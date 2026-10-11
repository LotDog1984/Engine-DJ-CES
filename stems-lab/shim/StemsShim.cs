// stems-processor.exe (custom slot) - the replacement stem separation engine.
//
// Engine DJ spawns this instead of its own processor. It speaks the same stdio protocol
// (recovered from a real job, see ../PROTOCOL.md) and answers with stems produced by the
// cascade engine in ../engine/engine_service.py:
//
//   vocals            <- vocals_mel_band_roformer
//   drums/bass/other  <- htdemucs_ft on the vocal-free residual
//
// If the engine is not installed at all, or STEMS_FORCE_DELEGATE=1 is set, it re-executes the
// preserved stock processor (stems-processor.vendor.exe) with the same arguments, so Engine DJ
// keeps working exactly as before. That decision has to be made before any input is consumed,
// because once the app has started streaming its audio there is nothing left to replay.
//
// An engine that is installed but not started yet is NOT a reason to fall back. The app streams
// the whole track before it wants anything back, and it streams at real time, so a cold engine
// service has minutes to come up: it is started in the background and waited for while the audio
// arrives. If it still never answers, the session is finished with silence and the reason is
// logged, because by then the stock processor can no longer take over.
//
// A finished job leaves nothing behind: once the app has been handed the stems, the rendered set
// under engine\cache and this job's input copy under engine\sessions are deleted. A job that dies
// keeps both - a retry is then cheap and the input can be looked at - and a later job sweeps
// leftovers by age: input copies after an hour, renders after six. STEMS_KEEP_CACHE=1 /
// STEMS_KEEP_SESSIONS=1 disable the corresponding deletions and sweeps for debugging.
//
// Protocol, as measured:
//   proc -> app   preparing=initialising\nsession=<token>\n\n
//   app  -> proc  version=...\nnumChannels=2\nsampleRate=44100\nmaxBlockSize=1024\n...\n
//   proc -> app   preparing=started\n\n
//   proc -> app   preparing=done\nnumReturnChannels=8\n\n
//   app  -> proc  action=block\nnumSamples=1024\n\n  + 1024 frames of float32 stereo, as PLANES
//   proc -> app   returnFrames=0\n\n                  (repeated while buffering)
//   app  -> proc  action=done\n\n                     (then the app closes stdin)
//   proc -> app   returnFrames=N\n\n + N frames of float32, 8 channels = four stereo stems, as PLANES
//   proc -> app   done=true\n\n
//
// Both directions are PLANAR: a message carries one plane per channel - all of channel 0 for
// the block, then all of channel 1 - not interleaved frames. Measured, not assumed:
//   * the app -> proc side, 2026-10-11: reassembling a captured mix.wav in 1024-frame planes
//     matches the source track at corr +1.0000 (lag 0, same low-band peak); reading the same
//     bytes as interleaved frames gives +0.05 and pitch one octave up, because every written
//     channel then holds every second sample of one plane, alternating with the other's plane.
//     See tests/planar-check.py. This one made every custom render sound pitched.
//   * the proc -> app side, 2026-10-09 stock capture: read as planes the four stems sum to the
//     mix at +0.998, read as interleaved frames at +0.002. See ../PROTOCOL.md.
// The app is built around zplane's bytes, so both sides are reproduced exactly.
//
// Rules it must never break:
//   * nothing is written to stdout except protocol messages - stdout carries the session.
//   * diagnostics go to stderr and to the log file only.
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

static class StemsShim
{
    const string VendorName = "stems-processor.vendor.exe";
    const int ReturnChannels = 8;                 // four stereo stems
    const int PreviewBytes = 192;
    const string DefaultLab = @"C:\Users\Branko\Desktop\EnginePrime\stems-lab";

    // The engine may come up at any point while the app streams the track, and gets a further
    // grace period once the audio is in before the session is finished with silence.
    const int EngineWatchSeconds = 900;
    const int EngineGraceSeconds = 600;

    // The shim keeps its own copy of each track's stream under engine\sessions so the engine has
    // a file to read. A copy is a whole track (tens of MB), so a successful job deletes its own
    // as soon as the app has received the stems; copies left by jobs that died are pruned by a
    // later job once they are older than SessionsMaxAgeMinutes. STEMS_KEEP_SESSIONS=1 keeps every
    // copy instead (debugging).
    const int SessionsMaxAgeMinutes = 60;

    // Renders under engine\cache are the same bargain with a longer fuse: a render is expensive
    // to recreate, and its entry must never be swept out from under a job that is still writing
    // it. A successful job deletes its own render immediately; an entry left behind by a job
    // that died is swept once nothing has written to it for this long. A cache hit counts as
    // activity - the service refreshes the entry's manifest when it serves one.
    const int RendersMaxAgeMinutes = 360;

    // Which stem sits in each stereo pair of the returned 8 channels. The app's own processor
    // sends vocals, bass, drums, other (measured on the stock capture: pair 1 is 99.7% below
    // 200 Hz, pair 2 carries the transients), so a bass stem in the drums slot would mute the
    // wrong thing in the app. Keep this order unless a capture says otherwise.
    static readonly string[] ChannelOrder = { "vocals", "bass", "drums", "other" };

    static FileStream logStream;
    static FileStream captureStream;
    static readonly object logGate = new object();
    static readonly object captureGate = new object();
    static readonly Stopwatch clock = Stopwatch.StartNew();
    static bool captureEnabled;
    static string dir;

    static void Log(string text)
    {
        Console.Error.WriteLine(text);
        try
        {
            byte[] b = Encoding.UTF8.GetBytes(text + Environment.NewLine);
            lock (logGate)
            {
                if (logStream == null) return;
                logStream.Write(b, 0, b.Length);
                logStream.Flush();
            }
        }
        catch { }
    }

    static string Lab()
    {
        string env = Environment.GetEnvironmentVariable("STEMS_LAB");
        if (!string.IsNullOrEmpty(env)) return env;
        string cfg = Path.Combine(dir, "engine.json");
        if (File.Exists(cfg))
        {
            try
            {
                Match m = Regex.Match(File.ReadAllText(cfg), "\"lab\"\\s*:\\s*\"([^\"]+)\"");
                if (m.Success) return m.Groups[1].Value.Replace("\\\\", "\\");
            }
            catch { }
        }
        return DefaultLab;
    }

    // ------------------------------------------------------------ pipe reader ---

    class MsgReader
    {
        readonly Stream s;
        readonly byte[] buf = new byte[1 << 16];
        int pos, len;

        public MsgReader(Stream stream) { s = stream; }

        int Fill()
        {
            len = s.Read(buf, 0, buf.Length);
            pos = 0;
            return len;
        }

        int Next()
        {
            if (pos >= len && Fill() <= 0) return -1;
            return buf[pos++];
        }

        /// Reads one message, which ends with a blank line (\n\n).
        public string ReadMessage()
        {
            var sb = new StringBuilder();
            bool prevNewline = false;
            while (true)
            {
                int c = Next();
                if (c < 0) return sb.Length > 0 ? sb.ToString() : null;
                sb.Append((char)c);
                if (c == '\n')
                {
                    if (prevNewline) return sb.ToString();
                    prevNewline = true;
                }
                else prevNewline = false;
            }
        }

        public byte[] ReadExact(int count)
        {
            byte[] data = new byte[count];
            int got = 0;
            while (got < count)
            {
                if (pos >= len && Fill() <= 0) throw new EndOfStreamException("pipe closed mid-block");
                int take = Math.Min(count - got, len - pos);
                Array.Copy(buf, pos, data, got, take);
                pos += take;
                got += take;
            }
            return data;
        }
    }

    static void Write(Stream s, byte[] data)
    {
        s.Write(data, 0, data.Length);
        s.Flush();
    }

    static void Write(Stream s, string text)
    {
        Write(s, Encoding.ASCII.GetBytes(text));
    }

    // ------------------------------------------------------------- engine link ---

    static string EnginePort()
    {
        string portFile = Path.Combine(Lab(), "engine", "engine.port");
        return File.Exists(portFile) ? File.ReadAllText(portFile).Trim() : null;
    }

    static bool EngineInstalled()
    {
        return File.Exists(Path.Combine(Lab(), ".venv", "Scripts", "python.exe"))
            && File.Exists(Path.Combine(Lab(), "engine", "engine_service.py"));
    }

    static bool StartEngineService(string reason)
    {
        string python = Path.Combine(Lab(), ".venv", "Scripts", "python.exe");
        string service = Path.Combine(Lab(), "engine", "engine_service.py");
        try
        {
            var psi = new ProcessStartInfo(python);
            psi.Arguments = "\"" + service + "\"";
            psi.UseShellExecute = false;
            psi.CreateNoWindow = true;
            psi.WorkingDirectory = Lab();
            psi.RedirectStandardOutput = true;
            psi.RedirectStandardError = true;
            Process proc = Process.Start(psi);
            DrainEngine(proc.StandardOutput.BaseStream, "engine stdout");
            DrainEngine(proc.StandardError.BaseStream, "engine stderr");
            Log("started the engine service (" + reason + ") pid " + proc.Id + ": " + service);
            return true;
        }
        catch (Exception e)
        {
            Log("could not start the engine service: " + e.Message);
            return false;
        }
    }

    /// A redirected pipe that nobody reads fills up and then blocks the writer, which for the
    /// engine means its next log line hangs a request. Keep reading, and keep the first few
    /// kilobytes in the shim log so engine-side tracebacks are not invisible.
    static void DrainEngine(Stream s, string label)
    {
        var t = new Thread(delegate ()
        {
            byte[] buf = new byte[4096];
            var head = new StringBuilder();
            long total = 0;
            try
            {
                while (true)
                {
                    int n = s.Read(buf, 0, buf.Length);
                    if (n <= 0) break;
                    total += n;
                    if (head.Length < 4096) head.Append(Encoding.UTF8.GetString(buf, 0, n));
                }
            }
            catch { }
            if (head.Length > 0)
                Log(label + " (first " + head.Length + " of " + total + " bytes): "
                    + head.ToString().Replace("\r", "\\r").Replace("\n", "\\n"));
            Log(label + " ended after " + total + " bytes");
        });
        t.IsBackground = true;
        t.Start();
    }

    static volatile bool engineReady;
    static volatile string engineWhy = "not probed";

    /// One readiness probe: the port file the service writes, then a ping over the socket.
    static bool TryEngineReady(out string detail)
    {
        string port = EnginePort();
        if (port == null) { detail = "no engine.port yet"; return false; }
        return Ping(port, out detail);
    }

    /// Brings the engine up in the background and records the outcome in engineReady/engineWhy.
    static Thread WatchEngine(int deadlineSeconds)
    {
        var t = new Thread(delegate ()
        {
            var sw = Stopwatch.StartNew();
            bool started = false;
            long lastLog = -10000;
            while (sw.Elapsed.TotalSeconds < deadlineSeconds && !engineReady)
            {
                string detail;
                if (TryEngineReady(out detail))
                {
                    engineReady = true;
                    engineWhy = "ready after " + (long)sw.Elapsed.TotalSeconds + "s";
                    Log("engine " + engineWhy);
                    break;
                }
                engineWhy = detail;
                if (!started)
                {
                    started = true;
                    StartEngineService(detail);
                }
                if (sw.ElapsedMilliseconds - lastLog > 10000)
                {
                    lastLog = sw.ElapsedMilliseconds;
                    Log("waiting for the engine: " + detail);
                }
                Thread.Sleep(500);
            }
            if (!engineReady) Log("engine never became ready within " + deadlineSeconds + "s: " + engineWhy);
        });
        t.IsBackground = true;
        t.Start();
        return t;
    }

    /// The service writes its JSON with json.dumps' default spacing, so "ok": true. Match the
    /// shape, never a literal string: the spacing is not part of the contract between the two
    /// processes, and matching it made a perfectly healthy engine look dead.
    static bool OkTrue(string reply)
    {
        return reply != null && Regex.IsMatch(reply, "\"ok\"\\s*:\\s*true");
    }

    static bool Ping(string port, out string detail)
    {
        try
        {
            using (var c = Connect(port))
            {
                string reply = Ask(c, "{\"cmd\":\"ping\"}");
                bool ok = OkTrue(reply);
                detail = ok ? "engine ready" : "engine ping failed: " + reply;
                return ok;
            }
        }
        catch (Exception e)
        {
            detail = "engine not reachable: " + e.Message;
            return false;
        }
    }

    static TcpClient Connect(string port)
    {
        var c = new TcpClient();
        c.Connect("127.0.0.1", int.Parse(port.Trim()));
        c.NoDelay = true;
        return c;
    }

    static string Ask(TcpClient c, string request)
    {
        c.ReceiveTimeout = 3600000;
        using (var ns = c.GetStream())
        {
            byte[] outb = Encoding.UTF8.GetBytes(request + "\n");
            ns.Write(outb, 0, outb.Length);
            ns.Flush();
            var sb = new StringBuilder();
            int b;
            while ((b = ns.ReadByte()) >= 0)
            {
                if (b == '\n') break;
                sb.Append((char)b);
            }
            return sb.ToString();
        }
    }

    static string JsonString(string json, string key)
    {
        if (json == null) return null;
        Match m = Regex.Match(json, "\"" + Regex.Escape(key) + "\"\\s*:\\s*\"((?:\\\\.|[^\"\\\\])*)\"");
        if (!m.Success) return null;
        return Regex.Unescape(m.Groups[1].Value);
    }

    // ------------------------------------------------------------------- wavs ---

    static void WriteWavFloat32(string path, float[] interleaved, int channels, int sampleRate)
    {
        using (var fs = new FileStream(path, FileMode.Create, FileAccess.Write))
        using (var w = new BinaryWriter(fs))
        {
            int dataBytes = interleaved.Length * 4;
            w.Write(Encoding.ASCII.GetBytes("RIFF"));
            w.Write(36 + dataBytes);
            w.Write(Encoding.ASCII.GetBytes("WAVE"));
            w.Write(Encoding.ASCII.GetBytes("fmt "));
            w.Write(16);
            w.Write((short)3);                       // IEEE float
            w.Write((short)channels);
            w.Write(sampleRate);
            w.Write(sampleRate * channels * 4);      // byte rate
            w.Write((short)(channels * 4));          // block align
            w.Write((short)32);                      // bits
            w.Write(Encoding.ASCII.GetBytes("data"));
            w.Write(dataBytes);
            byte[] raw = new byte[dataBytes];
            Buffer.BlockCopy(interleaved, 0, raw, 0, dataBytes);
            w.Write(raw);
        }
    }

    // Streamed rather than buffered: a stem is tens of megabytes and there are four of them.
    // The header is read with exact reads off the FileStream so its Position stays truthful
    // (a buffered BinaryReader would read ahead and desynchronise the seeks).
    class WavReader : IDisposable
    {
        public int Channels, SampleRate, Bits;
        public long DataOffset, DataLength;
        readonly FileStream fs;

        static byte[] Take(Stream s, int count)
        {
            byte[] b = new byte[count];
            int got = 0;
            while (got < count)
            {
                int n = s.Read(b, got, count - got);
                if (n <= 0) throw new EndOfStreamException("unexpected end of wav header");
                got += n;
            }
            return b;
        }

        static string Tag(Stream s) { return Encoding.ASCII.GetString(Take(s, 4)); }
        static int I32(Stream s) { return BitConverter.ToInt32(Take(s, 4), 0); }
        static short I16(Stream s) { return BitConverter.ToInt16(Take(s, 2), 0); }

        public WavReader(string path)
        {
            fs = new FileStream(path, FileMode.Open, FileAccess.Read);
            if (Tag(fs) != "RIFF") throw new InvalidDataException("not a RIFF file: " + path);
            I32(fs);
            if (Tag(fs) != "WAVE") throw new InvalidDataException("not a WAVE file: " + path);
            while (fs.Position + 8 <= fs.Length)
            {
                string id = Tag(fs);
                int size = I32(fs);
                long body = fs.Position;
                if (size < 0 || body + size > fs.Length) break;
                if (id == "fmt ")
                {
                    short format = I16(fs);
                    Channels = I16(fs);
                    SampleRate = I32(fs);
                    I32(fs);
                    I16(fs);
                    Bits = I16(fs);
                    if (format != 3) throw new InvalidDataException("expected a 32-bit float wav, format=" + format);
                }
                else if (id == "data")
                {
                    DataOffset = body;
                    DataLength = size;
                    break;
                }
                fs.Seek(body + size + (size % 2), SeekOrigin.Begin);
            }
            if (DataOffset == 0) throw new InvalidDataException("no data chunk in " + path);
        }

        public int Frames { get { return (int)(DataLength / (Channels * (Bits / 8))); } }

        public int ReadFrames(int startFrame, int count, float[] dest)
        {
            int frameBytes = Channels * (Bits / 8);
            int want = Math.Min(count, Frames - startFrame);
            if (want <= 0) return 0;
            fs.Seek(DataOffset + (long)startFrame * frameBytes, SeekOrigin.Begin);
            byte[] raw = new byte[want * frameBytes];
            int got = 0;
            while (got < raw.Length)
            {
                int n = fs.Read(raw, got, raw.Length - got);
                if (n <= 0) break;
                got += n;
            }
            Buffer.BlockCopy(raw, 0, dest, 0, got - (got % 4));
            return want;
        }

        public void Dispose() { try { fs.Dispose(); } catch { } }
    }

    // -------------------------------------------------------------- the session ---

    static bool EnvFlag(string name)
    {
        string env = Environment.GetEnvironmentVariable(name);
        int n;
        return !string.IsNullOrEmpty(env) && int.TryParse(env.Trim(), out n) && n >= 1;
    }

    static long DirSize(string dir)
    {
        long total = 0;
        try
        {
            if (!Directory.Exists(dir)) return 0;
            foreach (string f in Directory.GetFiles(dir, "*", SearchOption.AllDirectories))
            {
                try { total += new FileInfo(f).Length; } catch { }
            }
        }
        catch { }
        return total;
    }

    /// <summary>
    /// Deletes what a successful job no longer needs: the rendered stem set it produced (the app
    /// has the stems now) and this job's input copy. A job that failed runs neither deletion: the
    /// rendered set makes a retry cheap and the input stays for inspection.
    /// STEMS_KEEP_CACHE=1 / STEMS_KEEP_SESSIONS=1 keep each for debugging.
    /// </summary>
    static void CleanupAfterSuccess(string lab, string stamp, Dictionary<string, string> paths)
    {
        if (!EnvFlag("STEMS_KEEP_SESSIONS"))
        {
            try
            {
                string work = Path.Combine(lab, "engine", "sessions", stamp);
                long freed = DirSize(work);
                if (Directory.Exists(work)) Directory.Delete(work, true);
                if (freed > 0) Log(string.Format("cleanup: input copy removed, {0:0.0} MB reclaimed", freed / 1048576.0));
            }
            catch (Exception e) { Log("cleanup: input copy left in place: " + e.Message); }
        }

        if (!EnvFlag("STEMS_KEEP_CACHE"))
        {
            string cacheRoot = Path.Combine(lab, "engine", "cache");
            var dirs = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var kv in paths)
            {
                string d = Path.GetDirectoryName(kv.Value);
                // Only ever delete direct children of the lab's own cache directory.
                if (!string.IsNullOrEmpty(d)
                    && string.Equals(Path.GetDirectoryName(d), cacheRoot, StringComparison.OrdinalIgnoreCase))
                    dirs.Add(d);
            }
            foreach (string d in dirs)
            {
                try
                {
                    long freed = DirSize(d);
                    Directory.Delete(d, true);
                    Log(string.Format("cleanup: rendered stems removed, {0:0.0} MB reclaimed", freed / 1048576.0));
                }
                catch (Exception e) { Log("cleanup: rendered stems left in place: " + e.Message); }
            }
        }
    }

    /// <summary>
    /// Removes session input copies left by jobs that died before finishing (a successful job
    /// deletes its own). Age, not count: a copy another shim process is still using must never be
    /// touched, and a batch runs several shim processes at once.
    /// </summary>
    static void PruneSessions(string lab)
    {
        if (EnvFlag("STEMS_KEEP_SESSIONS")) return;
        try
        {
            string root = Path.Combine(lab, "engine", "sessions");
            if (!Directory.Exists(root)) return;
            DateTime cutoff = DateTime.UtcNow.AddMinutes(-SessionsMaxAgeMinutes);
            long freed = 0;
            int removed = 0;
            foreach (string d in Directory.GetDirectories(root))
            {
                try
                {
                    if (Directory.GetLastWriteTimeUtc(d) > cutoff) continue;
                    freed += DirSize(d);
                    Directory.Delete(d, true);
                    removed++;
                }
                catch { }
            }
            if (removed > 0)
                Log(string.Format("pruned {0} stale session input(s) (older than {1} min), {2:0.0} MB reclaimed",
                    removed, SessionsMaxAgeMinutes, freed / 1048576.0));
        }
        catch (Exception e) { Log("session prune skipped: " + e.Message); }
    }

    /// <summary>
    /// Sweeps renders no job is coming back for: an entry whose job died before the app received
    /// its stems. A successful job deletes its own render, so what is left here is only ever
    /// abandoned material. Age decides, not count, and only when nothing in the entry has been
    /// written for RendersMaxAgeMinutes - a job that is still rendering touches its own entry
    /// continuously, and a cache hit refreshes the manifest, so no live entry can qualify.
    /// STEMS_KEEP_CACHE=1 skips this too (debugging).
    /// </summary>
    static void PruneStaleRenders(string lab)
    {
        if (EnvFlag("STEMS_KEEP_CACHE")) return;
        try
        {
            string root = Path.Combine(lab, "engine", "cache");
            if (!Directory.Exists(root)) return;
            DateTime cutoff = DateTime.UtcNow.AddMinutes(-RendersMaxAgeMinutes);
            long freed = 0;
            int removed = 0;
            foreach (string d in Directory.GetDirectories(root))
            {
                try
                {
                    if (NewestWrite(d) > cutoff) continue;
                    freed += DirSize(d);
                    Directory.Delete(d, true);
                    removed++;
                }
                catch { }
            }
            if (removed > 0)
                Log(string.Format("pruned {0} stale render(s) (older than {1} min), {2:0.0} MB reclaimed",
                    removed, RendersMaxAgeMinutes, freed / 1048576.0));
        }
        catch (Exception e) { Log("render prune skipped: " + e.Message); }
    }

    /// <summary>The newest last-write time anywhere in a tree: "has anything touched this lately".</summary>
    static DateTime NewestWrite(string dir)
    {
        DateTime newest = Directory.GetLastWriteTimeUtc(dir);
        foreach (string f in Directory.GetFiles(dir, "*", SearchOption.AllDirectories))
        {
            try
            {
                DateTime t = File.GetLastWriteTimeUtc(f);
                if (t > newest) newest = t;
            }
            catch { }
        }
        return newest;
    }

    /// <summary>
    /// Keeps the newest few shim logs; one is written per job, in the shim's own directory, and
    /// they would otherwise pile up there forever. The current run's log is never touched.
    /// </summary>
    static void PruneLogs()
    {
        try
        {
            var files = new List<string>(Directory.GetFiles(dir, "stems-shim-*.log"));
            files.Sort(StringComparer.Ordinal);           // yyyyMMdd-HHmmss-fff names sort chronologically
            for (int i = 0; i < files.Count - 5; i++)
            {
                try { File.Delete(files[i]); } catch { }
            }
        }
        catch { }
    }

    static int RunEngineSession(MsgReader stdin, Stream stdout, string lab, string stamp, Thread watch)
    {
        string token = "FFF" + Guid.NewGuid().ToString("N").Substring(0, 13).ToUpperInvariant();
        Write(stdout, "preparing=initialising\nsession=" + token + "\n\n");

        string settings = stdin.ReadMessage();
        if (settings == null) { Log("session ended before the settings arrived"); return 1; }

        int numChannels = 2, sampleRate = 44100, maxBlockSize = 1024;
        foreach (string line in settings.Split('\n'))
        {
            int eq = line.IndexOf('=');
            if (eq <= 0) continue;
            string k = line.Substring(0, eq).Trim();
            string v = line.Substring(eq + 1).Trim();
            if (k == "numChannels") numChannels = int.Parse(v);
            else if (k == "sampleRate") sampleRate = int.Parse(v);
            else if (k == "maxBlockSize") maxBlockSize = int.Parse(v);
        }
        Log(string.Format("session {0}: {1} channels @ {2} Hz, block {3}", token, numChannels, sampleRate, maxBlockSize));
        if (numChannels != 2) Log("warning: unexpected channel count " + numChannels);

        Write(stdout, "preparing=started\n\n");
        Write(stdout, "preparing=done\nnumReturnChannels=" + ReturnChannels + "\n\n");

        // --- collect the mix
        var mix = new List<float>(sampleRate * numChannels * 60);
        int blocks = 0;
        while (true)
        {
            string msg = stdin.ReadMessage();
            if (msg == null) { Log("pipe closed before action=done"); break; }
            if (msg.StartsWith("action=block"))
            {
                int frames = 0;
                foreach (string line in msg.Split('\n'))
                {
                    int eq = line.IndexOf('=');
                    if (eq > 0 && line.Substring(0, eq).Trim() == "numSamples")
                        frames = int.Parse(line.Substring(eq + 1).Trim());
                }
                byte[] payload = stdin.ReadExact(frames * numChannels * 4);
                float[] planes = new float[frames * numChannels];
                Buffer.BlockCopy(payload, 0, planes, 0, payload.Length);
                // The app sends channel planes (all of channel 0 for the block, then channel 1).
                // Appending them as interleaved frames is what made every render sound pitched:
                // each written channel then holds every second sample of one plane, alternating
                // with the other's, which is an octave up with the timeline intact. The engine
                // wants an interleaved wav, so de-planarise as the blocks arrive.
                float[] f = new float[frames * numChannels];
                if (numChannels == 1)
                {
                    Array.Copy(planes, f, frames);
                }
                else
                {
                    for (int ch = 0; ch < numChannels; ch++)
                    {
                        int baseIn = ch * frames;
                        for (int i = 0; i < frames; i++)
                            f[i * numChannels + ch] = planes[baseIn + i];
                    }
                }
                mix.AddRange(f);
                blocks++;
                Write(stdout, "returnFrames=0\n\n");
                continue;
            }
            if (msg.StartsWith("action=done"))
            {
                Log(string.Format("input complete: {0} blocks, {1} frames", blocks, mix.Count / numChannels));
                break;
            }
            Log("unexpected message: " + msg.Replace("\n", "\\n"));
            Write(stdout, "returnFrames=0\n\n");
        }

        int totalFrames = mix.Count / numChannels;
        if (totalFrames == 0) { Write(stdout, "done=true\n\n"); return 0; }

        // --- run the engine (it has had the whole stream to come up)
        if (!engineReady)
        {
            Log("audio complete, engine not ready yet (" + engineWhy + "); waiting up to "
                + EngineGraceSeconds + "s");
            if (watch != null) watch.Join(TimeSpan.FromSeconds(EngineGraceSeconds));
        }
        if (!engineReady)
        {
            Log("FATAL engine unavailable: " + engineWhy);
            Log("returning silence so the app still completes; the job can be re-run once the engine answers");
            EmitSilence(stdout, totalFrames, maxBlockSize);
            return 3;
        }

        string work = Path.Combine(lab, "engine", "sessions", stamp);
        Directory.CreateDirectory(work);
        string mixPath = Path.Combine(work, "mix.wav");
        WriteWavFloat32(mixPath, mix.ToArray(), numChannels, sampleRate);
        mix = null;

        string request = "{\"cmd\":\"separate\",\"path\":" + JsonEscape(mixPath) + "}";
        string reply;
        try
        {
            using (var c = Connect(EnginePort()))
            {
                reply = Ask(c, request);
            }
        }
        catch (Exception e)
        {
            Log("FATAL engine call failed: " + e.Message);
            Log("returning silence so the app still completes; check the engine log");
            EmitSilence(stdout, totalFrames, maxBlockSize);
            return 3;
        }
        if (!OkTrue(reply))
        {
            Log("FATAL engine refused: " + reply);
            EmitSilence(stdout, totalFrames, maxBlockSize);
            return 3;
        }

        var paths = new Dictionary<string, string>();
        foreach (string stem in ChannelOrder) paths[stem] = JsonString(reply, stem);
        foreach (var kv in paths)
            if (kv.Value == null) { Log("FATAL engine reply is missing stem " + kv.Key); EmitSilence(stdout, totalFrames, maxBlockSize); return 3; }
        Log("engine produced stems: " + string.Join(", ", new List<string>(paths.Keys).ToArray()));

        // --- stream the four stems back as 8 interleaved channels
        var readers = new Dictionary<string, WavReader>();
        try
        {
            foreach (var kv in paths) readers[kv.Key] = new WavReader(kv.Value);
            int produced = readers[ChannelOrder[0]].Frames;
            if (produced != totalFrames)
                Log(string.Format("note: engine returned {0} frames for {1} input frames", produced, totalFrames));

            int frames = Math.Min(produced, totalFrames);
            int pos = 0;
            float[] outbuf = new float[maxBlockSize * ReturnChannels];
            float[] tmp = new float[maxBlockSize * 2];
            while (pos < frames)
            {
                int n = Math.Min(maxBlockSize, frames - pos);
                for (int si = 0; si < ChannelOrder.Length; si++)
                {
                    int r = readers[ChannelOrder[si]].ReadFrames(pos, n, tmp);
                    // Planes, not frames: plane 2*si is this pair's left channel for all n frames,
                    // plane 2*si+1 its right. The message's payload is n frames per plane, so the
                    // stride is n and outbuf is exactly filled @ n * ReturnChannels floats.
                    int left = (si * 2) * n;
                    int right = (si * 2 + 1) * n;
                    for (int i = 0; i < r; i++)
                    {
                        outbuf[left + i] = tmp[i * 2 + 0];
                        outbuf[right + i] = tmp[i * 2 + 1];
                    }
                }
                Write(stdout, "returnFrames=" + n + "\n\n");
                byte[] raw = new byte[n * ReturnChannels * 4];
                Buffer.BlockCopy(outbuf, 0, raw, 0, raw.Length);
                Write(stdout, raw);
                pos += n;
            }
        }
        finally
        {
            foreach (var r in readers.Values) r.Dispose();
        }

        Write(stdout, "done=true\n\n");
        CleanupAfterSuccess(lab, stamp, paths);
        Log(string.Format("session {0} finished: {1} frames of {2} stems returned", token, totalFrames, ChannelOrder.Length));
        return 0;
    }

    static void EmitSilence(Stream stdout, int totalFrames, int maxBlockSize)
    {
        int pos = 0;
        byte[] silence = new byte[maxBlockSize * ReturnChannels * 4];
        while (pos < totalFrames)
        {
            int n = Math.Min(maxBlockSize, totalFrames - pos);
            Write(stdout, "returnFrames=" + n + "\n\n");
            Write(stdout, n == maxBlockSize ? silence : new byte[n * ReturnChannels * 4]);
            pos += n;
        }
        Write(stdout, "done=true\n\n");
    }

    static string JsonEscape(string s)
    {
        return "\"" + s.Replace("\\", "\\\\").Replace("\"", "\\\"") + "\"";
    }

    // ------------------------------------------------------------- delegation ---

    static string Quote(string a)
    {
        if (a.Length > 0 && a.IndexOf(' ') < 0 && a.IndexOf('"') < 0) return a;
        return "\"" + a.Replace("\\", "\\\\").Replace("\"", "\\\"") + "\"";
    }

    static string Preview(byte[] buf, int offset, int count)
    {
        var hex = new StringBuilder();
        var ascii = new StringBuilder();
        int shown = Math.Min(count, PreviewBytes);
        for (int i = 0; i < shown; i++)
        {
            byte v = buf[offset + i];
            hex.Append(v.ToString("x2"));
            if (i % 2 == 1) hex.Append(' ');
            ascii.Append(v >= 0x20 && v < 0x7f ? (char)v : '.');
        }
        if (count > shown) hex.Append("... (").Append(count - shown).Append(" more bytes)");
        return "hex=" + hex + "\r\n     ascii=" + ascii;
    }

    static void Capture(string dirLabel, byte[] buf, int offset, int count, long offsetBytes)
    {
        if (!captureEnabled || captureStream == null) return;
        try
        {
            var sb = new StringBuilder();
            sb.AppendFormat("[{0}] t=+{1}ms start={2} len={3}\r\n     {4}\r\n",
                dirLabel, clock.ElapsedMilliseconds, offsetBytes, count, Preview(buf, offset, count));
            byte[] b = Encoding.UTF8.GetBytes(sb.ToString());
            lock (captureGate) { captureStream.Write(b, 0, b.Length); captureStream.Flush(); }
        }
        catch { }
    }

    static void Pump(Stream from, Stream to, string dirLabel, bool closeTo)
    {
        byte[] buf = new byte[65536];
        long total = 0;
        try
        {
            while (true)
            {
                int n = from.Read(buf, 0, buf.Length);
                if (n <= 0) break;
                Capture(dirLabel, buf, 0, n, total);
                to.Write(buf, 0, n);
                to.Flush();
                total += n;
            }
        }
        catch (Exception e) { Log(string.Format("[{0}] exception after {1} bytes: {2}", dirLabel, total, e.Message)); }
        Log(string.Format("[{0}] closed after {1} bytes", dirLabel, total));
        if (closeTo) { try { to.Close(); } catch { } }
    }

    static int Delegate(string[] args, string vendor)
    {
        Log("delegating to the stock processor: " + vendor);
        var psi = new ProcessStartInfo(vendor);
        var sb = new StringBuilder();
        foreach (string a in args) sb.Append(Quote(a)).Append(' ');
        psi.Arguments = sb.ToString();
        psi.UseShellExecute = false;
        psi.RedirectStandardInput = true;
        psi.RedirectStandardOutput = true;
        psi.RedirectStandardError = true;
        psi.WorkingDirectory = dir;

        Process child;
        try { child = Process.Start(psi); }
        catch (Exception e)
        {
            Console.Error.WriteLine("stems shim: failed to start the stock processor: " + e.Message);
            Log("FATAL failed to start vendor: " + e.Message);
            return 127;
        }

        var tOut = new Thread(delegate () { Pump(child.StandardOutput.BaseStream, Console.OpenStandardOutput(), "host<-proc", false); });
        var tErr = new Thread(delegate () { Pump(child.StandardError.BaseStream, Console.OpenStandardError(), "ERR", false); });
        var tIn = new Thread(delegate () { Pump(Console.OpenStandardInput(), child.StandardInput.BaseStream, "host->proc", true); });
        tOut.IsBackground = true; tErr.IsBackground = true; tIn.IsBackground = true;
        tOut.Start(); tErr.Start(); tIn.Start();
        child.WaitForExit();
        Thread.Sleep(300);
        Log("stock processor exit code " + child.ExitCode);
        return child.ExitCode;
    }

    // ------------------------------------------------------------------ start ---

    static int Main(string[] args)
    {
        dir = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
        // The stamp names this process's log file AND its engine\sessions directory, so it must be
        // unique per process. Engine DJ starts one processor per track in a batch, in the same
        // millisecond: with a bare millisecond stamp, a real 3-track batch on 2026-10-11 14:45 had
        // three processes sharing one mix.wav, and the engine loaded that path as 143.1 s, 0.0 s
        // and 205.1 s - the 0.0 s job died on a half-written file and the app was handed silence.
        string stamp = DateTime.Now.ToString("yyyyMMdd-HHmmss-fff") + "-" + Process.GetCurrentProcess().Id;

        string envLog = Environment.GetEnvironmentVariable("STEMS_SHIM_LOG");
        string logPath = !string.IsNullOrEmpty(envLog) ? envLog : Path.Combine(dir, "stems-shim-" + stamp + ".log");
        try { logStream = new FileStream(logPath, FileMode.Append, FileAccess.Write, FileShare.ReadWrite); } catch { }

        captureEnabled = File.Exists(Path.Combine(dir, "capture.on"))
            || Environment.GetEnvironmentVariable("STEMS_CAPTURE") == "1";
        if (captureEnabled)
        {
            string envCapture = Environment.GetEnvironmentVariable("STEMS_CAPTURE_LOG");
            string capPath = !string.IsNullOrEmpty(envCapture) ? envCapture : Path.Combine(dir, "stems-capture-" + stamp + ".log");
            try
            {
                captureStream = new FileStream(capPath, FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                Log("capture enabled -> " + capPath);
            }
            catch (Exception e) { captureEnabled = false; Log("capture requested but the log could not be opened: " + e.Message); }
        }

        string vendor = Path.Combine(dir, VendorName);
        Log(string.Format("=== shim start {0} args=[{1}] vendor={2} capture={3} mode={4}",
            DateTime.Now.ToString("s"), string.Join(" ", args), vendor, captureEnabled,
            Environment.GetEnvironmentVariable("STEMS_FORCE_DELEGATE") == "1" ? "forced-delegate" : "auto"));

        bool forceDelegate = Environment.GetEnvironmentVariable("STEMS_FORCE_DELEGATE") == "1";
        bool useEngine = !forceDelegate && EngineInstalled();
        string why = forceDelegate ? "forced by STEMS_FORCE_DELEGATE"
            : useEngine ? "engine installed at " + Lab() : "engine not installed at " + Lab();
        Log(useEngine ? "custom mode: " + why : "delegating: " + why);

        if (!useEngine)
        {
            if (!File.Exists(vendor))
            {
                string msg = "stems shim: neither the engine nor the stock processor is available (" + why
                    + "); looked for " + vendor;
                Console.Error.WriteLine(msg);
                Log("FATAL " + msg);
                return 2;
            }
            return Delegate(args, vendor);
        }

        try
        {
            var reader = new MsgReader(Console.OpenStandardInput());
            Stream stdout = Console.OpenStandardOutput();
            Thread watch = WatchEngine(EngineWatchSeconds);
            int code = RunEngineSession(reader, stdout, Lab(), stamp, watch);
            Log("session return code " + code);
            return code;
        }
        catch (Exception e)
        {
            // The input has already been consumed by now, so the stock processor cannot take
            // over; finish the session cleanly rather than leaving the app hanging.
            Log("FATAL session error: " + e);
            return 4;
        }
        finally
        {
            Thread.Sleep(200);
            if (useEngine) { PruneSessions(Lab()); PruneStaleRenders(Lab()); }
            PruneLogs();
            if (captureStream != null) { try { captureStream.Flush(); captureStream.Close(); } catch { } }
            if (logStream != null) { try { logStream.Flush(); } catch { } }
        }
    }
}
