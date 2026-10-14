# Custom stem engine — installed, and what to check in the app

*Cleanup note (2026-10-11): the probe scripts and recordings named in this file (for example
`tests/HostSim.exe`, `tests/runB-stems8.wav`, `tests/compare-stem-renders.py`) were removed from
the lab; the two harness scripts in `tests\` remain.*

## Where it stands

Engine DJ's stems processor is now **the custom engine**, installed and active in your live
install:

| file in `%LOCALAPPDATA%\AIR Music Technology\EnginePrime\bin` | what it is |
|---|---|
| `stems-processor.exe` (24 KB, `41b30700…`) | the shim Engine DJ spawns; it speaks the host's protocol and answers with stems from the engine |
| `stems-processor.vendor.exe` (396 MB, `e416e195…`) | your original processor, byte-identical to how it shipped |
| `NNPredictionDispatcher_on.dll` | untouched |

The stock processor is kept **whole** and is the automatic fallback: if the engine is missing, the
shim re-executes it with the same arguments and Engine DJ behaves exactly as before. Nothing was
copied, rewritten or deleted.

Revert any time (Engine DJ closed):

```
cd C:\Users\Branko\Desktop\EnginePrime
powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine vendor
```

`-Engine status` prints which engine is active at any moment.

## The close-hang round (2026-10-14)

**Reported:** after stem separation on 12 tracks, Engine DJ would not close - "something is still
using the engine".

**Found, from the live lab's own evidence** (`C:\Users\Branko\Desktop\Engine-DJ-CES-master\stems-lab`,
which is where `engine.json` points):

* `engine/engine.log` for that batch has **two `[serve] listening` lines in the same second**
  (20:48:31, ports 59352 and 59353). A batch of shims starts in the same instant, every one of them
  saw "no engine.port yet", and each started a service of its own - two python processes with a full
  set of models, one of them never used again.
* Nothing stops a service. That log has **no `[serve] stopped`** and `engine.port` is still lying
  there: the services were killed, not stopped, and they would have outlived the app for ever.
* The blocker itself is handle inheritance. The shim starts the service, and .NET's `Process.Start`
  passes `bInheritHandles=TRUE` *and duplicates the parent's standard handles as inheritable for the
  child*. Measured with `tests\sandbox\Probe.cs` on 2026-10-14: with `HANDLE_FLAG_INHERIT` cleared on
  all three std handles (and read back as cleared), a child started through `Process.Start` still
  held the write end of the parent's stdout pipe - with redirected streams and without them, with
  `CreateNoWindow` on and off. So the engine held the app's session pipe open after the shim had
  exited, and Engine DJ waited for the end of a stream that never came.

**Fixed:**

* The shim creates the engine with `CreateProcess` and `bInheritHandles=FALSE` (`StartOwnProcess`),
  detached and with no stdio: it cannot hold, or even see, anything of the app's. The service is
  asked for `--mirror-stdio` so library output still lands in `engine\stdstream.log` (python answers
  `isatty() True` for three NULL handles on this machine - measured - so `isatty()` cannot decide).
* The service's lifetime is the app's: `--watch-pid <the app>` from the shim, plus an idle exit
  (60 min) for a service started by hand, plus `STEMS_KEEP_ENGINE=1` to disable both. It stops
  gracefully and says why.
* One engine per machine: the service prefers port 51917 and a loser exits after checking that an
  engine is answering there - without loading anything. The port file is only ever removed when it
  still holds that service's own port.

**Measured after the fix:** shim handles suite **9/9** (it fails on the old binary - that is the
regression test), service lifecycle **32/32**, concurrency **8/8**, delegation **12/12**, switch
**54/54**, and the end-to-end suite **10/10**: a real 4 s track separated through the real models
("[done] 7.1s (1.77x realtime)", non-silent stems for all 176 400 frames) while the app's pipe
reached end-of-file with that engine still resident.

**Still to do:** the live install and the lab it points at (`Engine-DJ-CES-master`) still hold the
old shim and the old service; re-run `-Engine custom` from the folder you want them served from.

## The vocals-level round (2026-10-14)

**Reported:** "on custom engine, vocals are a little bit more quietly then drums, bass and melody —
match volume level of vocals to track volume just as drums, bass and melody is matched".

**Measured, and the complaint was exact.** Test 1, 60-120 s, our render against the stock engine's
capture of the same window: drums +0.28 dB, bass +0.39 dB, other +0.52 dB — and **vocals −2.34 dB**.
Method and the full tables are in `COMPARE.md` ("Vocals level: the cascade was dropping the
under-estimate"); tools are `tests/stem-level-audit.py` and `tests/stem-vocals-metrics.py`.

**Fixed at the cause, with no gain knob.** The cascade separates `mix − roformer_vocals` with
htdemucs and then discarded htdemucs' own vocals head on that residual — which is exactly where a
roformer under-estimate ends up. It is a coherent copy of the vocal (+0.78 correlation with the
roformer stem, +0.014 with the drum stem), and adding it back puts the stem at the stock engine's
level (+0.04 dB) and 0.55 dB under the mix on frames where the vocals should equal the mix, against
3.39 dB without it (the stock engine's own is 1.18 dB under). Nothing else moves, the four stems'
sum lands closer to the mix, and it costs no extra compute: the head was already there.

`PIPELINE_VERSION` (part of the cache key) was bumped, so renders made by the older pipeline cannot
be served after this change.

Suites, all exit 0: engine service **32/32**, concurrency **8/8**, shim delegation **12/12**, switch
**54/54**, shim/engine handles **9/9**, end-to-end on real audio **11/11** (a new check there reads
the service log for the recovery), plus the new `tests/test-engine-vocals-level.py` **14/14**, which
stands the two model stages in with synthetic signals and fails 4 of its 14 checks on the pre-fix
code.

**Still needs the install step.** The engine that runs is the one in the lab `engine.json` points
at, so until the switch is re-run (`-Engine custom` from *this* repo, Engine DJ closed) the app keeps
using the older service — quieter vocals included.

## The second report, the same night (2026-10-14)

**Reported:** "I still hear the difference in volume levels from track and vocal stem ... I need you
to match volume level of vocals to track volume just as drums, bass and melody is matched. I
downloaded again from github and recreate fresh engine. Did you update the github repo with the
fix?"

**Nothing since 2026-10-12 was ever committed.** `git log` ends at `be1b4a8` (Oct 12) and that
commit is what `origin/master` holds, so the repo a fresh download pulls is the Oct 12 code — while
this working tree carries the whole run of fixes as *uncommitted* changes:

| file | uncommitted | what is in it |
|---|---:|---|
| `engine/engine_service.py` | +357 lines | the vocals recovery, one engine per machine, the app-tied lifetime, the queue and cache |
| `shim/StemsShim.cs`, `shim/stems-processor.exe` | +257 lines, 26624 → 29184 bytes | the close-hang fix: `bInheritHandles=FALSE`, stdout end-of-file while the engine lives |

The recreated engine therefore runs the **Oct 12** build: the live shim log says `custom mode:
engine installed at ...\Engine-DJ-CES-master\stems-lab` and that lab's `engine.log` has `[stage2]`
followed by `[done]` with **no `[stage3]`** — the recovery never runs there. That is the whole of
"still quieter": what is running is the pre-fix pipeline, on both counts (the level and the hang).

**The app's own stem files cannot be measured** (so this round audited renders, not the library).
`Music\Engine Library\Stems\<trackId> <uuid>.stems` is one 8-channel AAC MP4 per track — but the
payload is not readable: ffmpeg decodes 0.02-0.28 s of a 3-minute file and reports 2944 `Error
submitting packet to decoder`, 1408 `Reserved bit set`, 1096 `Prediction is not allowed in AAC-LC`.
Engine DJ only plays those through its own decoder, so the stems a listener hears have to be
reproduced with a render rather than read out of the library.

**Measured on the files you separate, not on a lab excerpt.** `tests/stem-song-level.py` renders a
window of any song through `engine_service.separate_track()` itself — once with the recovery and
once with `add_vocals_leftover()` disabled — and scores each stem on the frames where that stem is
alone in the mix (0 dB = the stem sits at the mix's level there). Titanium remix, 60-120 s:

| stem | rms before | rms after | change | alone-frames before | after |
|---|---:|---:|---:|---:|---:|
| vocals | −24.36 | −22.68 | **+1.68** | −4.20 | −2.30 |
| drums | −16.83 | −16.85 | −0.01 | −0.29 | −0.29 |
| bass | −15.33 | −15.34 | −0.00 | −0.50 | −0.48 |
| other | −19.52 | −19.51 | +0.01 | −4.67 | −4.48 |

Four stems' sum vs the mix: level −0.16 → **−0.00 dB**, residual −21.1 → −23.5 dB.

**And the leftover ~2 dB is not ours to remove.** An independent separator, `htdemucs_ft` on the
*full* mix, puts the same window's vocals at −22.60 dB and −2.52 dB on those alone-frames; our fixed
stem is −22.68 dB and −2.30 dB — i.e. within **0.08 dB** of the reference in level and *better* on
the alone-frames, with +0.961 correlation. Both models sit ~2 dB under the mix there because that is
what vocal separation does at these frames, not because the stem is quiet: drums and bass score
near 0 dB only because they are the loudest thing in the mix whenever they play. Adding a gain on
top of that would be a taste trim on the mix's own balance, and it would break the four-stems-sum
property measured above.

**Committed and pushed (`ec9008b`).** Verified as a *download*, not as a push: GitHub's ZIP of
`master` now contains `add_vocals_leftover`, `PIPELINE_VERSION = "3"`, `bInheritHandles` in the shim
source and the 29184-byte shim binary, so a fresh clone + first-run setup is current from here on.

**Installed, and verified through the installed paths.** Two files changed on the machine, each with
its previous version kept beside it:

| what | now | previous kept as |
|---|---|---|
| `%LOCALAPPDATA%\...\EnginePrime\bin\stems-processor.exe` | the 29184-byte build, md5 `572b05f2…` | `stems-processor.exe.pre-20261014-fix.bak` |
| `…\Engine-DJ-CES-master\stems-lab\engine\engine_service.py` | this repo's file, byte-identical | `engine_service.py.pre-vocals-fix.bak` |

`engine.json` still points at `Engine-DJ-CES-master\stems-lab`, and the resident engine that had the
old module in memory was retired (`{"cmd":"stop"}` → `[serve] stopped`, port file gone), so the next
stem job in the app starts the fixed service.

**Measured through those exact paths** — `tests/sandbox/e2e-oldshim.ps1`, a copy of the end-to-end
suite with `$Shim` pointing at the live install's binary and `$LabRoot` at that lab:

| pair | result |
|---|---|
| live shim **before** this round (Oct 12 binary) + fixed service | **6 passed, 5 failed** |
| live shim **as installed now** + fixed service | **11 passed, 0 failed** |

The five failures in the first row are one cause, not five: the Oct 12 shim never closes the app's
pipe, and the harness reads the payload only after end-of-file (`$payload = $(if ($eof) {...} else
{''})`), so "frames came back", `done=true` and "stem audio, not silence" all fall with the EOF check
they descend from. That is the close-hang bug reproducing on the installed pair, and it is the shim
side of this round, not the service side.

**One open point, not hidden:** on a 4 s synthetic tone the residual's vocals head came back a
different shape in one run and the recovery was skipped by design (`[stage3] no usable residual
vocals head`); on both real songs it ran (+1.68 dB Titanium, +2.39 dB Test 1), and the same 4 s tone
recovered on the next run. Short-input shapes are worth making usable (trim/pad instead of skip).

## What is already verified

The unknown from last round — Engine DJ's audio framing — came out of your capture and is now
implemented: settings in, `action=block` + float32 stereo in, `returnFrames` + 8-channel float32
out, `action=done` to finish. Measured through a compiled fake Engine DJ ([tests/HostSim.exe](tests/HostSim.exe)),
which drives the shim exactly like the app does:

| session | result |
|---|---|
| 5 s / 12 s / 15 s / 20 s excerpts | session completes, exit 0, four stems returned, frames in = frames out |
| stem → channel slot | byte-exact through the protocol (max sample difference 0.0) |
| the four stems sum back to the mix | −21.6 dB (15 s excerpt), −32.9 dB (60 s), −34.3 dB (98 s full track) |
| speed | 0.16–0.58× realtime (a 4-minute track separates in about 40–50 s) |
| the same audio again | served from `engine/cache/`, seconds |

Two real bugs were found by this work and fixed:

* **A subsequence job could fail silently.** The engine's models write progress to `stderr`, which is
  a pipe owned by whoever started it; once the shim exits, that pipe is dead and on Windows a write
  to it raises `EINVAL(22)` — which killed the *second* job of a session. The engine now never
  writes to inherited handles, and its children get files of their own.
* **A live engine could look dead.** The shim compared the health reply against the literal text
  `"ok":true` while the service writes `{"ok": true}` — so it spawned a duplicate service, waited,
  and fell back to the stock processor for no reason. It now matches the shape, not the spelling.

Suites, all exit 0: engine service **25/25**, switch **54/54** (the live-install check now
snapshots the real installs before the run and asserts they were left untouched, instead of
asserting the stock processor is still installed — a state the deliberately installed engine
breaks), shim delegation **12/12**, capture + fake Engine DJ **18/18**, plus a stems validator over
the returned 8-channel audio.

## What only the app can confirm

**One real `create stems` job.** Open Engine DJ, run create stems on a short track, and let it
finish. To see that it went through the custom engine:

* `stems-lab\engine\engine.log` gains `[separate]`, `[stage1]`, `[stage2]`, `[done] …x realtime`.
* the shim log written next to the processor (`…\EnginePrime\bin\stems-shim-*.log`) says
  `custom mode: engine installed …` and `engine produced stems: vocals, drums, bass, other`.

Then listen to the four stems. **The one convention the capture could not tell us** is which stereo
pair of the returned 8 channels the app expects to be which stem. The shim sends
`vocals, drums, bass, other` in that order — if a stem lands in the wrong slot, say which one and
it is a one-line change (`ChannelOrder` in [shim/StemsShim.cs](shim/StemsShim.cs)).

## Listening without a device

Everything the app received is on disk, so stems can be auditioned without exporting anywhere:

```
cd C:\Users\Branko\Desktop\EnginePrime\stems-lab
.venv\Scripts\python.exe stem-player\serve.py
```

Then open `http://127.0.0.1:8777/stem-player/index.html` (it is also what the Preview panel in this
thread shows). Every cached separation is listed newest first, and the four stems play together, in
sync, with mute and solo per stem and a level meter each — these are the same samples the processor
handed Engine DJ. The player streams from `engine/cache/` with HTTP Range support, so seeking is
instant. The four stems of a single job are also just WAV files you can double-click:
`engine\cache\<cache-key>\{vocals,drums,bass,other}.wav`.

## "Stems sound pitched on the SC4" — what the measurements say

The report was that every stem channel sounds highly pitched on the device. The audit is
re-runnable, and it passes 12/12 (exit 0):

```
.venv\Scripts\python.exe tests\verify-job-audio.py
```

| check | measurement |
|---|---|
| the stream Engine DJ sent | 44 100 Hz, 2 ch, **10 914 944 frames** = the source track's own frame count; no glitch at any 1024-frame boundary |
| the stream vs the source mp3 | envelope correlation **0.98**, identical timeline, identical length |
| pitch of the stream | chroma alignment best at **0 semitones** — no transposition |
| stems vs the stream | sum **−16.8 dB**, corr 0.990; the four stems are distinct |
| the `.stems` container | AAC LC (`ASC 12 00`), **44 100 Hz**, 247.478 s vs the track's 247.504 s, 644 785 bps — same structure, encoder and profile as the vendor-made files (id 29678 today, and the 2024/2025 ones) |
| the returned 8-channel audio | four distinct stereo pairs that sum back to the input (−16.8 dB, corr 0.990) |

**Correction:** an earlier version of this note claimed the vendor's channel layout had been confirmed by
those replay files. It had not. `tests/runB-stems8.wav` and its neighbours were produced with the engine
installed — their own summaries say `custom mode: engine installed … started the engine service` — so
they are the *custom* engine's output, and the **pair-to-stem convention is still unverified**, as the
section above says.

**The vendor binary cannot be driven outside the app** (measured today): pointed at directly by the
test harness in a sandbox, it exits within half a second without sending its handshake, and an earlier
attempt through the shim had the shim delegating to a copy of *itself* — 631 worker processes that had
to be killed by name. Any vendor-vs-custom comparison has to go through Engine DJ itself.

Nothing on the PC side shifts the rate or the pitch: the engine is handed the track at 44.1 kHz and
its own length, and returns sample-exact stems; the container declares that same rate and the right
duration.

**What the payload actually is** (measured 2026-10-08 on both renders, identical in both): one
`mp4a` track whose sample entry says 2 channels and whose AudioSpecificConfig is `12 00`
(channelConfiguration 0), 8 344 frames of 1 024 samples at 44.1 kHz = **193.724 s**, ~645 kb/s — and
the frames themselves carry private element tags plus prediction: ffmpeg reports `Prediction is not
allowed in AAC-LC` and `channel element 1.10 is not allocated`, faad adds `PCE shall be the first
element in a frame`.

So the audio inside a `.stems` file is readable **only by Engine DJ's own decoder**. ffmpeg, faad
(through VLC) and the browser's Media Foundation ([stem-player/probe.html](stem-player/probe.html))
all refuse it — the stock engine's render exactly as much as ours, so this is the format, not our
output. Plainly: the *samples* in either file cannot be measured or auditioned on this PC, and the
ear test has to happen on the SC4 or in Engine DJ's own player. What can be auditioned here is the
*pre-encode* audio — `engine/cache/<job>/` is what our engine handed the app — and the auditioner
now labels it and lists the two raw files with that verdict (`/api/renders`).

Tools from this round: [tests/compare-stem-renders.py](tests/compare-stem-renders.py) (two renders
side by side: rate, channels, frame count, ASC, frame sizes, decode verdict) and
[tests/decode-stems-payload.py](tests/decode-stems-payload.py) (re-wraps the frames as ADTS to try
profiles and channel configs — it documents *why* they cannot be decoded).

**The two-copies A/B is done** (2026-10-08, 22:43 and 22:44). Both copies decode to identical PCM
(same md5), so the engine was the only variable. Attribution comes from evidence, not memory:
`Stems/1 0b238a4f….stems` (22:43) is the **custom engine** — the shim log says
`custom mode: engine installed … session FFFB7B2F075E32C4`, `engine.log` shows
`[separate] … 193.7 s @ 44100 Hz`, cache `2d23e8df…`; `Stems/2 …stems` (22:44) is the **stock
processor** — no shim log for that session, `engine.log` ends 22:43:40, `switch-state.json` says
`activeEngine: vendor` at 22:44:06, and the live bin holds the 415 MB original. Engine DJ's own
`m.db` names them: id 1 `Test 1 New`, id 2 `Test 2 Old`.

Re-running the audit against *that* job (`--session …`, `--cache …`, `--source …`, `--stems …`):
**12/12, exit 0** — stream 44.1 kHz / 8 544 256 frames, no block glitches; stems full length and
distinct, summing at −17.2 dB; stream vs source envelope 0.9928 at the source's own length;
container 44 100 Hz, 193.724 s vs the source's 193.747 s. Chroma alignment of the source against
the app's stream, our vocals, our residual and the four summed: **+0 semitones** (drums and bass have
no dominant key — those rows are not pitch tests).

**Two tests that separate the remaining candidates:**

1. **Listen in the auditioner first** (it now labels the Test 1 job). If those samples sound right
   but the SC4 render does not, whatever changes the sound sits between our returned floats and the
   device.
2. **Play both files on the same SC4** — `Stems/1 …stems` (custom engine) against `Stems/2 …stems`
   (stock engine), same track, same input. Also pitched on the stock file -> it is Engine DJ's
   container/device path, not the separation. Ours alone -> it is our output, and the measurable
   difference to look at first is the 1.225 peak (headroom) noted below.

**Separate finding, worth knowing:** the stream Engine DJ sends is *not* a plain decode of the file
— same music, same timeline, but **−9.0 dB below 100 Hz and +17.9 dB at 15–20 kHz** against the mp3.
A second, different track measured the same way on 2026-10-08 (+11.2 dB at 15–20 kHz, −1.9 dB below
100 Hz), so the tilt is systematic rather than a property of one file. The stock processor is handed
the same input, so it is not a difference between us, but it does mean the separation runs on a
brighter, thinner signal than the file itself.

## Keep in mind

* **Peaks.** Two full-track runs produced a drums stem peaking at **1.12** and **1.225** in float
  (0.988 after mono-summing), above full scale. The protocol hands the app float32, so nothing is
  clipped on the way over — but if the app converts to integer when it writes its `.stems`
  container, or the device's output path does, that is a headroom decision I would rather make
  deliberately than discover in a club.
* **Job duration.** The app hands the track over far faster than real time — the 4-minute job's
  87 MB arrived in about two seconds — so a job takes essentially the separation time (32 s for
  that track, 0.13x realtime). The engine is brought up while the stream is arriving, so a cold
  machine is not a problem.
* **Verified on excerpts plus one full track.** Your first app job is the first end-to-end run
  against the real host, on your own library.
* The engine is a separate resident process ([engine/engine_service.py](engine/engine_service.py));
  it is started on demand and survives between jobs, which is what makes repeat jobs fast.
