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

Requests are one JSON object per line on a loopback socket; replies are one JSON object per
line. The port is written to engine.port next to this file so the shim can find it.

  {"cmd":"ping"}                                  -> models, device, cache stats
  {"cmd":"separate","path":"<audio file>"}        -> four stem WAV paths (cached by content hash)
  {"cmd":"stop"}                                  -> shuts the service down

Run it directly to watch it work:

  .venv/Scripts/python.exe engine/engine_service.py --once test/emms.mp3 --segment 0:15
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
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

PORT_FILE = HERE / "engine.port"
CACHE_DIR = HERE / "cache"
LOG_FILE = HERE / "engine.log"
STREAM_LOG = HERE / "stdstream.log"


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


def install_safe_streams() -> None:
    """Never let a library write to an inherited handle that may already be broken."""
    if sys.stderr is not None and sys.stderr.isatty():
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
    digest.update(f"{VOCALS_MODEL}|{OTHER_MODEL}|{segment or 'full'}|".encode())
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


def serve(host: str, port: int, segment: str | None, stop_event: threading.Event) -> None:
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    srv.bind((host, port))
    srv.listen(8)
    actual = srv.getsockname()[1]
    PORT_FILE.write_text(str(actual), encoding="utf-8")
    log(f"[serve] listening on {host}:{actual} (segment={segment or 'full'})")

    srv.settimeout(0.5)
    while not stop_event.is_set():
        try:
            conn, addr = srv.accept()
        except socket.timeout:
            continue
        except OSError:
            break
        threading.Thread(target=handle_connection, args=(conn, addr, segment, stop_event), daemon=True).start()

    try:
        srv.close()
    finally:
        try:
            PORT_FILE.unlink()
        except OSError:
            pass
    log("[serve] stopped")


def handle_connection(conn: socket.socket, addr, segment: str | None, stop_event: threading.Event) -> None:
    conn.settimeout(None)
    try:
        reader = conn.makefile("r", encoding="utf-8", newline="\n")
        writer = conn.makefile("w", encoding="utf-8", newline="\n")
        for line in reader:
            line = line.strip()
            if not line:
                continue
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
        }
    if cmd == "separate":
        try:
            return handle_separate(req, segment)
        except Exception as exc:  # separation failures must never kill the service
            log(f"[error] separation failed: {exc!r}")
            log("[trace] " + traceback.format_exc().replace("\n", " | "))
            return {"ok": False, "error": str(exc)}
    if cmd == "stop":
        stop_event.set()
        return {"ok": True, "shutdown": True}
    return {"ok": False, "error": f"unknown command: {cmd!r}"}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--segment", default=None, help="start:end seconds, for fast testing")
    ap.add_argument("--once", default=None, help="separate this file and exit (no server)")
    args = ap.parse_args()

    install_safe_streams()
    CACHE_DIR.mkdir(parents=True, exist_ok=True)

    if args.once:
        start = end = None
        if args.segment:
            a, b = args.segment.split(":")
            start, end = float(a), float(b)
        path = pathlib.Path(args.once)
        result = separate_track(path, start, end, CACHE_DIR / cache_key(path, args.segment))
        print(json.dumps(result, indent=2))
        return 0

    stop_event = threading.Event()
    try:
        serve(args.host, args.port, args.segment, stop_event)
    except KeyboardInterrupt:
        stop_event.set()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
