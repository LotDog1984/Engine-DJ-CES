# The stems-processor protocol, as measured

Engine DJ spawns one `stems-processor.exe` per stem job and talks to it over two pipes: the app
writes the mix to the process's **stdin**, and reads the stems from its **stdout**. Both directions
are line-oriented messages in `key=value` form, each message terminated by a blank line (`\n\n`);
audio payloads follow their message as raw little-endian float32.

Measured on 2026-10-08 from a real job (shim capture of the stock processor, `captures/20261008-194448/`),
and on 2026-10-09/10-11 from the app side (`tests/pipe-trace/`, `tests/pipe-read-trace/`). The stock
processor is zplane Stems Pro 1.1.0 (`bin/stems-processor.exe`); the custom engine's shim
([shim/StemsShim.cs](shim/StemsShim.cs)) speaks this protocol.

*Cleanup note (2026-10-11): the capture and probe material named below (`captures/`, the old
`tests/` probe dirs and scripts) was removed from the lab; only the two harness scripts named in
README-ENGINE-SWITCH.md remain. The measurements stand.*

## Transcript of one session

```
proc -> app   preparing=initialising\ntime=...\nsession=<token>\n\n
app  -> proc  version=1.6.0\ntime=...\nnumChannels=2\nsampleRate=44100\nmaxBlockSize=1024\n
              highQuality=1\nresidual=0\nnumThreads=3\nsession=<token>\n\n
proc -> app   preparing=started\n\n
proc -> app   preparing=done\nnumReturnChannels=8\n\n
              ... the app streams the whole mix, at real time ...
app  -> proc  action=block\nnumSamples=N\n\n   + N frames of float32 stereo, as PLANES (N = maxBlockSize)
proc -> app   returnFrames=0\n\n                 (once per input block, while buffering)
app  -> proc  action=done\n\n                    (then the app closes stdin)
              ... separation ...
proc -> app   returnFrames=N\n\n                 + the payload below, in blocks
proc -> app   done=true\n\n                      (the end of the session)
```

Notes from the captures:

* The app hands the track over far faster than real time in the custom/shim path (87 MB in ~2 s),
  but the stock processor's session runs at roughly 1× while the app streams in.
* The app reads the processor's stdout in **small reads, about 1 KB** - the 2026-10-09 capture
  stored 283,672 reads for 273.6 MB, 964 bytes on average. Anything that filters reads by size
  ("only copy reads >= 1024 bytes") silently loses the whole return stream.
* `numReturnChannels=8` means four stereo stems. `residual=0` and `highQuality=1` are what the app
  asks for; the payload carries four stems regardless.

## Both payloads are planar

In **both** directions a message carries one plane per channel - all of channel 0 for the block, then
all of channel 1 - not interleaved frames. The return side is shown first because it was measured
first; the input side ([below](#the-input-payload-is-planar-too)) turned out to be the same layout,
and misreading it is what made every custom render sound pitched.

### The return payload is planar

One `returnFrames=N` message carries **eight planes of N frames**, not N interleaved frames of eight
channels:

```
plane 0: frames 0..N-1 of channel 0     (stem pair 0, left)
plane 1: frames 0..N-1 of channel 1     (stem pair 0, right)
plane 2: frames 0..N-1 of channel 2     (stem pair 1, left)
...
plane 7: frames 0..N-1 of channel 7     (stem pair 3, right)
```

That is the layout an audio plugin's planar `float**` block has, and it is what `maxBlockSize=1024`
describes. It matters: the two readings differ only in byte order, so both produce eight finite
float streams, and Engine DJ cannot be asked which one it wants.

It was settled against the music. The four stems must sum back to the mix the app sent, and that mix
is a decode of the source track. On the 2026-10-09 capture, which is the **stock** processor's own
return for one full job (`Test 1 stems.m4a`, 193.747 s, live install on stock at the time -
`switch-log.txt` shows stock from 10-09 19:53 to 10-10 20:32):

| reading | returned frames | stems summed vs source |
|---|---:|---|
| **planar** | 8,544,256 = the source's own frame count | **L +0.998, R +0.998** |
| interleaved | 8,544,256 | L +0.002, R +0.002 |

Re-run it: `.venv/Scripts/python.exe tests/scan-return-frames.py tests/pipe-trace/20261009-235036 --source "…\Test 1 stems.m4a"`
prints both readings and the frame delta.

## The four pairs, by measurement

Same capture, whole-track band energy per pair - nothing here is assumed from a convention:

| pair | channels | <200 Hz | 200-2000 Hz | >2 kHz | L-R corr | RMS (median / min) | reads as |
|---|---:|---:|---:|---:|---:|---:|---|
| 0 | 0,1 | 0.005 | 0.868 | 0.127 | 0.72 | 0.095 / **0.0002** | vocals (mid-heavy, has silent stretches) |
| 1 | 2,3 | **0.997** | 0.002 | 0.001 | **0.98** | 0.066 / 0.018 | bass (sub-bass only, near-mono, never silent) |
| 2 | 4,5 | 0.960 | 0.024 | 0.017 | 0.95 | **0.142** / 0.010 | drums (loudest, carries the transients and top end) |
| 3 | 6,7 | 0.183 | 0.807 | 0.010 | **0.37** | 0.054 / 0.029 | other (wide mid, the instrumental bed) |

So the wire order is **vocals, bass, drums, other**. Independently, the four decoded stems are
distinct (1 s envelope correlation 0.13-0.51 between pairs, never 1.0), and they sum to the source at
+0.998 with zero frame delta - a complete, sample-aligned, stock render.

## Capturing a return stream

```
.venv/Scripts/python.exe tests/pipe-read-trace.py --seconds 900     # attach, then run a job in Engine DJ
.venv/Scripts/python.exe tests/scan-return-frames.py tests/pipe-read-trace/<session> \
    --source "<the track>" --stems engine/stock/<session>          # decode + write the four stems
```

The agent ([tests/pipe-read.js](tests/pipe-read.js)) finds the processor's stdout pipe
(`CreatePipe` + `CreateProcessW`'s `STARTUPINFOW.hStdOutput`) and copies **every** read of it, of any
size, sync or overlapped. The decode is exact rather than heuristic: a header is only accepted where
the previous message ended, so a parse that reaches `done=true` (11 bytes before the end of the
file, in the 273,576,923-byte capture) cannot be a coincidence.

### The input payload is planar too

Measured 2026-10-11, after every custom render turned out to sound an octave high. The shim wrote
the mix it collected as interleaved frames; the app had sent planes. That reading does not lose
samples - it interleaves the two planes into each other, so with a 1024-frame block every written
channel holds every second sample of one plane for 512 frames, then every second sample of the other
plane for 512 frames. The result is the same track, the same length, and one octave up: exactly the
complaint. It survived so long because nothing about it is silent or obviously broken - it is music,
just at the wrong pitch, and only a comparison against the source track shows it.

Settled on a real job's own bytes: `Test 1 stems.m4a` (193.747 s) as the shim wrote it versus the
same bytes reassembled in 1024-frame planes, both scored against a plain ffmpeg decode of the
source. That capture was `engine/sessions/20261008-224258-717/mix.wav`, kept as
`engine/references/test1-app-stream-as-old-shim-wrote.wav` now that sessions are pruned:

| reading of the captured bytes | corr vs source | low-band peak |
|---|---:|---:|
| as the shim wrote it (interleaved) | +0.0508 | 90.00 Hz (source: 49.88) |
| reassembled as planes, 1024-frame blocks | **+1.0000 at lag 0** | **49.88 Hz**, identical |

The correlation is the whole answer: the app's own bytes reproduce the source file exactly once the
planes are put back in order. Nothing else in the chain was wrong - the decoder, the engine and the
source file were all fine, and the track's own frame count (8,544,256) never changed.

Re-run it: `.venv/Scripts/python.exe tests/planar-check.py <mix.wav> <source.wav>` prints the same
comparison, a block-size sweep (1024 is the app's `maxBlockSize` and the only size that fits
exactly), and `--write` to lay the repaired stream down as a WAV.

## What the shim does now

[shim/StemsShim.cs](shim/StemsShim.cs) de-planarises each `action=block` payload as it arrives, so
`engine/sessions/<stamp>/mix.wav` is the app's stream in ordinary interleaved frames, and it answers
with **eight planes per message** in the measured pair order `vocals, bass, drums, other`.
[tests/HostSim.cs](tests/HostSim.cs) speaks the same layout in both directions, so a replay through
it exercises the real byte order.

Verified 2026-10-11 on a 30 s excerpt and then on the full `Test 1` stream captured above, replayed
through the shim into the engine:

```
.venv/Scripts/python.exe tests/verify-shim-session.py \
    --session engine/sessions/<stamp> --source <source.wav> --returned <stems8.wav>
```

| what was measured | before | after |
|---|---:|---:|
| `mix.wav` vs the source track | +0.05, peak 90.00 Hz | **+1.0000 at lag 0**, peak 49.88 Hz |
| the four returned pairs summed vs the source | - | **+0.9969 at lag 0** |
| pair 1's energy below 200 Hz | - | 0.999 (the bass slot) |

The one thing no capture can settle is still the *names*: the pair order above is the app's byte
order, and the names are read off the spectra in the table. If a stem ever lands in the wrong slot it
is a one-line change (`ChannelOrder` in [shim/StemsShim.cs](shim/StemsShim.cs)).

## Disk: what a job leaves behind

A render used to leave two large things behind for good, because nothing ever removed them:

| what | per 193 s track | who removes it now |
|---|---:|---|
| `engine/cache/<key>/_tmp/` - the models' intermediate render | ~196 MB | the engine, as the job ends (`free_scratch` in [engine/engine_service.py](engine/engine_service.py), success or failure) |
| `engine/sessions/<stamp>/mix.wav` - the shim's copy of the app's stream | 62-84 MB | the shim, keeping only the newest 3 (`PruneSessions`, `STEMS_KEEP_SESSIONS` overrides) |
| `engine/cache/<key>/` - the four float32 stems | ~264 MB | nothing: this is the render, and it is what makes a repeat job instant |

The scratch deletion cannot affect a later job: a cached job is answered from `manifest.json` and
the four stems alone (checked by removing one job's `_tmp` and asking the engine for that track
again - `cached: true`, all four stems present). The session copies are the shim's own, and every
capture kept for the record in `engine/references/` survives pruning.
