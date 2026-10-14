"""Resident stem separation service.

The replacement processor is a two-part thing:

  stems-processor.exe  (the shim Engine DJ spawns: speaks the host's stdio protocol)
      |
      v  loopback TCP, one JSON object per line
  engine_service.py    (this file: loads the models once, separates, caches, replies)

Keeping the models in their own long-lived process means they load once instead of once
per track, and it keeps every heavy dependency (torch, demucs, audio-separator) out of the
Engine DJ install directory entirely.

Separation is the cascade already measured in ../COMPARE.md:

  vocals        <- vocals_mel_band_roformer
  residual      = mix - vocals
  drums/bass/other <- htdemucs_ft on the residual      (so the four stems still sum to the mix)
  vocals       += htdemucs' own vocals head on the residual

The last line is the 2026-10-14 fix for vocals sitting ~2.3 dB under the other three stems: the
roformer under-estimates, and the residual's vocals head is where the missing energy went, so
throwing it away (what this did before) was throwing away a coherent copy of the vocal. See
add_vocals_leftover() and the measurements in ../COMPARE.md.

Requests are one JSON object per line on a loopback socket; replies are one JSON object per
line. The port is written to engine.port next to this file so the shim can find it.

  {"cmd":"ping"}                                  -> models, device, cache stats
  {"cmd":"separate","path":"<audio file>"}        -> four stem WAV paths (cached by content hash)
  {"cmd":"stop"}                                  -> shuts the service down

Its lifetime is the app's: the shim starts it with --watch-pid <the app that needs it> and it
stops when that process does (or after --idle-exit-minutes with no requests at all, 60 by
default). One service per machine, too - see DEFAULT_PORT below.

Run it directly to watch it work:

  .venv/Scripts/python.exe engine/engine_service.py --once test/emms.mp3 --segment 0:15

Lifetime (see "When the service stops" below): one instance per machine, and it goes away with
the app that needed it.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import math
import os
import pathlib
import re
import shutil
import socket
import sys
import threading
import traceback
import time

HERE = pathlib.Path(__file__).resolve().parent
LAB = HERE.parent
sys.path.insert(0, str(LAB))

import separate  # noqa: E402  (needs the sys.path entry above)

VOCALS_MODEL = "vocals_mel_band_roformer.ckpt"
OTHER_MODEL = "htdemucs_ft"
STEM_NAMES = ("vocals", "drums", "bass", "other")

# Bumped whenever the same audio would come out different, so a render in engine/cache is never
# served after the pipeline that made it has changed. "3" is the vocals-leftover fix of
# 2026-10-14: a cache written by the older pipeline holds the quieter vocals stem.
PIPELINE_VERSION = "3"

# Where the service keeps its state. Overridable so a second lab (or a test) can run beside the
# real one on the same machine without either seeing the other's port, log or renders.
PORT_FILE = pathlib.Path(os.environ.get("STEMS_PORT_FILE") or (HERE / "engine.port"))
CACHE_DIR = pathlib.Path(os.environ.get("STEMS_CACHE_DIR") or (HERE / "cache"))
LOG_FILE = pathlib.Path(os.environ.get("STEMS_LOG_FILE") or (HERE / "engine.log"))
STREAM_LOG = pathlib.Path(os.environ.get("STEMS_STREAM_LOG") or (HERE / "stdstream.log"))

# One engine per machine. The port is fixed rather than asked of the OS because several shims
# start at once - Engine DJ launches one processor per track in a batch, and they all race to
# bring the engine up. With a random port each of them binds its own and the machine ends up with
# a service per shim, every one of them holding a full set of models; on 2026-10-13 a real batch
# of 13 tracks left two of them behind (engine.log: two "[serve] listening" in the same second).
# A fixed port means the loser of the race cannot bind, finds the winner and exits instead of
# loading anything. It is only ever a preference: if something else already owns the port, the
# service falls back to an OS-assigned one and still writes engine.port, so nothing depends on
# 51917 being free.
DEFAULT_PORT = 51917

# A service nobody asked for any more must not sit on a GPU for the rest of the day. The app is
# the natural end of its life: the first shim hands over the pid of the app that started it
# (--watch-pid), and the service stops when that process is gone. The idle timer is the fallback
# for a service started by hand, with no app to watch.
IDLE_EXIT_MINUTES = 60.0
DRAIN_SECONDS = 30.0

# The env var the shim and the tests use to keep the engine up regardless (debugging).
KEEP_ENGINE = (os.environ.get("STEMS_KEEP_ENGINE", "").strip() not in ("", "0"))


class _MirrorStream:
    """A std stream that cannot fail.

    Our standard handles are borrowed, not owned. The shim hands us pipes, then exits at the end
    of the job and the handles break; on Windows a write to a broken pipe raises EINVAL(22).
    demucs' own progress bar writes to sys.stderr, so that alone is enough to kill a perfectly
    healthy separation - which is exactly what happened on the second job of a session.

    Anything a library writes here is appended to stdstream.log instead, so the information
    survives and no write can raise.
    """

    def __init__(self, tag: str):
        self.tag = tag

    def write(self, text: str) -> int:
        if text:
            try:
                with STREAM_LOG.open("a", encoding="utf-8", errors="replace") as fh:
                    for line in text.replace("\r", "\n").splitlines():
                        if line.strip():
                            fh.write(f"{self.tag} {line}\n")
            except OSError:
                pass
        return len(text)

    def writelines(self, lines) -> None:
        for line in lines:
            self.write(line)

    def flush(self) -> None:
        pass

    def isatty(self) -> bool:
        return False


def describe_streams() -> str:
    """What the standard streams look like, for the startup log line.

    The shim starts this service with no handles at all (bInheritHandles=FALSE), so the three
    streams are whatever python makes of that; the same line also covers a service started by hand
    in a console. It is how "why is nothing in stdstream.log" gets answered without guessing.
    """
    parts = []
    for name in ("stdin", "stdout", "stderr"):
        stream = getattr(sys, name, None)
        if stream is None:
            parts.append(f"{name}=none")
            continue
        try:
            parts.append(f"{name}={'tty' if stream.isatty() else 'not-a-tty'}")
        except Exception:
            parts.append(f"{name}=unknown")
    return " ".join(parts)


def install_safe_streams(mirror_stdio: bool = False) -> None:
    """Never let a library write to an inherited handle that may already be broken.

    A service started in a real console writes to that console, which is the useful place for
    diagnostics. One started by the shim gets no handles at all (bInheritHandles=FALSE) and is
    asked for --mirror-stdio instead: what python makes of having no handles is not something to
    build on - on this machine it answers isatty() True for three NULL handles, so the old
    isatty() test alone would send every library's output into nothing.
    """
    if not mirror_stdio and sys.stderr is not None and sys.stderr.isatty():
        return  # a real console is the useful place for diagnostics; leave it alone
    sys.stdout = _MirrorStream("[out]")
    sys.stderr = _MirrorStream("[err]")


def log(message: str) -> None:
    """The log file is written FIRST on purpose.

    stderr belongs to whoever started the service. If that pipe is never drained - which is
    exactly what happens when the shim starts us - a write to it blocks once the pipe buffer
    fills, and anything written afterwards never happens. Writing the file first means a
    blocked stderr can slow a log line down but can never lose it.
    """
    line = f"{time.strftime('%Y-%m-%d %H:%M:%S')} {message}"
    try:
        with LOG_FILE.open("a", encoding="utf-8") as fh:
            fh.write(line + "\n")
    except OSError:
        pass
    try:
        print(line, file=sys.stderr, flush=True)
    except BaseException:
        pass


def process_alive(pid: int) -> bool:
    """Is that process still running? The service's reason to live is usually an app's pid.

    OpenProcess with SYNCHRONIZE only needs the right to wait on the handle, so it works across
    integrity levels in practice; a refusal is treated as "still there" rather than as an excuse
    to exit, because the only cost of being wrong that way is a cold model load later.
    """
    if pid <= 0:
        return False
    try:
        import ctypes

        kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)
        handle = kernel32.OpenProcess(0x00100000, False, int(pid))   # SYNCHRONIZE
        if not handle:
            return ctypes.get_last_error() == 5                      # ERROR_ACCESS_DENIED
        try:
            # WAIT_TIMEOUT (0x102) is a process that is still running.
            return kernel32.WaitForSingleObject(handle, 0) == 0x102
        finally:
            kernel32.CloseHandle(handle)
    except Exception:
        try:
            os.kill(int(pid), 0)
            return True
        except OSError as exc:
            return getattr(exc, "errno", None) in (1, 13)           # EPERM/EACCES -> it exists
        except Exception:
            return True


class Lifespan:
    """When the service has no reason to keep living. State only, so it can be tested directly.

    stop_reason() is the whole policy:
      * the app this engine was started for is gone  -> stop (the machine is free again)
      * nobody has asked for anything for N minutes  -> stop (started by hand, forgotten)
      * STEMS_KEEP_ENGINE=1                          -> never (a debugging run)
    A job in flight does not cancel the reason; serve() drains it before exiting, which is what
    keeps a separation from being cut in half.
    """

    def __init__(self, watch_pid: int | None = None, idle_minutes: float = IDLE_EXIT_MINUTES,
                 keep: bool = False, clock=time.monotonic, alive=process_alive):
        self.watch_pid = watch_pid
        self.idle_seconds = max(0.0, float(idle_minutes) * 60.0)
        self.keep = keep
        self._clock = clock
        self._alive = alive
        self.started = clock()
        self.last_request = self.started
        self.active_jobs = 0
        self.app_seen = False
        self.stopped_because: str | None = None

    def touch(self) -> None:
        self.last_request = self._clock()

    def job_started(self) -> None:
        self.active_jobs += 1

    def job_finished(self) -> None:
        self.active_jobs = max(0, self.active_jobs - 1)

    def describe(self) -> str:
        watch = f"watching pid {self.watch_pid}" if self.watch_pid else "no app to watch"
        idle = f"{self.idle_seconds / 60:.1f} min idle exit" if self.idle_seconds else "no idle exit"
        return watch + ", " + idle + (", kept alive by STEMS_KEEP_ENGINE" if self.keep else "")

    def stop_reason(self) -> str | None:
        if self.keep:
            return None
        if self.watch_pid:
            if self._alive(self.watch_pid):
                self.app_seen = True
            else:
                return (f"the app this engine was started for (pid {self.watch_pid}) is gone")
        if self.idle_seconds and self._clock() - self.last_request >= self.idle_seconds:
            return f"idle for {self.idle_seconds / 60:.1f} min"
        return None


# The lifespan of the running service. serve() replaces it; dispatch() reads it for the ping
# reply. Kept module-level so small tests can exercise a request without standing a server up.
LIFESPAN = Lifespan(keep=True)


def pick_device() -> str:
    """Which compute device a separation should use.

    "cuda" when this machine's torch sees a CUDA GPU, otherwise "cpu". STEMS_DEVICE overrides
    the choice (for example STEMS_DEVICE=cpu on a machine whose GPU should be left alone, or a
    pinned 'cuda'/'cpu' for testing).
    """
    env = os.environ.get("STEMS_DEVICE", "").strip().lower()
    if env:
        return env
    try:
        import torch
        return "cuda" if torch.cuda.is_available() else "cpu"
    except Exception:
        return "cpu"


def cache_key(path: pathlib.Path, segment: str | None = None) -> str:
    """Content hash, so re-running the same track is free and different rips differ."""
    digest = hashlib.sha256()
    digest.update(f"v{PIPELINE_VERSION}|{VOCALS_MODEL}|{OTHER_MODEL}|{segment or 'full'}|".encode())
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()[:32]


def free_scratch(tmp: pathlib.Path) -> int:
    """Delete one job's scratch directory and report the bytes it was holding.

    The models write their per-stem intermediates under `_tmp`, which is as large as the four
    stems the job keeps (about 200 MB for a 193 s track). Nothing reads it once the stems are
    written, and a cached job is served from the stems alone, so it is removed on the way out
    of every run - success or failure.
    """
    if not tmp.exists():
        return 0
    freed = 0
    for root, _dirs, files in os.walk(tmp):
        for name in files:
            try:
                freed += (pathlib.Path(root) / name).stat().st_size
            except OSError:
                pass
    shutil.rmtree(tmp, ignore_errors=True)
    return freed


def add_vocals_leftover(vocals, leftover):
    """Add the residual's own vocals head back onto the roformer's vocals stem.

    htdemucs' vocals head run on `mix - roformer_vocals` describes exactly what the roformer left
    behind. Measured on Test 1, 60-120 s (tests/sandbox/vocals-metrics.py, numbers in COMPARE.md):

      * the leftover is the same signal, not bleed: correlation +0.78 with the roformer stem and
        +0.01 with the drum stem;
      * adding it puts the vocals stem at the level the mix has the vocal at (-0.56 dB under the
        mix on quiet-accompaniment frames, where the stock engine's own vocals is -1.18 dB, and
        the stem without it is -3.39 dB) - i.e. the under-estimate returned, not a fudge factor;
      * it stays clean while doing so: vocals 1.1 dB quieter on kick/snare frames than without
        it, HF share moving toward the mix's rather than away.

    Nothing else moves, so the four stems still sum to the mix - better than before, since this
    energy was being dropped. Returns (vocals, gain in dB) or (vocals, None) if the two stages
    disagree on shape, in which case the stem is left exactly as the roformer made it.
    """
    if leftover is None or tuple(leftover.shape) != tuple(vocals.shape):
        return vocals, None
    combined = vocals + leftover
    rms = lambda t: float(t.pow(2).mean().sqrt())  # noqa: E731
    before, after = rms(vocals), rms(combined)
    gain = 20.0 * math.log10(after / before) if before > 0 else None
    return combined, gain


def separate_track(path: pathlib.Path, start: float | None, end: float | None, outdir: pathlib.Path) -> dict:
    """The cascade. Returns {stem: wav path} plus timing. Its scratch is removed before return."""
    import numpy as np
    import soundfile as sf

    device = pick_device()
    if device.startswith("cuda"):
        import torch
        if not torch.cuda.is_available():
            log("[device] CUDA was requested but torch cannot see a GPU - using CPU")
            device = "cpu"
    log(f"[device] {device}")

    separate.ensure_ffmpeg()
    outdir.mkdir(parents=True, exist_ok=True)
    tmp = outdir / "_tmp"
    t0 = time.time()

    try:
        wav, sr = separate.load_audio(path, start, end, 44100)
        seconds = wav.shape[1] / sr
        log(f"[load] {path.name} {seconds:.1f}s @ {sr} Hz")

        vocal_stems, _ = separate.run_audio_separator(wav, sr, VOCALS_MODEL, device, tmp / "vocals")
        vocals = next(v for k, v in vocal_stems.items() if k == "vocals")
        residual = wav - vocals
        log(f"[stage1] roformer vocals done ({tuple(vocals.shape)})")

        inst_stems, out_sr = separate.run_demucs(residual, sr, OTHER_MODEL, device, shifts=1, jobs=0)
        log(f"[stage2] htdemucs on residual -> {sorted(inst_stems)}")

        # What the roformer under-estimated ends up in htdemucs' vocals head on the residual; it
        # is part of the vocals stem, not waste (see add_vocals_leftover).
        vocals, recovered = add_vocals_leftover(vocals, inst_stems.get("vocals"))
        if recovered is None:
            log("[stage3] no usable residual vocals head (missing, or a different shape from the "
                "roformer's) - the vocals stem stays as stage 1 left it")
        else:
            log(f"[stage3] vocals +{recovered:.2f} dB recovered from the residual")

        stems = {"vocals": vocals}
        for name, tensor in inst_stems.items():
            if name != "vocals":
                stems[name] = tensor

        written = {}
        for name in STEM_NAMES:
            tensor = stems[name]
            arr = np.ascontiguousarray(tensor.numpy().T)
            target = outdir / f"{name}.wav"
            sf.write(str(target), arr, out_sr, subtype="FLOAT")
            written[name] = str(target)

        elapsed = time.time() - t0
        log(f"[done] {elapsed:.1f}s ({elapsed / max(seconds, 1e-6):.2f}x realtime) -> {outdir}")
        return {
            "stems": written,
            "sample_rate": out_sr,
            "seconds": round(seconds, 3),
            "elapsed_s": round(elapsed, 2),
            "realtime_factor": round(elapsed / max(seconds, 1e-6), 3),
            "cached": False,
        }
    finally:
        freed = free_scratch(tmp)
        if freed:
            log(f"[clean] scratch removed, {freed / 1048576:.0f} MB reclaimed ({tmp.name})")


_JOB_LOCKS = {}
_JOB_LOCKS_GUARD = threading.Lock()


def job_lock(key: str):
    """One lock per cache key, made on demand - one small object per separated track."""
    with _JOB_LOCKS_GUARD:
        lock = _JOB_LOCKS.get(key)
        if lock is None:
            lock = threading.Lock()
            _JOB_LOCKS[key] = lock
        return lock


def cached_result(outdir: pathlib.Path, key: str, name: str) -> dict | None:
    """The finished render for one cache key, or None when there is not a complete one."""
    manifest = outdir / "manifest.json"
    if not manifest.is_file():
        return None
    try:
        data = json.loads(manifest.read_text(encoding="utf-8"))
        if not all(pathlib.Path(p).is_file() for p in data.get("stems", {}).values()):
            return None
    except (ValueError, OSError):
        return None

    data["cached"] = True
    data["cache_key"] = key
    # A hit is use. The shim sweeps renders nothing has written to for hours, so the entry being
    # served has to look alive or a concurrent job's sweep could delete the very files this
    # request is about to hand back.
    try:
        os.utime(manifest, None)
    except OSError:
        pass
    log(f"[cache] hit for {name} ({key})")
    return data


def handle_separate(req: dict, segment: str | None) -> dict:
    raw = req.get("path")
    if not raw:
        return {"ok": False, "error": "missing 'path'"}
    path = pathlib.Path(raw)
    if not path.is_file():
        return {"ok": False, "error": f"not a file: {path}"}

    key = cache_key(path, segment)
    outdir = CACHE_DIR / key

    hit = cached_result(outdir, key, path.name)
    if hit is not None:
        return {"ok": True, **hit}

    start = end = None
    if segment:
        a, b = segment.split(":")
        start, end = float(a), float(b)

    # One separation per cache key at a time. Two Engine DJ windows - or a retry while the first
    # job still looks slow - would otherwise write the same `_tmp` scratch and the same stem
    # files, and whichever finished first would delete the other's scratch on the way out. The
    # loser then never finished at all, and both ran at half speed for sharing the CPU.
    lock = job_lock(key)
    if lock.acquire(blocking=False):
        waited = False
    else:
        log(f"[queue] {path.name} is already separating under {key} - waiting for that job instead of starting a second one")
        lock.acquire()
        waited = True

    try:
        if waited:
            hit = cached_result(outdir, key, path.name)
            if hit is not None:
                log(f"[queue] {path.name} was finished by the job we waited for - serving it from cache")
                return {"ok": True, **hit}

        log(f"[separate] {path.name} -> {key}")
        result = separate_track(path, start, end, outdir)
        result["cache_key"] = key
        (outdir / "manifest.json").write_text(
            json.dumps({k: v for k, v in result.items() if k != "cached"}, indent=2), encoding="utf-8"
        )
        return {"ok": True, **result}
    finally:
        lock.release()


def bind_listener(host: str, port: int) -> socket.socket:
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # On Windows SO_REUSEADDR lets a second process bind a port that is already being listened
    # on, which would quietly defeat the one-instance rule; there the flag that means "mine
    # alone" is SO_EXCLUSIVEADDRUSE. Elsewhere SO_REUSEADDR is what lets a restart take its own
    # port back from TIME_WAIT.
    exclusive = getattr(socket, "SO_EXCLUSIVEADDRUSE", None)
    if exclusive is not None:
        srv.setsockopt(socket.SOL_SOCKET, exclusive, 1)
    else:
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    srv.bind((host, port))
    srv.listen(8)
    return srv


def serving_here(port: int, timeout: float = 1.0) -> bool:
    """Is an engine service already answering on this port?"""
    try:
        with socket.create_connection(("127.0.0.1", port), timeout=timeout) as c:
            c.settimeout(timeout)
            c.sendall(b'{"cmd":"ping"}\n')
            data = b""
            while not data.endswith(b"\n"):
                chunk = c.recv(4096)
                if not chunk:
                    break
                data += chunk
        return re.search(rb'"ok"\s*:\s*true', data) is not None
    except OSError:
        return False


def acquire_listener(host: str, port: int) -> tuple[socket.socket | None, int, str]:
    """Take the listening port, or report that an engine already holds it.

    (None, port, reason) means "a service is already serving there": this process has nothing to
    load and nothing to do, which is what keeps a batch of shims from each starting an engine.
    """
    for _attempt in range(4):
        try:
            return bind_listener(host, port), port, ""
        except OSError:
            # The winner of the race may be listening but not yet accepting; the probe waits.
            if serving_here(port):
                return None, port, f"another engine is already serving on port {port}"
            time.sleep(0.25)
    # Something else owns the port and does not speak the protocol. A free port still serves the
    # job; engine.port is what the shim actually reads, so nothing depends on the fixed one.
    log(f"[serve] port {port} is taken by something that is not this engine - using a free port")
    srv = bind_listener(host, 0)
    return srv, srv.getsockname()[1], ""


def watch_lifespan(lifespan: Lifespan, stop_event: threading.Event) -> None:
    """Ends the service when the reason it exists has gone away (see Lifespan)."""
    while not stop_event.is_set():
        reason = lifespan.stop_reason()
        if reason:
            lifespan.stopped_because = reason
            jobs = lifespan.active_jobs
            log(f"[serve] {reason} - shutting down"
                + (f" once the {jobs} running job(s) finish" if jobs else ""))
            stop_event.set()
            return
        stop_event.wait(1.0)


def wait_for_jobs(lifespan: Lifespan, seconds: float) -> bool:
    """Leave any job already in flight alone for a moment before the process ends."""
    deadline = time.monotonic() + seconds
    while lifespan.active_jobs > 0 and time.monotonic() < deadline:
        time.sleep(0.2)
    return lifespan.active_jobs == 0


def serve(host: str, port: int, segment: str | None, stop_event: threading.Event,
          lifespan: Lifespan | None = None) -> None:
    global LIFESPAN
    if lifespan is not None:
        LIFESPAN = lifespan
    lifespan = LIFESPAN

    srv, actual, note = acquire_listener(host, port)
    if srv is None:
        # Point engine.port at the engine that keeps the port: the file may be missing, or a loser
        # of an older race may have left a stale one. Then get out of the way without loading
        # anything - that is the whole point of not having a second service on this machine.
        try:
            PORT_FILE.write_text(str(actual), encoding="utf-8")
        except OSError:
            pass
        log(f"[serve] {note} - exiting, the running one keeps the port")
        return

    PORT_FILE.write_text(str(actual), encoding="utf-8")
    log(f"[serve] listening on {host}:{actual} (segment={segment or 'full'}; {lifespan.describe()})")
    started = time.time()

    threading.Thread(target=watch_lifespan, args=(lifespan, stop_event), daemon=True).start()

    srv.settimeout(0.5)
    while not stop_event.is_set():
        try:
            conn, addr = srv.accept()
        except socket.timeout:
            continue
        except OSError:
            break
        threading.Thread(target=handle_connection, args=(conn, addr, segment, stop_event), daemon=True).start()

    # Closed before the drain below, so a shim arriving now is told there is no engine and starts
    # a fresh one instead of being handed a service that is on its way out.
    try:
        srv.close()
    except OSError:
        pass

    drained = wait_for_jobs(lifespan, DRAIN_SECONDS)
    try:
        # Only ever remove our own file: between a service deciding to stop and the unlink below,
        # a fresh engine can already have written its own port here.
        if PORT_FILE.read_text(encoding="utf-8").strip() == str(actual):
            PORT_FILE.unlink()
    except (OSError, ValueError):
        pass
    log(f"[serve] stopped after {time.time() - started:.0f}s ({lifespan.stopped_because or 'asked to stop'})"
        + ("" if drained else f" - a job was still running after {DRAIN_SECONDS:.0f}s"))


def handle_connection(conn: socket.socket, addr, segment: str | None, stop_event: threading.Event) -> None:
    conn.settimeout(None)
    try:
        reader = conn.makefile("r", encoding="utf-8", newline="\n")
        writer = conn.makefile("w", encoding="utf-8", newline="\n")
        for line in reader:
            line = line.strip()
            if not line:
                continue
            LIFESPAN.touch()
            log(f"[req] {line[:200]}")
            try:
                req = json.loads(line)
            except ValueError as exc:
                reply = {"ok": False, "error": f"bad json: {exc}"}
            else:
                try:
                    reply = dispatch(req, segment, stop_event)
                except BaseException as exc:  # never answer a request with silence
                    log(f"[error] request failed: {exc!r}")
                    reply = {"ok": False, "error": repr(exc)}
            writer.write(json.dumps(reply) + "\n")
            writer.flush()
            if reply.get("shutdown"):
                break
    except OSError as exc:
        log(f"[serve] connection from {addr} failed: {exc}")
    except BaseException as exc:
        log(f"[serve] connection from {addr} aborted: {exc!r}")
    finally:
        try:
            conn.close()
        except OSError:
            pass


def dispatch(req: dict, segment: str | None, stop_event: threading.Event) -> dict:
    cmd = req.get("cmd")
    if cmd == "ping":
        return {
            "ok": True,
            "models": [VOCALS_MODEL, OTHER_MODEL],
            "device": pick_device(),
            "segment": segment,
            "cache_dir": str(CACHE_DIR),
            "watch_pid": LIFESPAN.watch_pid,
            "idle_exit_minutes": round(LIFESPAN.idle_seconds / 60, 3) if LIFESPAN.idle_seconds else 0,
            "jobs_running": LIFESPAN.active_jobs,
        }
    if cmd == "separate":
        LIFESPAN.job_started()
        try:
            return handle_separate(req, segment)
        except Exception as exc:  # separation failures must never kill the service
            log(f"[error] separation failed: {exc!r}")
            log("[trace] " + traceback.format_exc().replace("\n", " | "))
            return {"ok": False, "error": str(exc)}
        finally:
            LIFESPAN.job_finished()
    if cmd == "stop":
        stop_event.set()
        return {"ok": True, "shutdown": True}
    return {"ok": False, "error": f"unknown command: {cmd!r}"}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=int(os.environ.get("STEMS_PORT") or DEFAULT_PORT),
                    help=f"listening port; the default ({DEFAULT_PORT}) is what makes one "
                         "engine per machine possible, and 0 asks the OS for a free one")
    ap.add_argument("--watch-pid", type=int,
                    default=int(os.environ.get("STEMS_WATCH_PID") or 0) or None,
                    help="stop when this process (the app that started the first shim) is gone")
    ap.add_argument("--idle-exit-minutes", type=float,
                    default=float(os.environ.get("STEMS_IDLE_EXIT_MINUTES", IDLE_EXIT_MINUTES)),
                    help="stop after this long with no request at all (0 = never)")
    ap.add_argument("--segment", default=None, help="start:end seconds, for fast testing")
    ap.add_argument("--once", default=None, help="separate this file and exit (no server)")
    ap.add_argument("--mirror-stdio", action="store_true",
                    help="append stdout/stderr to stdstream.log instead of using them; the shim "
                         "passes this because it starts the service with no handles at all")
    args = ap.parse_args()

    install_safe_streams(args.mirror_stdio)
    CACHE_DIR.mkdir(parents=True, exist_ok=True)
    log(f"[stdio] {describe_streams()}")

    if args.once:
        start = end = None
        if args.segment:
            a, b = args.segment.split(":")
            start, end = float(a), float(b)
        path = pathlib.Path(args.once)
        result = separate_track(path, start, end, CACHE_DIR / cache_key(path, args.segment))
        print(json.dumps(result, indent=2))
        return 0

    lifespan = Lifespan(watch_pid=args.watch_pid, idle_minutes=args.idle_exit_minutes,
                        keep=KEEP_ENGINE)
    log(f"[serve] starting: {lifespan.describe()}")

    stop_event = threading.Event()
    try:
        serve(args.host, args.port, args.segment, stop_event, lifespan)
    except KeyboardInterrupt:
        stop_event.set()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
