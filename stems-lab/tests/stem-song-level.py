"""Is every stem at the level the mix has it?  One stem at a time, on a window of a real song.

The report is a level ("vocals are quieter than drums, bass and melody"), so this measures one:
for each stem, the frames where the *other three* are at their quietest are the frames where that
stem is, in the mix, effectively alone - and on those frames a correctly levelled stem sits at the
mix's level (0 dB), while an under-estimate shows as negative dB. Drums, bass and other are the
control group: whatever they score, a vocals stem that scores clearly less is the reported bug.

It renders through `engine_service.separate_track()` itself rather than a copy of the cascade, so
the numbers are the pipeline the app runs, and it renders twice: with the vocals recovery (what the
2026-10-14 fix installed) and with `add_vocals_leftover()` disabled (what the engine did before).
The difference between the two vocals stems is the recovered signal - correlation with the
roformer's own vocals stem says whether it is a coherent copy of the vocal or just noise.

    .venv/Scripts/python.exe tests/stem-song-level.py \
        --source "C:\\Users\\Branko\\Desktop\\STEMS Test\\Custom\\<a song>.mp3" --start 60 --end 120
"""
from __future__ import annotations

import argparse
import pathlib
import sys
import time

import numpy as np
import soundfile as sf

HERE = pathlib.Path(__file__).resolve().parent
LAB = HERE.parent
sys.path.insert(0, str(LAB))
sys.path.insert(0, str(LAB / "engine"))
import engine_service  # noqa: E402   (the service's own code path, not a copy of it)
import separate  # noqa: E402

STEMS = engine_service.STEM_NAMES


def db(x: float) -> float:
    return 20.0 * float(np.log10(max(abs(float(x)), 1e-12)))


def rms(x) -> float:
    return float(np.sqrt((np.asarray(x, dtype=np.float64) ** 2).mean()))


def arr(x) -> np.ndarray:
    return x.detach().cpu().numpy() if hasattr(x, "detach") else np.asarray(x)


def frame_db(x, sr: int, ms: float = 50.0) -> np.ndarray:
    mono = arr(x).astype(np.float64)
    if mono.ndim == 2:
        mono = mono.mean(axis=0)
    size = max(int(sr * ms / 1000.0), 1)
    count = len(mono) // size
    blocks = mono[:count * size].reshape(count, size)
    return 20.0 * np.log10(np.sqrt((blocks ** 2).mean(axis=1)) + 1e-12)


def load(path) -> np.ndarray:
    data, _ = sf.read(str(path), dtype="float64", always_2d=True)
    return data.T


def render(source: pathlib.Path, start: float | None, end: float | None, outdir: pathlib.Path,
           recovery: bool = True):
    """One pass of the service's cascade, with the vocals recovery on or off."""
    saved = engine_service.add_vocals_leftover
    if not recovery:
        engine_service.add_vocals_leftover = lambda vocals, leftover: (vocals, None)
    try:
        t0 = time.time()
        info = engine_service.separate_track(source, start, end, outdir)
        elapsed = time.time() - t0
    finally:
        engine_service.add_vocals_leftover = saved
    return {name: load(info["stems"][name]) for name in STEMS}, info, elapsed


def solo_scores(stems: dict[str, np.ndarray], mix: np.ndarray, sr: int) -> dict[str, tuple[float, int]]:
    """Per stem: dB under the mix on the frames where that stem is alone, and how many frames."""
    mix_levels = frame_db(mix, sr)
    scores = {}
    for name in STEMS:
        accompaniment = sum(stems[other] for other in STEMS if other != name)
        own = frame_db(stems[name], sr)
        acc = frame_db(accompaniment, sr)
        count = min(len(own), len(acc), len(mix_levels))
        own, acc, reference = own[:count], acc[:count], mix_levels[:count]
        quiet = (acc <= np.quantile(acc, 0.10)) & (reference > -45.0)
        scores[name] = (float(np.median(own[quiet] - reference[quiet])), int(quiet.sum()))
    return scores


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--source", required=True, type=pathlib.Path)
    ap.add_argument("--start", type=float, default=60.0)
    ap.add_argument("--end", type=float, default=120.0)
    ap.add_argument("--out", type=pathlib.Path, default=HERE / "sandbox" / "song-level")
    args = ap.parse_args()

    print(f"{args.source.name}\n  window {args.start:g}-{args.end:g}s, pipeline "
          f"v{engine_service.PIPELINE_VERSION}, device {engine_service.pick_device()}\n")

    before, info_b, secs_b = render(args.source, args.start, args.end, args.out / "before", False)
    after, info_a, secs_a = render(args.source, args.start, args.end, args.out / "after", True)
    mix_t, sr = separate.load_audio(args.source, args.start, args.end, 44100)
    mix = arr(mix_t)
    print(f"  rendered twice: recovery off {secs_b:.1f}s, recovery on {secs_a:.1f}s "
          f"({info_a['seconds']:.1f}s of audio)\n")

    recovered = after["vocals"] - before["vocals"]
    corr = float(np.corrcoef(recovered.reshape(-1), before["vocals"].reshape(-1))[0, 1])

    s_before = solo_scores(before, mix, sr)
    s_after = solo_scores(after, mix, sr)

    print(f"  {'stem':8} {'rms before':>11} {'rms after':>10} {'change':>8} "
          f"{'alone vs mix: before':>21} {'after':>8}")
    for name in STEMS:
        b, a = rms(before[name]), rms(after[name])
        print(f"  {name:8} {db(b):11.2f} {db(a):10.2f} {db(a / b):+8.2f} "
              f"{s_before[name][0]:+21.2f} {s_after[name][0]:+8.2f}")
    for label, stems in (("before", before), ("after", after)):
        summed = sum(stems.values())
        error = mix - summed
        print(f"  {label:8} four stems sum vs mix: level "
              f"{db(rms(summed) / rms(mix)):+.2f} dB, residual {db(rms(error) / rms(mix)):+.2f} dB")

    print(f"\n  recovered signal: {db(rms(recovered) / rms(before['vocals'])):+.2f} dB against the "
          f"roformer's own vocals, correlation {corr:+.3f} (bleed would be ~0)")
    print(f"  vocals alone-frames: {s_before['vocals'][0]:+.2f} dB before, "
          f"{s_after['vocals'][0]:+.2f} dB after "
          f"({s_after['vocals'][1]} frames); the other three sit at "
          f"{np.mean([s_after[n][0] for n in STEMS if n != 'vocals']):+.2f} dB on average")
    return 0


if __name__ == "__main__":
    sys.exit(main())
