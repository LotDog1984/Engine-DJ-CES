"""The vocals stem carries the vocal, not only the part the roformer finds.

Engine DJ showed the custom engine's vocals a little quieter than drums, bass and melody, and a
measurement of a real render agreed: -2.34 dB against the stock engine's vocals while the other
three stems sat within 0.5 dB of it (tests/stem-level-audit.py; numbers in COMPARE.md).

The cause was in our cascade, not in the models. It separates `mix - roformer_vocals` with
htdemucs and then threw htdemucs' own vocals head on that residual away - and that head is where
the roformer's under-estimate ended up. On the real render it is a coherent copy of the vocal
(+0.78 correlation with the roformer stem, +0.01 with the drum stem), and adding it back puts the
stem at the stock engine's level (+0.04 dB) and *closer* to the mix on a-cappella frames than the
stock engine is (-0.56 dB vs -1.18 dB).

This suite stands the two model stages in with synthetic signals whose true answer is known, so the
level can be asserted exactly and no models, GPU or audio are needed: a "roformer" that hands back
76% of the vocal (-2.34 dB), and an "htdemucs" that finds the rest in the residual, as the real
pair do. It checks the recovered level, that the fix moves nothing but the vocals, and that the
four stems still sum to the mix.

usage: .venv\\Scripts\\python.exe tests\\test-engine-vocals-level.py
"""
import math
import os
import pathlib
import re
import sys
import tempfile

import numpy as np
import soundfile as sf
import torch

LAB = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(LAB))
sys.path.insert(0, str(LAB / "engine"))

TMP_HANDLE = tempfile.TemporaryDirectory(prefix="stems-vocals-level-")
TMP = pathlib.Path(TMP_HANDLE.name)

# The service reads these at import time, so point them at the scratch directory first.
os.environ["STEMS_LOG_FILE"] = str(TMP / "engine.log")
os.environ["STEMS_PORT_FILE"] = str(TMP / "engine.port")
os.environ["STEMS_CACHE_DIR"] = str(TMP / "cache")

import engine_service  # noqa: E402  (needs the sys.path entries and the env above)
import separate  # noqa: E402

CHECKS = []
SR = 44100
SECONDS = 3.0
UNDER_DB = -2.34                  # what the stub roformer misses, the real one's gap
F = 10 ** (UNDER_DB / 20.0)


def check(name, ok, detail=""):
    CHECKS.append(bool(ok))
    print(("PASS  " if ok else "FAIL  ") + name + (f"   [{detail}]" if detail else ""))


def db(x):
    return 20.0 * math.log10(max(float(np.sqrt((np.asarray(x, dtype=np.float64) ** 2).mean())),
                                 1e-12))


def tensor(x):
    """(2, samples) float32, the shape both models return."""
    return torch.from_numpy(np.stack([x, x]).astype(np.float32))


def signals():
    """A mix and its four true stems - synthetic, but with the parts of a real one."""
    t = np.arange(int(SR * SECONDS)) / SR
    rng = np.random.default_rng(7)
    stems = {
        "vocals": 0.30 * np.sin(2 * np.pi * 440.0 * t) + 0.05 * rng.standard_normal(t.size),
        "drums": 0.20 * np.sin(2 * np.pi * 60.0 * t) ** 8 * np.sin(2 * np.pi * 3000.0 * t),
        "bass": 0.25 * np.sin(2 * np.pi * 70.0 * t),
        "other": 0.15 * np.sin(2 * np.pi * 1200.0 * t) + 0.05 * rng.standard_normal(t.size),
    }
    return sum(stems.values()), {k: v.astype(np.float32) for k, v in stems.items()}


MIX, TRUTH = signals()


def stub_vocals(wav, sr, model, device, tmpdir):
    """Stage 1: a roformer that only finds F of the vocal, as the real one does."""
    return {"vocals": tensor(F * TRUTH["vocals"])}, sr


def stub_htdemucs(wav, sr, model, device, shifts, jobs):
    """Stage 2, on the residual the service handed it.

    Its vocals head is what stage 1 left behind - derived here from the residual itself, not from
    the truth, which is what the real model has to work from - and its other three heads are the
    true stems, which is what the cascade asks of htdemucs.
    """
    residual = wav.numpy()[0]
    leftover = residual - (TRUTH["drums"] + TRUTH["bass"] + TRUTH["other"])
    return {"vocals": tensor(leftover.astype(np.float32)),
            "drums": tensor(TRUTH["drums"]),
            "bass": tensor(TRUTH["bass"]),
            "other": tensor(TRUTH["other"])}, sr


def read(path):
    data, _ = sf.read(str(path), dtype="float64", always_2d=True)
    return data.mean(axis=1)


def main():
    print(f"a synthetic render whose true vocal level is known ({SR} Hz, {SECONDS:g} s)")

    mix_wav = TMP / "mix.wav"
    sf.write(str(mix_wav), np.stack([MIX, MIX], axis=1), SR, subtype="FLOAT")

    # --- the helper, on its own -------------------------------------------------------------
    vocals = tensor(F * TRUTH["vocals"])
    leftover = tensor((1.0 - F) * TRUTH["vocals"])
    combined, gain = engine_service.add_vocals_leftover(vocals, leftover)
    check("the helper reports the gain it added", gain is not None and abs(gain + UNDER_DB) < 0.01,
          f"{gain}")
    check("a missing residual head leaves the stem alone",
          engine_service.add_vocals_leftover(vocals, None)[0] is vocals)
    check("so does a shape the stage cannot have produced",
          engine_service.add_vocals_leftover(vocals, tensor(TRUTH["vocals"][:1000]))[0] is vocals)

    # --- the cascade, with the two stages stood in -------------------------------------------
    real_demucs, real_separator = separate.run_demucs, separate.run_audio_separator
    separate.run_audio_separator = stub_vocals
    separate.run_demucs = stub_htdemucs
    try:
        outdir = TMP / "render"
        result = engine_service.separate_track(mix_wav, None, None, outdir)
    finally:
        separate.run_demucs, separate.run_audio_separator = real_demucs, real_separator

    check("the cascade returned all four stems", sorted(result["stems"]) == ["bass", "drums",
                                                                             "other", "vocals"],
          str(sorted(result["stems"])))
    written = {name: read(path) for name, path in result["stems"].items()}
    check("every stem was actually written",
          all(pathlib.Path(path).exists() for path in result["stems"].values()))

    # What stage 1 alone found, for the comparison the user's complaint is about.
    stage1 = db(F * TRUTH["vocals"])
    recovered = db(written["vocals"])
    check("stage 1 alone is the ~2.3 dB short vocal the complaint was about",
          abs(stage1 - db(TRUTH["vocals"]) - UNDER_DB) < 0.01, f"{stage1 - db(TRUTH['vocals']):+.2f} dB")
    check("the delivered vocals stem is at the true vocal level",
          abs(recovered - db(TRUTH["vocals"])) < 0.05,
          f"{recovered - db(TRUTH['vocals']):+.3f} dB vs truth")
    check("which is the full under-estimate recovered",
          abs((recovered - stage1) + UNDER_DB) < 0.05, f"{recovered - stage1:+.3f} dB vs stage 1")

    for name in ("drums", "bass", "other"):
        delta = db(written[name]) - db(TRUTH[name])
        check(f"{name} is untouched by the recovery", abs(delta) < 0.01, f"{delta:+.4f} dB")

    summed = sum(written[name] for name in ("vocals", "drums", "bass", "other"))
    error = db(summed - MIX) - db(MIX)
    check("the four stems still sum to the mix", error < -60.0, f"sum vs mix {error:+.1f} dB")

    # --- cache and log ------------------------------------------------------------------------
    log = pathlib.Path(os.environ["STEMS_LOG_FILE"]).read_text(encoding="utf-8")
    line = next((item for item in log.splitlines() if "[stage3]" in item), "")
    found = re.search(r"vocals \+([\d.]+) dB recovered from the residual", line)
    check("the log records how much the recovery added",
          found is not None and abs(float(found.group(1)) + UNDER_DB) < 0.05, line)

    key_before = engine_service.cache_key(mix_wav)
    original = engine_service.PIPELINE_VERSION
    try:
        engine_service.PIPELINE_VERSION = original + "-test"
        key_after = engine_service.cache_key(mix_wav)
    finally:
        engine_service.PIPELINE_VERSION = original
    check("the cache key follows the pipeline, so an older render is never served",
          key_before != key_after, f"{key_before[:8]} vs {key_after[:8]}")

    failed = CHECKS.count(False)
    print()
    print(f"{len(CHECKS) - failed}/{len(CHECKS)} checks passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
