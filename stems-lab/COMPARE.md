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

## Vocals level: the cascade was dropping the under-estimate (2026-10-14)

**Reported:** on the custom engine, vocals sound a little quieter than drums, bass and melody.

**Measured** on Test 1, 60-120 s, both renders of that same window and the same source
([tests/stem-level-audit.py](tests/stem-level-audit.py); stock = the 2026-10-09 capture decoded per
stem, custom = a `--once` separation of the same window):

| stem | stock | custom before | custom after | after − stock |
|---|---:|---:|---:|---:|
| vocals | −19.60 | −21.94 | **−19.56** | **+0.04 dB** |
| drums | −17.06 | −16.74 | −16.78 | +0.28 |
| bass | −24.24 | −24.01 | −23.86 | +0.39 |
| other | −21.58 | −21.07 | −21.06 | +0.52 |
| sum vs mix | −24.0 dB error, −0.19 dB level | −14.5 dB, −0.69 dB | −17.1 dB, −0.15 dB | — |

That is the complaint exactly: the other three stems sat within 0.5 dB of the stock engine, and
vocals sat 2.34 dB under it.

**Cause, not a gain setting.** The cascade removes the roformer's vocals from the mix, hands
`mix − vocals` to htdemucs, and then threw htdemucs' **vocals** head on that residual away. That
head is where a roformer under-estimate goes, and the measurements say so
([tests/stem-vocals-metrics.py](tests/stem-vocals-metrics.py), same window):

| candidate | vocals rms | vs stock | HF share >6 kHz | a cappella | kick/snare frames |
|---|---:|---:|---:|---:|---:|
| stock | −19.60 | 0.00 | 0.021 | −1.18 dB | −1.77 dB |
| roformer alone | −21.94 | −2.34 | 0.017 | −3.39 dB | −3.93 dB |
| roformer + the residual's vocals head | **−19.58** | **+0.02** | 0.015 | **−0.55 dB** | −4.97 dB |
| mix (reference) | −13.02 | — | 0.010 | 0 dB | — |

* "a cappella" is the vocals stem's level against the mix on frames where that stem's own
  accompaniment is quietest and the mix is not silent — where a correct vocals stem should equal
  the mix. The stock engine's own vocals sits 1.18 dB under; ours alone was 3.39 dB under; with the
  head added it is 0.55 dB under, i.e. closer to the truth than the reference render is.
* The leftover is that signal, not bleed: correlation **+0.78** with the roformer stem, +0.487 with
  the mix, **+0.014** with the stock drum stem — and adding it leaves the vocals *quieter* on
  kick/snare frames (−4.97 dB vs −3.93 dB), with an HF share that moves toward the mix's 0.010.
* So no user-facing gain and no vendor level is copied: the energy was being thrown away, and it
  happens to land the stem on the stock render's level (+0.02 dB) because both are the same vocal.
* It costs nothing: htdemucs had already computed that head; it was dropped one line later. The
  four stems' sum also moves *closer* to the mix (last row), since the recovered energy is no
  longer missing from the render.

`PIPELINE_VERSION` in `engine/engine_service.py` is part of the cache key and was bumped, so a
render made by the older pipeline is never served after this change.

## The same vocal, on your own songs, against an independent separator (2026-10-14)

Test 1 is a lab excerpt; the report came from real tracks, so the same question was measured on one
of them. `tests/stem-song-level.py` renders a window through `engine_service.separate_track()`
itself — once with the recovery, once with `add_vocals_leftover()` disabled — and scores every stem
on the frames where that stem is alone in the mix (its own accompaniment at its quietest, mix not
silent). 0 dB means the stem sits at the mix's level on the frames where the mix is that stem.

Titanium (David Guetta & Morten Future Rave Remix feat. Sia), `--start 60 --end 120`:

| stem | rms before | rms after | change | alone vs mix, before | after |
|---|---:|---:|---:|---:|---:|
| vocals | −24.36 | −22.68 | **+1.68** | −4.20 | −2.30 |
| drums | −16.83 | −16.85 | −0.01 | −0.29 | −0.29 |
| bass | −15.33 | −15.34 | −0.00 | −0.50 | −0.48 |
| other | −19.52 | −19.51 | +0.01 | −4.67 | −4.48 |
| four stems' sum vs mix | level −0.16 dB, residual −21.09 dB | **−0.00 dB, −23.46 dB** | | | |

The recovered signal is −9.73 dB against the roformer's own vocals stem, correlation **+0.562**.

**An independent separator agrees with the result, not with the gap.** `htdemucs_ft` run on the
*full* mix (not on the residual) for the same window, in the same frame metric:

| candidate | rms | alone vs mix | HF share >3 kHz | spectral centroid |
|---|---:|---:|---:|---:|
| mix (the track) | −11.44 | 0.00 | 0.047 | 503 Hz |
| htdemucs_ft on the full mix | −22.60 | −2.52 | 0.271 | 2164 Hz |
| ours, stage 1 only | −24.36 | −4.20 | 0.265 | 2220 Hz |
| ours, fixed | **−22.68** | **−2.30** | 0.244 | 2028 Hz |

Our fixed vocals stem is **0.08 dB** from the reference separator's level and 0.22 dB *better* on the
alone-frames (correlation +0.961), so the ~2 dB it keeps under the mix is what vocal separation does
at those frames — both models show it — and not a level our pipeline is holding back. Drums and bass
sit near 0 dB only because they are the loudest element in the mix whenever they play. The remaining
levers, in order of honesty: install the fix (this table's "after" column), or accept a taste trim
on top of the mix's own balance, which necessarily pushes the four stems' sum above the mix where
the vocals play.

**Why the app's own stem files are not the reference here.** Engine DJ stores each separated track
as `<Music>\Engine Library\Stems\<trackId> <uuid>.stems`, an 8-channel AAC MP4 (channel order
vocals, bass, drums, other). It is not readable outside the app: ffmpeg gets 0.02–0.28 s out of a
3-minute file, with 2944 `Error submitting packet to decoder`, 1408 `Reserved bit set` and 1096
`Prediction is not allowed in AAC-LC` — the payload is not plain AAC-LC. So the four stems a
listener hears have to be reproduced by a render, which is what the tables above do.

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
