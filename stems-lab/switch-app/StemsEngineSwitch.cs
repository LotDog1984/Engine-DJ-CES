// StemsEngineSwitch - a small window that flips Engine DJ between its own stems
// processor and the custom one, so nothing has to be typed into a terminal.
//
// It is a front end for stems-lab\engine-switch.ps1, which is the tested piece:
// every button click runs that script and shows its output verbatim. The script
// does the renaming, the hashing and the rollback; this window only chooses the
// mode and reports what happened.
//
//   --selftest <outfile>   run headless, write a report, exit 0/1 (used by tests)
//   --setup [logfile]      run the first-run install headless (see "Set up Custom Engine")
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

static class Program
{
    [STAThread]
    static int Main(string[] args)
    {
        if (args.Length >= 2 && args[0] == "--selftest")
            return SelfTest(args[1]);

        // the same first-run install the button runs, without a window, so a fresh clone
        // can be prepared from a script (and so tests can exercise the real path).
        if (args.Length >= 1 && args[0] == "--setup")
        {
            string report = MainForm.SetupCustomEngine();
            Console.WriteLine(report);
            // a GUI-subsystem exe owns no console, so also write the log when a file is named
            if (args.Length >= 2) File.WriteAllText(args[1], report);
            return report.ToUpperInvariant().Contains("SETUP FAILED") ? 1 : 0;
        }

        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        Application.Run(new MainForm());
        return 0;
    }

    // ---------------------------------------------------------------- script --

    // The exe lives in <lab>\switch-app\, so the lab root is exactly one level up. The script
    // runner and the first-run setup both need it, so it is resolved in one place.
    internal static string LabRoot()
    {
        string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
        return Path.GetFullPath(Path.Combine(appDir, ".."));
    }

    internal static string ScriptPath()
    {
        return Path.Combine(LabRoot(), "engine-switch.ps1");
    }

    internal class ScriptResult
    {
        public string Output;
        public int ExitCode;
    }

    internal static ScriptResult RunScript(string mode, bool liveTarget, bool force, bool json)
    {
        var result = new ScriptResult();
        string script = ScriptPath();
        if (!File.Exists(script))
        {
            result.ExitCode = 1;
            result.Output = "engine-switch.ps1 not found at " + script;
            return result;
        }

        var psi = new ProcessStartInfo("powershell.exe");
        var a = new StringBuilder();
        a.Append("-NoProfile -ExecutionPolicy Bypass -File \"").Append(script).Append("\"");
        a.Append(" -Engine ").Append(mode);
        a.Append(" -Target ").Append(liveTarget ? "live" : "project");
        if (force) a.Append(" -Force");
        if (json) a.Append(" -Json");
        psi.Arguments = a.ToString();
        psi.UseShellExecute = false;
        psi.CreateNoWindow = true;
        psi.RedirectStandardOutput = true;
        psi.RedirectStandardError = true;

        try
        {
            using (var p = Process.Start(psi))
            {
                Task<string> outTask = p.StandardOutput.ReadToEndAsync();
                Task<string> errTask = p.StandardError.ReadToEndAsync();
                p.WaitForExit();
                string output = outTask.Result;
                string err = errTask.Result;
                result.ExitCode = p.ExitCode;
                if (!string.IsNullOrEmpty(err)) output = output + Environment.NewLine + err;
                result.Output = output;
                return result;
            }
        }
        catch (Exception e)
        {
            result.ExitCode = 1;
            result.Output = "could not run PowerShell: " + e.Message;
            return result;
        }
    }

    // Turning a button into a script mode. The one twist: on a brand new setup there
    // is no recorded baseline, and the switch deliberately refuses to guess which file
    // is the original. So the first click on "ORIGINAL" records the baseline instead.
    internal static string ResolveMode(string requested, string engine)
    {
        if (requested == "vendor" && engine == "unknown") return "adopt";
        return requested;
    }

    // Minimal reader for the flat JSON that -Status -Json emits. We produce that
    // JSON ourselves, so a regex is enough and avoids extra dependencies.
    internal static string JsonString(string json, string key)
    {
        if (json == null) return null;
        var m = Regex.Match(json, "\"" + Regex.Escape(key) + "\"\\s*:\\s*\"((?:\\\\.|[^\"\\\\])*)\"");
        return m.Success ? Regex.Unescape(m.Groups[1].Value) : null;
    }

    internal static string JsonRaw(string json, string key)
    {
        if (json == null) return null;
        var m = Regex.Match(json, "\"" + Regex.Escape(key) + "\"\\s*:\\s*(\\[[^\\]]*\\]|null|[^,}\\s]+)");
        return m.Success ? m.Groups[1].Value : null;
    }

    // ------------------------------------------------------------- selftest --

    static int SelfTest(string reportPath)
    {
        var sb = new StringBuilder();
        int failures = 0;

        Action<string, bool, string> check = delegate (string name, bool ok, string detail)
        {
            if (!ok) failures++;
            sb.AppendLine((ok ? "PASS  " : "FAIL  ") + name + (string.IsNullOrEmpty(detail) ? "" : "   [" + detail + "]"));
        };

        string script = ScriptPath();
        check("engine-switch.ps1 resolves next to the app", File.Exists(script), script);

        ScriptResult r = RunScript("status", true, false, true);
        string json = r.Output;
        check("status -Json exits 0", r.ExitCode == 0, "exit=" + r.ExitCode + " " + json);

        string engine = JsonString(json, "engine");
        string bin = JsonString(json, "bin");
        string baseline = JsonString(json, "baselineHash");
        string active = JsonString(json, "activeHash");
        string liveBin = JsonString(json, "liveBin");
        string appRunning = JsonRaw(json, "appRunning");

        check("json parses and reports an engine", engine != null && engine.Length > 0, "engine=" + engine);
        check("json reports the live bin directory", bin != null && liveBin != null && bin == liveBin, "bin=" + bin);
        check("json reports the active processor hash", active != null && active.Length == 32, "active=" + active);
        check("json reports appRunning as an array", appRunning != null && appRunning.StartsWith("["), "appRunning=" + appRunning);
        sb.AppendLine("engine=" + engine + " baseline=" + (baseline ?? "(none)") + " active=" + active);
        sb.AppendLine("appRunning=" + appRunning);

        ScriptResult r2 = RunScript("status", false, false, false);
        string human = r2.Output;
        check("human status exits 0 for the project copy", r2.ExitCode == 0, "exit=" + r2.ExitCode);
        check("human status names the engine", human != null && human.Contains("engine:"), human);

        check("first click on ORIGINAL records the baseline", ResolveMode("vendor", "unknown") == "adopt", ResolveMode("vendor", "unknown"));
        check("ORIGINAL restores once a baseline exists", ResolveMode("vendor", "vendor") == "vendor", ResolveMode("vendor", "vendor"));
        check("CUSTOM is passed straight through", ResolveMode("custom", "vendor") == "custom", ResolveMode("custom", "vendor"));

        sb.AppendLine();
        sb.AppendLine(failures == 0 ? "ALL CHECKS PASSED" : failures + " CHECK(S) FAILED");
        File.WriteAllText(reportPath, sb.ToString());
        return failures == 0 ? 0 : 1;
    }
}

class MainForm : Form
{
    Label lblEngine;
    Label lblDetail;
    Button btnOriginal;
    Button btnCustom;
    Label lblOriginalHint;
    Label lblCustomHint;
    ComboBox cmbTarget;
    CheckBox chkForce;
    Button btnRefresh;
    Button btnSetup;
    TextBox txtLog;
    StatusStrip strip;
    ToolStripStatusLabel stripLabel;
    bool busy;
    string currentEngine = "unknown";

    public MainForm()
    {
        Text = "Stems Engine Switch";
        ClientSize = new Size(700, 560);
        MinimumSize = new Size(700, 520);
        StartPosition = FormStartPosition.CenterScreen;
        Font = new Font("Segoe UI", 9F);
        BackColor = Color.FromArgb(250, 250, 252);

        // ---- header
        var header = new Panel();
        header.Dock = DockStyle.Top;
        header.Height = 108;
        header.Padding = new Padding(16, 12, 16, 8);
        header.BackColor = Color.White;

        var lblCaption = new Label();
        lblCaption.Text = "Stems engine in use";
        lblCaption.ForeColor = Color.FromArgb(110, 110, 120);
        lblCaption.Dock = DockStyle.Top;
        lblCaption.Height = 20;

        lblEngine = new Label();
        lblEngine.Text = "reading...";
        lblEngine.Font = new Font("Segoe UI", 17F, FontStyle.Bold);
        lblEngine.Dock = DockStyle.Top;
        lblEngine.Height = 38;

        lblDetail = new Label();
        lblDetail.Text = "";
        lblDetail.ForeColor = Color.FromArgb(90, 90, 100);
        lblDetail.Dock = DockStyle.Fill;

        header.Controls.Add(lblDetail);
        header.Controls.Add(lblEngine);
        header.Controls.Add(lblCaption);

        // ---- buttons
        var buttons = new Panel();
        buttons.Dock = DockStyle.Top;
        buttons.Height = 132;
        buttons.Padding = new Padding(16, 10, 16, 8);

        btnOriginal = new Button();
        btnOriginal.Text = "Use ORIGINAL stems";
        btnOriginal.Font = new Font("Segoe UI", 11F, FontStyle.Bold);
        btnOriginal.Size = new Size(316, 62);
        btnOriginal.Location = new Point(16, 10);
        btnOriginal.FlatStyle = FlatStyle.Flat;
        btnOriginal.BackColor = Color.FromArgb(225, 234, 245);
        btnOriginal.Click += delegate { Go("vendor"); };

        btnCustom = new Button();
        btnCustom.Text = "Use CUSTOM stems";
        btnCustom.Font = new Font("Segoe UI", 11F, FontStyle.Bold);
        btnCustom.Size = new Size(316, 62);
        btnCustom.Location = new Point(346, 10);
        btnCustom.FlatStyle = FlatStyle.Flat;
        btnCustom.BackColor = Color.FromArgb(224, 241, 224);
        btnCustom.Click += delegate { Go("custom"); };

        lblOriginalHint = new Label();
        lblOriginalHint.Text = "Engine DJ's own processor";
        lblOriginalHint.ForeColor = Color.FromArgb(110, 110, 120);
        lblOriginalHint.Location = new Point(18, 76);
        lblOriginalHint.Size = new Size(300, 20);

        lblCustomHint = new Label();
        lblCustomHint.Text = "Your replacement engine";
        lblCustomHint.ForeColor = Color.FromArgb(110, 110, 120);
        lblCustomHint.Location = new Point(348, 76);
        lblCustomHint.Size = new Size(300, 20);

        buttons.Controls.Add(btnOriginal);
        buttons.Controls.Add(btnCustom);
        buttons.Controls.Add(lblOriginalHint);
        buttons.Controls.Add(lblCustomHint);

        // ---- options
        var options = new Panel();
        options.Dock = DockStyle.Top;
        options.Height = 48;
        options.Padding = new Padding(16, 6, 16, 6);
        options.BackColor = Color.White;

        var lblTarget = new Label();
        lblTarget.Text = "Apply to:";
        lblTarget.Location = new Point(16, 14);
        lblTarget.Size = new Size(62, 20);

        cmbTarget = new ComboBox();
        cmbTarget.DropDownStyle = ComboBoxStyle.DropDownList;
        cmbTarget.Location = new Point(82, 11);
        cmbTarget.Size = new Size(250, 24);
        cmbTarget.Items.Add("Engine DJ (live install)");
        cmbTarget.Items.Add("Project copy (practice only)");
        cmbTarget.SelectedIndex = 0;

        chkForce = new CheckBox();
        chkForce.Text = "Force (use if Engine DJ stays open)";
        chkForce.Location = new Point(348, 12);
        chkForce.Size = new Size(240, 22);

        btnRefresh = new Button();
        btnRefresh.Text = "Refresh";
        btnRefresh.Location = new Point(596, 10);
        btnRefresh.Size = new Size(80, 26);
        btnRefresh.Click += delegate { RefreshState(false); };

        options.Controls.Add(lblTarget);
        options.Controls.Add(cmbTarget);
        options.Controls.Add(chkForce);
        options.Controls.Add(btnRefresh);

        // ---- first-run setup (downloads the Python side a fresh clone does not carry)
        var setup = new Panel();
        setup.Dock = DockStyle.Top;
        setup.Height = 48;
        setup.Padding = new Padding(16, 8, 16, 8);
        setup.BackColor = Color.White;

        btnSetup = new Button();
        btnSetup.Text = "Set up Custom Engine (first run)";
        btnSetup.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
        btnSetup.Size = new Size(360, 32);
        btnSetup.Location = new Point(16, 8);
        btnSetup.FlatStyle = FlatStyle.Flat;
        btnSetup.BackColor = Color.FromArgb(255, 243, 205);
        btnSetup.Click += delegate { GoSetUp(); };
        setup.Controls.Add(btnSetup);

        // ---- log
        txtLog = new TextBox();
        txtLog.Multiline = true;
        txtLog.ReadOnly = true;
        txtLog.ScrollBars = ScrollBars.Both;
        txtLog.WordWrap = false;
        txtLog.Dock = DockStyle.Fill;
        txtLog.BackColor = Color.FromArgb(30, 30, 34);
        txtLog.ForeColor = Color.FromArgb(226, 226, 232);
        txtLog.Font = new Font("Consolas", 8.5F);
        txtLog.BorderStyle = BorderStyle.None;

        var logHost = new Panel();
        logHost.Dock = DockStyle.Fill;
        logHost.Padding = new Padding(16, 8, 16, 8);
        logHost.Controls.Add(txtLog);

        strip = new StatusStrip();
        stripLabel = new ToolStripStatusLabel("ready");
        strip.Items.Add(stripLabel);
        strip.SizingGrip = false;

        Controls.Add(logHost);
        Controls.Add(options);
        Controls.Add(buttons);
        Controls.Add(setup);
        Controls.Add(header);
        Controls.Add(strip);

        Load += delegate { RefreshState(false); };
    }

    bool LiveTarget { get { return cmbTarget.SelectedIndex == 0; } }

    void SetBusy(bool on, string message)
    {
        busy = on;
        btnOriginal.Enabled = !on;
        btnCustom.Enabled = !on;
        btnRefresh.Enabled = !on;
        btnSetup.Enabled = !on;
        cmbTarget.Enabled = !on;
        chkForce.Enabled = !on;
        UseWaitCursor = on;
        stripLabel.Text = message;
    }

    // -------------------------------------------- first run (the big button) --
    //
    // A fresh clone is deliberately small: no .venv, no model, no ffmpeg binary. The CUSTOM
    // button has nothing to start until that Python side exists, so this one button builds it
    // all from official sources, then leaves the engine choice to the user.
    async void GoSetUp()
    {
        if (busy) return;
        SetBusy(true, "setting up the custom engine...");
        txtLog.Text = "";
        try
        {
            string log = SetupCustomEngine();
            txtLog.Text = log;
            if (log.ToUpperInvariant().Contains("SETUP FAILED"))
            {
                ShowFailure("setting up the custom engine did not complete", "");
                return;
            }

            // Re-read the state so the window is accurate now that the venv and model exist.
            // afterAction stays false, and ApplyStatus will not overwrite the setup log above
            // because it only fills an empty log.
            Program.ScriptResult r = await Task.Run(() => Program.RunScript("status", LiveTarget, false, true));
            ApplyStatus(r.Output, false);
            SetBusy(false, "ready - custom engine installed");

            MessageBox.Show(
                "All set up.\n\n"
                + "The custom engine is ready. Now choose which stems processor to use:\n\n"
                + "  Use ORIGINAL stems  - Engine DJ's own processor\n"
                + "  Use CUSTOM stems    - the replacement engine you just set up\n\n"
                + "You can switch between them any time from this window.",
                "Stems Engine Switch", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        catch (Exception e)
        {
            ShowFailure("unexpected error while setting up", e.Message);
        }
    }

    // What the button actually does, kept in one place so --setup and the button cannot drift.
    // Every step is safe to repeat: anything already installed is detected and skipped.
    internal static string SetupCustomEngine()
    {
        string labDir = Program.LabRoot();
        // if that guess is wrong (unusual layout), fall back to the directory holding the exe
        if (!Directory.Exists(Path.Combine(labDir, "shim")))
            labDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

        var sb = new StringBuilder();
        Action<string> log = msg => sb.AppendLine(msg);
        bool failed = false;

        log("Lab root: " + labDir);

        // ---- 1. uv (the tool that can put a Python 3.12 in place without an installer) ----
        string uvExe = FindUsableExe(labDir, "uv.exe", "uv");
        if (uvExe == null)
        {
            log("uv not found beside the app, on PATH or in the venv - downloading it...");
            uvExe = DownloadAndExtractUV(labDir, log);
            if (uvExe == null)
            {
                log("FAILED to obtain uv");
                failed = true;
            }
            else log("uv.exe ready: " + uvExe);
        }
        else log("using uv: " + uvExe);

        // ---- 2. python 3.12 ----
        if (!failed)
        {
            log("making sure Python 3.12 is available (uv python install 3.12)...");
            if (!Run(uvExe, null, log, "python", "install", "3.12"))
                log("uv python install reported a problem - the venv step will say if it matters");
            else log("Python 3.12 ready");
        }

        // ---- 3. the venv, then the pinned packages ----
        string venv = Path.Combine(labDir, ".venv");
        string pythonExe = Path.Combine(venv, "Scripts", "python.exe");
        if (!failed)
        {
            if (!Directory.Exists(venv) || !File.Exists(pythonExe))
            {
                log("creating .venv with uv...");
                if (!Run(uvExe, null, log, "venv", "--python", "3.12", ".venv", labDir))
                {
                    log("FAILED to create .venv");
                    failed = true;
                }
                else log(".venv created");
            }
            else log(".venv already present");

            if (!failed && File.Exists(pythonExe))
            {
                log("installing requirements.txt (the big step - a few GB of wheels)...");
                if (!Run(pythonExe, labDir, log, "-m", "pip", "install", "-r", "requirements.txt"))
                {
                    log("FAILED to install requirements.txt");
                    failed = true;
                }
                else log("requirements installed");
            }
        }

        // ---- 4. the vocal model ----
        if (!failed)
        {
            string audioSep = Path.Combine(venv, "Scripts", "audio-separator.exe");
            if (File.Exists(audioSep))
            {
                string modelsDir = Path.Combine(labDir, "models");
                Directory.CreateDirectory(modelsDir);
                if (Directory.EnumerateFiles(modelsDir, "*.ckpt").Any())
                    log("vocal model already present");
                else
                {
                    log("downloading vocals_mel_band_roformer.ckpt (~900 MB via audio-separator)...");

                    // audio-separator wants ffmpeg on PATH. imageio-ffmpeg is installed by the
                    // step above; put the lab's own copy in front of PATH for this child only.
                    var env = new Dictionary<string, string>();
                    System.Collections.IDictionary current = Environment.GetEnvironmentVariables();
                    foreach (System.Collections.DictionaryEntry kv in current)
                    {
                        string k = kv.Key as string;
                        string v = kv.Value as string;
                        if (k != null && v != null) env[k] = v;
                    }
                    string ffmpeg = Path.Combine(labDir, ".ffmpeg", "ffmpeg.exe");
                    if (File.Exists(ffmpeg) && env.ContainsKey("PATH"))
                        env["PATH"] = ffmpeg + ";" + env["PATH"];

                    if (!RunWithEnv(audioSep, labDir, log, env,
                                    "--model_filename", "vocals_mel_band_roformer.ckpt",
                                    "--model_file_dir", modelsDir,
                                    "--download_model_only"))
                    {
                        log("FAILED to download the vocal model");
                        failed = true;
                    }
                    else log("vocal model downloaded");
                }
            }
            else log("WARNING: audio-separator.exe is missing after pip install - model step skipped");
        }

        // ---- 5. ffmpeg (recreated from the imageio-ffmpeg cache, same call the service makes) ----
        if (!failed && File.Exists(pythonExe))
        {
            log("recreating .ffmpeg\\ffmpeg.exe...");
            // separate.py sits at the lab root and is imported the same way the engine service
            // imports it (lab root on sys.path), so mirror that here.
            if (!Run(pythonExe, labDir, log, "-c",
                     "import sys, os; sys.path.insert(0, os.getcwd()); import separate; separate.ensure_ffmpeg()"))
                log("WARNING: ffmpeg could not be recreated now - the service will try again on first use");
            else log("ffmpeg ready");
        }

        // ---- 6. demucs weights, so the first real separation does not stop to download ----
        if (!failed && File.Exists(pythonExe))
        {
            log("pre-fetching the demucs htdemucs_ft weights...");
            if (!Run(pythonExe, labDir, log, "-c",
                     "import os; os.environ['HF_HUB_DISABLE_PROGRESS_BARS']='1'; "
                     + "from demucs.api import Separator; "
                     + "Separator(model='htdemucs_ft', device='cpu', shifts=0, jobs=0, progress=False); "
                     + "print('demucs weights ready')"))
                log("WARNING: demucs weights were not fetched now - they download on first use");
            else log("demucs weights ready");
        }

        sb.Insert(0, failed ? "SETUP FAILED\n================\n" : "SETUP COMPLETE\n================\n");
        return sb.ToString();
    }

    // ------------------------- helpers used by the setup flow --

    static string FindUsableExe(string labDir, string fileName, string pathName)
    {
        // prefer the copy beside the app (stable, no PATH or venv needed)
        string beside = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), fileName);
        if (File.Exists(beside)) return beside;

        string onPath;
        if (pathName != null && TryFindOnPath(pathName, out onPath)) return onPath;

        string inVenv = Path.Combine(labDir, ".venv", "Scripts", fileName);
        if (File.Exists(inVenv)) return inVenv;
        return null;
    }

    static bool TryFindOnPath(string name, out string foundPath)
    {
        foundPath = null;
        string pathVar = Environment.GetEnvironmentVariable("PATH");
        string[] dirs = (pathVar != null) ? pathVar.Split(Path.PathSeparator) : new string[0];
        // Windows PATH entries hold uv.exe, not uv, so the .exe form is tried too
        string withExe = name.EndsWith(".exe", StringComparison.OrdinalIgnoreCase) ? name : name + ".exe";
        foreach (string dir in dirs)
        {
            if (dir == null) continue;
            string clean = dir.Trim('"');
            if (clean.Length == 0) continue;
            string candidate = Path.Combine(clean, withExe);
            if (File.Exists(candidate)) { foundPath = candidate; return true; }
        }
        return false;
    }

    // The one piece the button cannot take from an existing install: uv itself. It ships as a
    // plain zip on Astral's GitHub releases, so a bare PC needs no installer and no admin.
    static string DownloadAndExtractUV(string labDir, Action<string> log)
    {
        string beside = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), "uv.exe");
        if (File.Exists(beside)) return beside;

        string zipPath = Path.Combine(labDir, "_uv_download.zip");
        string extractDir = Path.Combine(labDir, "_uv_extract");

        log("downloading uv-x86_64-pc-windows-msvc.zip (about 15 MB)...");
        try
        {
            // .NET Framework still negotiates TLS 1.0 by default, which GitHub refuses
            System.Net.ServicePointManager.SecurityProtocol = System.Net.SecurityProtocolType.Tls12;
        }
        catch (Exception) { /* very old runtime; the download below will report the failure */ }

        try
        {
            using (var client = new System.Net.WebClient())
                client.DownloadFile(
                    "https://github.com/astral-sh/uv/releases/download/0.13.0/uv-x86_64-pc-windows-msvc.zip",
                    zipPath);
        }
        catch (Exception e)
        {
            log("FAILED to download uv: " + e.Message);
            return null;
        }

        log("extracting uv.exe...");
        try
        {
            if (Directory.Exists(extractDir)) Directory.Delete(extractDir, true);
            Directory.CreateDirectory(extractDir);
            ZipFile.ExtractToDirectory(zipPath, extractDir);

            string[] found = Directory.GetFiles(extractDir, "uv.exe", SearchOption.AllDirectories);
            if (found.Length == 0)
            {
                log("uv.exe was not found inside the archive");
                return null;
            }
            if (File.Exists(beside)) File.Delete(beside);
            File.Move(found[0], beside);
            log("uv.exe installed beside the app: " + beside);
            return beside;
        }
        catch (Exception e)
        {
            log("FAILED to extract uv: " + e.Message);
            return null;
        }
        finally
        {
            try { if (Directory.Exists(extractDir)) Directory.Delete(extractDir, true); } catch (Exception) { }
            try { if (File.Exists(zipPath)) File.Delete(zipPath); } catch (Exception) { }
        }
    }

    static bool Run(string exe, string workingDir, Action<string> log, params string[] args)
    {
        return Run(exe, workingDir, log, Environment.GetEnvironmentVariables(), args);
    }

    static bool Run(string exe, string workingDir, Action<string> log,
                    System.Collections.IDictionary environment, params string[] args)
    {
        if (exe == null)
        {
            log("cannot run a step because the program it needs was not found");
            return false;
        }

        var psi = new ProcessStartInfo();
        psi.FileName = exe;
        psi.Arguments = string.Join(" ", args.Select(EscapeArg).ToArray());
        psi.WorkingDirectory = workingDir;
        psi.UseShellExecute = false;
        psi.CreateNoWindow = true;
        psi.RedirectStandardOutput = true;
        psi.RedirectStandardError = true;
        foreach (System.Collections.DictionaryEntry kv in environment)
        {
            string k = kv.Key as string;
            string v = kv.Value as string;
            if (k != null && v != null) psi.EnvironmentVariables[k] = v;
        }

        try
        {
            using (var p = Process.Start(psi))
            {
                if (p == null)
                {
                    log("FAILED to start: " + exe);
                    return false;
                }
                Task<string> outTask = p.StandardOutput.ReadToEndAsync();
                Task<string> errTask = p.StandardError.ReadToEndAsync();
                p.WaitForExit();
                foreach (string line in SplitLines(outTask.Result)) log(line);
                foreach (string line in SplitLines(errTask.Result)) log(line);
                return p.ExitCode == 0;
            }
        }
        catch (Exception e)
        {
            log("FAILED: " + e.Message);
            return false;
        }
    }

    static bool RunWithEnv(string exe, string workingDir, Action<string> log,
                           System.Collections.IDictionary env, params string[] args)
    {
        return Run(exe, workingDir, log, env, args);
    }

    static string[] SplitLines(string text)
    {
        if (string.IsNullOrEmpty(text)) return new string[0];
        string[] parts = text.Replace("\r\n", "\n").Split('\n');
        var kept = new List<string>();
        foreach (string part in parts)
            if (part.Trim().Length > 0) kept.Add(part.TrimEnd());
        return kept.ToArray();
    }

    static string EscapeArg(string a)
    {
        if (string.IsNullOrEmpty(a)) return "\"\"";
        if (a.IndexOf(' ') < 0 && a.IndexOf('"') < 0) return a;
        return "\"" + a.Replace("\"", "\"\"") + "\"";
    }

    async void RefreshState(bool afterAction)
    {
        SetBusy(true, "reading current state...");
        try
        {
            Program.ScriptResult r = await Task.Run(() => Program.RunScript("status", LiveTarget, false, true));
            if (r.ExitCode != 0) { ShowFailure("could not read the current state", r.Output); return; }
            ApplyStatus(r.Output, afterAction);
            SetBusy(false, "ready");
        }
        catch (Exception e)
        {
            ShowFailure("unexpected error", e.Message);
        }
    }

    async void Go(string mode)
    {
        bool toCustom = mode == "custom";

        if (toCustom && currentEngine == "unknown")
        {
            MessageBox.Show(
                "First-time setup: click \"Set up ORIGINAL stems\" once.\n\n"
                + "That records which file is Engine DJ's original processor, which is the "
                + "restore point the switch needs before it will touch anything.",
                "Stems Engine Switch", MessageBoxButtons.OK, MessageBoxIcon.Information);
            return;
        }

        string resolved = Program.ResolveMode(mode, currentEngine);
        string what = resolved == "adopt" ? "original baseline" : (toCustom ? "custom" : "original");

        if (chkForce.Checked)
        {
            var answer = MessageBox.Show(
                "Force is on. The switch will modify files even if Engine DJ is running.\n\nContinue?",
                "Stems Engine Switch", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (answer != DialogResult.Yes) return;
        }

        SetBusy(true, "switching to " + what + " stems...");
        txtLog.Text = "";
        try
        {
            bool force = chkForce.Checked;
            Program.ScriptResult r = await Task.Run(() => Program.RunScript(resolved, LiveTarget, force, false));
            txtLog.Text = r.Output;
            if (r.ExitCode != 0)
            {
                ShowFailure("switch to " + what + " stems did not complete", "");
                SetBusy(false, "no change made");
                return;
            }
            Program.ScriptResult r2 = await Task.Run(() => Program.RunScript("status", LiveTarget, false, true));
            ApplyStatus(r2.Output, true);
            SetBusy(false, toCustom ? "now using custom stems" : "back on the original stems");
        }
        catch (Exception e)
        {
            ShowFailure("unexpected error", e.Message);
        }
    }

    void ApplyStatus(string json, bool afterAction)
    {
        string engine = Program.JsonString(json, "engine");
        currentEngine = engine;
        string bin = Program.JsonString(json, "bin");
        string baseline = Program.JsonString(json, "baselineHash");
        string active = Program.JsonString(json, "activeHash");
        string appRunning = Program.JsonRaw(json, "appRunning");
        bool running = appRunning != null && appRunning.Replace(" ", "") != "[]";

        string text;
        Color colour;
        switch (engine)
        {
            case "vendor":
                text = "ORIGINAL STEMS  (Engine DJ's processor)";
                colour = Color.FromArgb(31, 78, 140);
                break;
            case "custom":
                text = "CUSTOM STEMS  (replacement engine)";
                colour = Color.FromArgb(28, 122, 55);
                break;
            case "none":
                text = "NO PROCESSOR PRESENT";
                colour = Color.FromArgb(160, 40, 40);
                break;
            default:
                text = "NOT SET UP YET";
                colour = Color.FromArgb(160, 110, 20);
                break;
        }
        lblEngine.Text = text;
        lblEngine.ForeColor = colour;

        string hint = ShortHash(bin) + "\n";
        if (engine == "vendor") hint += "Restore point: everything is stock.\n";
        if (engine == "custom") hint += "The original is preserved alongside as stems-processor.vendor.exe.\n";
        if (engine == "unknown") hint += "Click \"Use ORIGINAL stems\" once to record the stock baseline, then switch to custom.\n";
        hint += "active " + ShortHash(active) + "   baseline " + ShortHash(baseline);
        if (running) hint += "\nEngine DJ is open - close it before switching.";
        lblDetail.Text = hint;

        btnOriginal.Font = new Font("Segoe UI", 11F, engine == "vendor" ? FontStyle.Bold : FontStyle.Regular);
        btnCustom.Font = new Font("Segoe UI", 11F, engine == "custom" ? FontStyle.Bold : FontStyle.Regular);
        btnOriginal.FlatAppearance.BorderSize = engine == "vendor" ? 3 : 1;
        btnCustom.FlatAppearance.BorderSize = engine == "custom" ? 3 : 1;
        btnOriginal.Text = engine == "unknown" ? "Set up ORIGINAL stems" : "Use ORIGINAL stems";
        lblOriginalHint.Text = engine == "vendor" ? "in use now"
            : (engine == "unknown" ? "first-time: records the original, then you can switch" : "Engine DJ's own processor");
        lblCustomHint.Text = engine == "custom" ? "in use now" : "Your replacement engine";

        if (!afterAction && string.IsNullOrEmpty(txtLog.Text))
            txtLog.Text = "Engine: " + engine + Environment.NewLine
                + "Folder: " + bin + Environment.NewLine
                + "Active: " + active + Environment.NewLine
                + "Baseline: " + (baseline ?? "(not recorded yet)") + Environment.NewLine;
    }

    static string ShortHash(string hash)
    {
        if (string.IsNullOrEmpty(hash)) return "(none)";
        return hash.Substring(0, 8) + "...";
    }

    void ShowFailure(string title, string detail)
    {
        lblEngine.Text = title.ToUpperInvariant();
        lblEngine.ForeColor = Color.FromArgb(170, 40, 40);
        if (!string.IsNullOrEmpty(detail)) txtLog.Text = detail;
        SetBusy(false, "failed - see the log below");
    }
}
