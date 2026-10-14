"""Per-stem level audit: a render's stem levels against the mix, stem by stem, in dBFS.

Written for the vocals-level question ("vocals sit lower than drums, bass and melody"): Engine
DJ's own processor and our cascade have both been rendered for the same track, so the two can be
put side by side in dBFS per stem, on the same window, against the same source.

It also reports whether a render is additive - the four stems summing back to the mix - because
that is what makes the app's default four-stem playback identical to the original, and because a
render that is *not* additive has per-stem gains baked in by whoever made it.

A render separated from a segment of the mix is shorter than the mix, so it carries its own start
offset in the mix's time base: NAME=DIR@SECONDS (a whole-file render needs no offset).

    .venv/Scripts/python.exe tests/stem-level-audit.py \
        --source engine/references/source-test1.wav \
        --render stock=engine/stock/20261009-235036 \
        --render custom=engine/cache/<key>@60 \
        --start 60 --end 120
"""
from __future__ import annotations

import argparse
import pathlib
import sys

import numpy as np
import soundfile as sf

STEM_NAMES = ("vocals", "drums", "bass", "other")


def db(x: float) -> float:
    return 20.0 * float(np.log10(max(x, 1e-12)))


def rms(x: np.ndarray) -> float:
    return float(np.sqrt((x.astype(np.float64) ** 2).mean()))


def peak(x: np.ndarray) -> float:
    return float(np.abs(x).max()) if x.size else 0.0


def read_window(path: pathlib.Path, start: float | None, end: float | None) -> np.ndarray:
    """(frames, channels) float64 for the requested time window."""
    info = sf.info(str(path))
    first = int(start * info.samplerate) if start else 0
    frames = -1
    if end:
        frames = int(end * info.samplerate) - first
    data, _ = sf.read(str(path), start=first, frames=frames, dtype="float64", always_2d=True)
    return data


def load_render(directory: pathlib.Path, start, end, offset: float) -> dict[str, np.ndarray]:
    """The render's stems for the window, in the render's own time base."""
    stems = {}
    for name in STEM_NAMES:
        path = directory / f"{name}.wav"
        if not path.exists():
            raise SystemExit(f"{directory}: no {name}.wav")
        stems[name] = read_window(path,
                                  None if start is None else start - offset,
                                  None if end is None else end - offset)
        if stems[name].shape[0] == 0:
            raise SystemExit(f"{path}: window {start}-{end}s is empty for this render - pass "
                             f"@{offset:g} with the source second the render starts at")
    return stems


def table(title: str, stems: dict[str, np.ndarray], mix_rms: float) -> dict[str, float]:
    print(f"\n{title}")
    print(f"  {'stem':8} {'rms dBFS':>9} {'peak dBFS':>10} {'rms vs mix':>11} {'share':>7}")
    levels = {}
    total = sum(rms(a) ** 2 for a in stems.values())  # energy sum of the four stems
    for name in STEM_NAMES:
        level = rms(stems[name])
        levels[name] = level
        share = 100.0 * level ** 2 / total if total else 0.0
        print(f"  {name:8} {db(level):9.2f} {db(peak(stems[name])):10.2f} "
              f"{db(level / mix_rms):+11.2f} {share:6.1f}%")
    return levels


def additivity(label: str, stems: dict[str, np.ndarray], mix: np.ndarray) -> None:
    """Does the sum of the stems reproduce the mix? 0 dB means yes, -X dB means an X dB error."""
    summed = sum(stems.values())
    error = mix - summed
    message = (f"{label}: sum vs mix = {db(rms(error) / rms(mix)):+.2f} dB "
               f"(peak error {db(peak(error)):.2f} dBFS)")
    summed_rms, mix_rms = rms(summed), rms(mix)
    message += f", sum level {db(summed_rms / mix_rms):+.2f} dB vs mix"
    print("  " + message)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--source", required=True, type=pathlib.Path,
                    help="the mix, i.e. what the four stems should add up to")
    ap.add_argument("--render", action="append", default=[], metavar="NAME=DIR[@SECONDS]",
                    help="a directory holding vocals/drums/bass/other.wav, optionally with the "
                         "source second it starts at; repeatable")
    ap.add_argument("--start", type=float, default=None)
    ap.add_argument("--end", type=float, default=None)
    args = ap.parse_args()

    window = f"{args.start:g}-{args.end:g}s" if args.start is not None or args.end else "whole file"
    mix = read_window(args.source, args.start, args.end)
    mix_rms = rms(mix)
    print(f"source  {args.source}  ({window}, {mix.shape[0]} frames @ "
          f"{sf.info(str(args.source)).samplerate} Hz)")
    print(f"mix     rms {db(mix_rms):+.2f} dBFS, peak {db(peak(mix)):+.2f} dBFS")

    levels: dict[str, dict[str, float]] = {}
    for spec in args.render:
        name, _, directory = spec.partition("=")
        if not directory:
            raise SystemExit(f"--render needs NAME=DIR, got {spec!r}")
        directory, _, offset = directory.partition("@")
        offset_s = float(offset) if offset else 0.0
        stems = load_render(pathlib.Path(directory), args.start, args.end, offset_s)
        title = f"{name}  ({directory}{'' if not offset_s else f', from {offset_s:g}s'})"
        levels[name] = table(title, stems, mix_rms)
        additivity(name, stems, mix)

    if len(levels) == 2:
        first, second = list(levels)
        print(f"\n{second} - {first} (dB per stem; positive = {second} is louder)")
        for name in STEM_NAMES:
            a, b = levels[first][name], levels[second][name]
            print(f"  {name:8} {db(b / a):+7.2f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
