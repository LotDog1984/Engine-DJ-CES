"""Whose vocals stem has the right level? Level, cleanliness and a-cappella checks.

Candidates, same 60 s of Test 1, 60-120 s:
  stock              Engine DJ's own processor (the level the user hears as "right")
  roformer           our cascade's vocals stem without the residual's own vocals head
  roformer+leftover  with it - what engine_service.add_vocals_leftover() now delivers

Three checks that do not trust a candidate's own levels:
  a cappella   on frames where the accompaniment (that candidate's drums+bass+other) is quietest
               and the mix is not silent, vocals should equal the mix: 0 dB means the vocal
               element sits at the level the mix has it, negative means the stem under-estimates it
  transients   kick/snare frames taken from the STOCK drums stem: a clean vocal stem should not
               rise with them (positive dB = percussion bleeding into the vocals stem)
  HF share     share of energy above 6 kHz (mix is the reference; 2026-10-10 COMPARE.md numbers:
               htdemucs 0.414, roformer 0.344 on the emms excerpt)

2026-10-14 numbers, on this window: stock vocals -19.60 dBFS at -1.18 dB under the mix on those
quiet frames, roformer alone -21.94 dBFS (2.34 dB short) at -3.39 dB, roformer+leftover -19.58
dBFS at -0.56 dB - i.e. the recovered stem is closer to the mix than the stock engine's own, and
quieter on kick/snare frames than roformer alone (-5.0 dB vs -3.9 dB), so it adds vocal, not bleed.

Separates once and saves the candidate renders under tests/sandbox/vocals-leftover/ (kept out of
the repo), so re-running this for different metrics costs no GPU time.

    .venv/Scripts/python.exe tests/stem-vocals-metrics.py
"""
import pathlib
import sys

import numpy as np
import soundfile as sf

HERE = pathlib.Path(__file__).resolve().parent
LAB = HERE.parent
sys.path.insert(0, str(LAB))
import separate  # noqa: E402

START, END = 60.0, 120.0
VOCALS_MODEL = "vocals_mel_band_roformer.ckpt"
OTHER_MODEL = "htdemucs_ft"
OUT = LAB / "tests" / "sandbox" / "vocals-leftover"    # scratch renders; delete to re-separate
STOCK_DIR = LAB / "engine" / "stock" / "20261009-235036"
SOURCE = LAB / "engine" / "references" / "source-test1.wav"
STEMS = ("vocals", "drums", "bass", "other")


def arr(x) -> np.ndarray:
    """(channels, frames) numpy, from a torch tensor or a numpy array."""
    return x.detach().cpu().numpy() if hasattr(x, "detach") else np.asarray(x)


def db(x):
    return 20.0 * float(np.log10(max(abs(float(x)), 1e-12)))


def rms(x):
    return float(np.sqrt((arr(x).astype(np.float64) ** 2).mean()))


def frame_db(x, sr, ms=50.0):
    mono = arr(x).astype(np.float64)
    if mono.ndim == 2:
        mono = mono.mean(axis=0)
    size = max(int(sr * ms / 1000.0), 1)
    count = len(mono) // size
    blocks = mono[:count * size].reshape(count, size)
    return 20.0 * np.log10(np.sqrt((blocks ** 2).mean(axis=1)) + 1e-12)


def hf_share(x, sr, cutoff=6000.0):
    mono = arr(x)
    mono = mono.mean(axis=0) if mono.ndim == 2 else mono
    block = sr
    high = total = 0.0
    for i in range(0, max(len(mono) - block, block), block):
        power = np.abs(np.fft.rfft(mono[i:i + block] * np.hanning(block))) ** 2
        freq = np.fft.rfftfreq(block, 1.0 / sr)
        high += power[freq > cutoff].sum()
        total += power.sum()
    return float(high / total) if total else float("nan")


def corr(a, b):
    a, b = arr(a).reshape(-1).astype(np.float64), arr(b).reshape(-1).astype(np.float64)
    if a.std() == 0 or b.std() == 0:
        return float("nan")
    return float(np.corrcoef(a, b)[0, 1])


def load_file(path, start=None, end=None) -> np.ndarray:
    """(channels, frames) from a stem file, optionally windowed at 44.1 kHz."""
    first = int(start * 44100) if start else 0
    frames = -1 if end is None else int(end * 44100) - first
    data, _ = sf.read(str(path), start=first, frames=frames, dtype="float64", always_2d=True)
    return data.T


def write(path, x, sr):
    sf.write(str(path), np.ascontiguousarray(arr(x).T), sr, subtype="FLOAT")


def separate_once():
    """Run both stages as the service does, keeping the htdemucs vocals head the cascade dropped."""
    import torch

    separate.ensure_ffmpeg()
    mix_t, sr = separate.load_audio(SOURCE, START, END, 44100)
    mix = arr(mix_t)
    print(f"mix {mix.shape} @ {sr}  rms {db(rms(mix)):+.2f} dBFS (separating)")
    vstems, _ = separate.run_audio_separator(mix_t, sr, VOCALS_MODEL, "cuda", OUT / "_tmp" / "v")
    vocals = arr(vstems["vocals"])
    residual = mix - vocals
    inst_t, out_sr = separate.run_demucs(torch.from_numpy(np.ascontiguousarray(residual)), sr,
                                         OTHER_MODEL, "cuda", shifts=1, jobs=0)
    inst = {k: arr(v) for k, v in inst_t.items()}
    for label, vocal_dir in (("base", vocals), ("plus", vocals + inst["vocals"])):
        directory = OUT / label
        directory.mkdir(parents=True, exist_ok=True)
        write(directory / "vocals.wav", vocal_dir, out_sr)
        for name in ("drums", "bass", "other"):
            write(directory / f"{name}.wav", inst[name], out_sr)
    write(OUT / "leftover.wav", inst["vocals"], out_sr)
    return out_sr


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    sr = 44100
    if not (OUT / "leftover.wav").exists() or not (OUT / "base" / "vocals.wav").exists():
        sr = separate_once()
    else:
        print("reusing tests/sandbox/vocals-leftover renders (delete the folder to re-separate)")

    mix = arr(separate.load_audio(SOURCE, START, END, 44100)[0])
    base = {name: load_file(OUT / "base" / f"{name}.wav") for name in STEMS}
    plus = {name: load_file(OUT / "plus" / f"{name}.wav") for name in STEMS}
    leftover = load_file(OUT / "leftover.wav")
    stock = {name: load_file(STOCK_DIR / f"{name}.wav", START, END) for name in STEMS}

    print(f"mix rms {db(rms(mix)):+.2f} dBFS, stock vocals {db(rms(stock['vocals'])):+.2f} dBFS")
    print(f"leftover: {db(rms(leftover)):+.2f} dBFS ({db(rms(leftover) / rms(base['vocals'])):+.2f} "
          f"dB vs the roformer stem), corr with the roformer stem "
          f"{corr(base['vocals'], leftover):+.3f}, with the mix {corr(leftover, mix):+.3f}, "
          f"with the stock drums {corr(leftover, stock['drums']):+.3f}")

    candidates = {"stock": stock, "roformer": base, "roformer+leftover": plus}
    drum_levels = frame_db(stock["drums"], sr)
    transient = drum_levels >= np.quantile(drum_levels, 0.995)
    mix_levels = frame_db(mix, sr)

    print(f"\n{'candidate':18} {'vocals rms':>10} {'vs stock':>9} {'HF>6k':>6} "
          f"{'cappella':>9} {'transients':>11} {'quiet frames':>13}")
    for label, stems in candidates.items():
        voc = stems["vocals"]
        acc_levels = frame_db(stems["drums"] + stems["bass"] + stems["other"], sr)
        quiet = (acc_levels <= np.quantile(acc_levels, 0.10)) & (mix_levels > -45.0)
        vocals_frames = frame_db(voc, sr)
        cappella = float(np.median(vocals_frames[quiet] - mix_levels[quiet]))
        bleed = float(np.median(vocals_frames[transient]) - np.median(vocals_frames))
        print(f"{label:18} {db(rms(voc)):10.2f} {db(rms(voc) / rms(stock['vocals'])):+9.2f} "
              f"{hf_share(voc, sr):6.3f} {cappella:+9.2f} {bleed:+11.2f} {int(quiet.sum()):13d}")
    print(f"{'mix (reference)':18} {db(rms(mix)):10.2f} {'-':>9} {hf_share(mix, sr):6.3f}")
    print(f"transient frames: {int(transient.sum())} of {len(transient)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
