# Stem separation A/B — Engine DJ's zplane engine vs open models

Goal: keep the four-stem DJ layout but replace the separation algorithm, because the
algorithm shipped with Engine DJ is a mel-spectrogram U-Net from the pre-transformer era
(see `../bin/stems-processor.exe` → embedded ONNX model, details below).

Everything here runs on this machine (RTX 5070 Ti, Ryzen 7 9700X, 31 GB RAM).

## What the stock engine actually is

* `bin/stems-processor.exe` = zplane **Stems Pro 1.1.0** (build path
  `C:\janeway\workspace\tems-Pro_Stems-Pro-Windows_1.1.0@12\src\StemsProAlgorithm.cpp`),
  396 MiB of which **391.6 MiB is one embedded ONNX model** (PyTorch 2.3.1 export,
  ir_version 6, 489 nodes, 536 initializers, ~102M params).
* Graph: 154 Conv + 142 LeakyReLU + 75 BatchNorm + 11 AveragePool (down) + 6 Resize (up),
  `mel.melW`/`imel.melW` mel filterbank MatMuls, four parallel decoder heads
  (`conv_block7a..d`) → `after_conv2[8×32×1×1]`.
* I/O: `input[1,2,128,2048]` → `output[1,8,128,2048]` = 4 stems × stereo, in the
  mel-spectrogram domain (2048 bins ⇒ n_fft 4096, 128 frames per block).
* No waveform branch, no attention, no cross-stem refinement — this class of model is
  consistently a step behind modern hybrid/transformer separators, which matches the
  "stems sound bad" complaint.
* Extracted for inspection/benchmarking: `stems_model.onnx` (391.7 MiB) — **removed from the lab on
  2026-10-11** in the project cleanup. It is a 391.7 MiB extraction of the model embedded in
  `stems-processor.exe`, so re-extract it from that binary if the model itself needs re-measuring.

## What was run

Same audio for every model: `test/emms.mp3`, excerpt **30.0–75.0 s** (45.0 s, 44.1 kHz stereo).
`mix.wav` in each run directory is the exact decoded excerpt, so files are sample-aligned.

*Cleanup note (2026-10-11): the comparison inputs (`test/`), the helper scripts (`cascade.py`,
`analyze.py`), the run outputs under `runs/` and the `relay/` proxy described later in this
document were removed from the lab. The measurements below stand, but re-running or re-checking
them needs those inputs back.*

| run | stems | wall time | × realtime | device |
|---|---|---:|---:|---|
| `htdemucs_ft` (Demucs v4 fine-tuned) | vocals, drums, bass, other | 8.4 s | 0.19× | CUDA |
| `vocals_mel_band_roformer` (Kimberley Jensen) | vocals, instrumental | 6.0 s | 0.13× | CPU¹ |
| `cascade` = roformer vocals + htdemucs on `mix − vocals` | vocals, drums, bass, other | 10.6 s | 0.24× | CUDA + CPU¹ |

¹ ONNX Runtime could not load CUDA (`cublasLt64_13.dll` missing from its search path), so the
Roformer ran on CPU — already faster than htdemucs on GPU. Fixable by adding torch's `lib`
folder to `PATH` if you want it faster; not needed for these durations.

Commands (from `stems-lab/`, venv already set up):

```bash
.venv/Scripts/python.exe separate.py --input test/emms.mp3 --model htdemucs_ft --segment 30:75
.venv/Scripts/python.exe separate.py --input test/emms.mp3 --engine audio-separator \
    --model vocals_mel_band_roformer.ckpt --segment 30:75
.venv/Scripts/python.exe cascade.py  --input test/emms.mp3 --segment 30:75
.venv/Scripts/python.exe analyze.py runs --json runs/report.json
```

Drop `--segment` for a whole track. Listening pack: [`ab/`](ab) (mix + each model's stems).

## Measurements (single excerpt, no ground truth — proxies, not SDR)

Published SDR from the audio-separator model list (for reference):

| | vocals | drums | bass | other |
|---|---:|---:|---:|---:|
| htdemucs_ft | 10.8 | 10.0 | 12.0 | — |
| vocals_mel_band_roformer | **12.6** | — | — | — |

Local, on this excerpt:

| metric | htdemucs_ft | roformer | cascade |
|---|---|---|---|
| sum-of-stems vs mix error (RMS) | −33.1 dB | −35.8 dB | **−36.0 dB** |
| highest envelope correlation (any stem pair) | 0.112 (bass\|other) | −0.184 (vocals\|other) | 0.135 (vocals\|bass) |
| percussion bleed into vocals (drums' transients) | **+4.7 dB** | −10.4 dB | −10.4 dB |
| vocals HF share >6 kHz (mix = 0.270) | 0.414 | 0.344 | 0.344 |
| vocals RMS | −28.7 dB | −24.4 dB | −24.4 dB |

Reading:

* **htdemucs_ft leaks percussion into the vocals stem** here: vocals energy actually *rises*
  +4.7 dB during drum transients, and the vocals stem carries more high-frequency share
  (0.414) than the full mix (0.270) — cymbal/hat content sitting in the vocal.
* The **Roformer vocals are markedly cleaner** (energy *drops* −10.4 dB during drum hits),
  consistent with the published SDR gap (12.6 vs 10.8).
* The **cascade keeps the four-stem layout and is exactly transparent** (−36 dB
  reconstruction), so a DJ set that mixes all four stems back together sounds identical to
  the original track.

A second track (`test/angosound.mp3`, 0–30 s, htdemucs_ft) reproduced the same defect:
drums bleed into vocals at +2.0 dB and the vocals stem's HF share is 0.544 — so the
percussion-in-vocals pattern is a property of the model, not of one excerpt.

Caveats: one 45 s excerpt per track, and my bleed/HF metrics are no-reference proxies.
Judge the remaining difference by ear from `ab/` before committing.

## Recommendation

Use the **cascade** when stem quality matters: Roformer for vocals (it is the weak point of
the stock engine and of plain htdemucs), htdemucs for drums/bass/other on the residual.
Cost is ~0.24× realtime, i.e. a 5-minute track in about 70 s on this GPU.

If you want a smaller machine footprint, `htdemucs_ft` alone is still a large step up from
the shipped engine — but the percussion bleed into vocals stays.

## Next step: putting it inside Engine DJ (not done yet)

1. **Relay capture** — a logging proxy is built and tested in [`relay/`](relay)
   (`Relay.cs`, `install-relay.ps1` / `uninstall-relay.ps1`). Installing it and running one
   short stem job in Engine DJ records the exact stdio handshake (the processor's side is
   known: `preparing=initialising` + `session=<token>`, then keys `numChannels`,
   `sampleRate`, `maxBlockSize`, `highQuality`, `numThreads`, host expects `numReturnChannels`).
   That transcript is what a drop-in replacement processor must satisfy.
2. **Drop-in replacement** — a small `stems-processor.exe` that speaks that protocol and
   shells out to the cascade. Reversible: original stays renamed on disk, no other files touched.
3. **Offline route** — generate stems ourselves and work out how Engine DJ stores them
   (`stm.db` in the library's `Database2`, per-track `isSsfileAvailable` flag).

Not investigated yet: whether Engine DJ validates the component's signature/version, and the
exact STFT window/hop the vendor processor uses in front of its model.
