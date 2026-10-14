"""Separate a track into stems with a chosen model.

Examples:
  python separate.py --input "E:/path/track.mp3" --model htdemucs_ft --segment 30:75
  python separate.py --input track.wav --engine audio-separator --model vocals_mel_band_roformer

Outputs <outdir>/<model>/<track>/ with one WAV per stem plus mix.wav (the exact
input excerpt, so every model is compared on identical audio) and manifest.json.
"""
from __future__ import annotations

import argparse
import json
import os
import pathlib
import re
import subprocess
import sys
import time

os.environ.setdefault("PYTHONUTF8", "1")

# A console program started by a process that has no console gets a console of its own, and on
# Windows 11 the default terminal host opens that as a visible window. The engine service runs
# without a window on purpose (see StartOwnProcess in shim/StemsShim.cs), so audio-separator.exe -
# a console program - would put a terminal window on screen for every track. CREATE_NO_WINDOW runs
# it with a console that has no window; its output still goes to a file of its own, see
# _child_output(). Measured 2026-10-14 on a job in progress: this window was titled
# `.venv\Scripts\python.exe`, the launcher the engine itself is started through.
CHILD_FLAGS = {"creationflags": subprocess.CREATE_NO_WINDOW} if os.name == "nt" else {}


def ensure_ffmpeg() -> str | None:
    """Make an ffmpeg binary reachable for engines that shell out to it."""
    try:
        import imageio_ffmpeg
    except ImportError:
        return None
    exe = imageio_ffmpeg.get_ffmpeg_exe()
    target_dir = pathlib.Path(__file__).resolve().parent / ".ffmpeg"
    target_dir.mkdir(exist_ok=True)
    link = target_dir / "ffmpeg.exe"
    if not link.exists():
        link.write_bytes(pathlib.Path(exe).read_bytes())
    os.environ["PATH"] = str(target_dir) + os.pathsep + os.environ.get("PATH", "")
    return str(link)


def load_audio(path: pathlib.Path, start: float | None, end: float | None, target_sr: int):
    """Decode, trim, resample. Returns (torch float32 [channels, samples], sr)."""
    import numpy as np
    import soundfile as sf
    import torch
    import torchaudio

    info = sf.info(str(path))
    sr = info.samplerate
    start_frame = int(start * sr) if start else 0
    end_frame = int(end * sr) if end else info.frames
    n = end_frame - start_frame
    data, sr = sf.read(str(path), start=start_frame, frames=n, dtype="float32", always_2d=True)
    wav = torch.from_numpy(np.ascontiguousarray(data.T))  # (channels, samples)
    if sr != target_sr:
        wav = torchaudio.functional.resample(wav, sr, target_sr)
        sr = target_sr
    if wav.shape[0] == 1:
        wav = wav.repeat(2, 1)
    return wav, sr


def run_demucs(wav, sr, model: str, device: str, shifts: int, jobs: int):
    from demucs.api import Separator

    sep = Separator(model=model, device=device, shifts=shifts, jobs=jobs, progress=True)
    model_sr = getattr(sep, "samplerate", None) or getattr(sep, "sample_rate", 44100)
    if sr != model_sr:
        import torchaudio
        wav = torchaudio.functional.resample(wav, sr, model_sr)
        sr = model_sr
    _, out = sep.separate_tensor(wav, sr=model_sr)
    return {k: v.cpu() for k, v in out.items()}, model_sr


def _child_output(tmpdir: pathlib.Path):
    """Where a spawned engine's output should go.

    Standard handles are borrowed, not owned: the resident service inherits a pipe from whoever
    started it (the shim), and when that process exits the handles break. On Windows writing to
    such a handle fails with EINVAL(22), and a child spawned with it can fail outright - which is
    exactly how a perfectly healthy engine failed the second job of a session. So a non-interactive
    parent hands the child a file of its own instead of its own std handles.
    """
    if sys.stdout.isatty():
        return None, None
    path = tmpdir / "separator.log"
    handle = path.open("wb")
    return handle, subprocess.STDOUT


def run_audio_separator(wav, sr, model: str, device: str, tmpdir: pathlib.Path):
    """audio-separator needs files on disk; we hand it the excerpt as WAV."""
    import soundfile as sf
    import numpy as np

    tmpdir.mkdir(parents=True, exist_ok=True)
    in_wav = tmpdir / "input.wav"
    sf.write(str(in_wav), np.ascontiguousarray(wav.numpy().T), sr, subtype="FLOAT")
    out_dir = tmpdir / "sep"
    out_dir.mkdir(exist_ok=True)
    cli = pathlib.Path(sys.executable).parent / "audio-separator.exe"
    model_dir = pathlib.Path(__file__).resolve().parent / "models"
    model_dir.mkdir(exist_ok=True)
    cmd = [str(cli), str(in_wav), "--model_filename", model, "--output_dir", str(out_dir),
           "--model_file_dir", str(model_dir), "--output_format", "WAV"]
    try:
        print(" ".join(cmd), flush=True)
    except OSError:
        pass  # a caller whose stdout is gone must not turn a diagnostic into a failure
    out, err = _child_output(tmpdir)
    # CREATE_NO_WINDOW only when the child's output is redirected to a file. A child that inherits
    # this process's *console* handles must not be given a console of its own: those handles are
    # then invalid inside it, and audio-separator dies with exit 1 and no message (measured
    # 2026-10-14 by running this function from a console). With the redirect there is nothing to
    # inherit, and the flag is exactly what keeps the window away from a windowless parent.
    flags = CHILD_FLAGS if out is not None else {}
    env = None
    if device and device.lower().startswith("cpu"):
        # audio-separator has no device flag and would pick the GPU itself; hiding the GPU from
        # the child process is how it is made to run on the CPU (STEMS_DEVICE=cpu). "-1", not an
        # empty string: on Windows an empty value leaves torch.cuda.is_available() true with zero
        # devices, which crashes the model's own device probe instead of selecting the CPU.
        env = dict(os.environ)
        env["CUDA_VISIBLE_DEVICES"] = "-1"
    try:
        subprocess.run(cmd, check=True, stdout=out, stderr=err, env=env, **flags)
    finally:
        if out is not None:
            out.close()
    import soundfile as sf
    import torch

    stems = {}
    for f in out_dir.glob("*.wav"):
        # audio-separator names outputs "<input>_(<stem>)_<model>.wav"
        m = re.search(r"\(([^)]+)\)", f.name)
        name = m.group(1).lower().replace(" ", "_") if m else f.stem
        if name == "instrumental":
            name = "no_vocals"
        data, _ = sf.read(str(f), dtype="float32", always_2d=True)
        stems[name] = torch.from_numpy(data.T)
    return stems, sr


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--input", required=True)
    ap.add_argument("--engine", default="demucs", choices=["demucs", "audio-separator"])
    ap.add_argument("--model", default="htdemucs_ft")
    ap.add_argument("--segment", default=None, help="start:end seconds, e.g. 30:75")
    ap.add_argument("--outdir", default="runs")
    ap.add_argument("--device", default=None)
    ap.add_argument("--shifts", type=int, default=1)
    ap.add_argument("--jobs", type=int, default=0)
    args = ap.parse_args()

    import numpy as np
    import soundfile as sf
    import torch

    ffmpeg = ensure_ffmpeg()
    device = args.device or ("cuda" if torch.cuda.is_available() else "cpu")
    start = end = None
    if args.segment:
        a, b = args.segment.split(":")
        start, end = float(a), float(b)

    src = pathlib.Path(args.input)
    tag = f"{start:g}-{end:g}s" if args.segment else "full"
    outdir = pathlib.Path(args.outdir) / args.model / f"{src.stem}__{tag}"
    outdir.mkdir(parents=True, exist_ok=True)

    print(f"[load] {src.name} segment={args.segment} ffmpeg={ffmpeg}", flush=True)
    wav, sr = load_audio(src, start, end, 44100)
    print(f"[load] {wav.shape[1]} samples @ {sr} Hz ({wav.shape[1] / sr:.1f}s) device={device}", flush=True)

    t0 = time.time()
    if args.engine == "demucs":
        stems, out_sr = run_demucs(wav, sr, args.model, device, args.shifts, args.jobs)
    else:
        stems, out_sr = run_audio_separator(wav, sr, args.model, device, outdir / "_tmp")
    elapsed = time.time() - t0

    rms = {}
    for name, tensor in sorted(stems.items()):
        arr = tensor.numpy()
        arr = arr.T if arr.shape[0] <= 8 and arr.shape[0] < arr.shape[1] else arr
        sf.write(str(outdir / f"{name}.wav"), np.ascontiguousarray(arr), out_sr, subtype="FLOAT")
        rms[name] = float(np.sqrt((arr.astype(np.float64) ** 2).mean()))
    mix = wav.numpy().T
    sf.write(str(outdir / "mix.wav"), np.ascontiguousarray(mix), sr, subtype="FLOAT")

    manifest = {
        "source": str(src),
        "model": args.model,
        "engine": args.engine,
        "device": device,
        "segment": args.segment,
        "sample_rate": out_sr,
        "seconds": round(wav.shape[1] / sr, 3),
        "elapsed_s": round(elapsed, 2),
        "realtime_factor": round(elapsed / (wav.shape[1] / sr), 3),
        "stems": {k: {"rms": round(v, 6), "shape": list(stems[k].shape)} for k, v in rms.items()},
    }
    (outdir / "manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    print(f"[done] {elapsed:.1f}s ({manifest['realtime_factor']}x realtime) -> {outdir}", flush=True)
    print(json.dumps(manifest["stems"], indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
