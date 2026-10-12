# Stems engine switch

A way to choose which stems processor Engine DJ uses, and a one-click way back to the
original.

## The switch app (nothing to type)

Double-click:

```
stems-lab\switch-app\StemsEngineSwitch.exe
```

It shows which engine is in use and gives you two buttons: **Use ORIGINAL stems** and
**Use CUSTOM stems**. The active one is marked "in use now". Switching back is the same
one click, and the log panel at the bottom shows exactly what happened, hashes included.

Options in the window:

* **Apply to** — `Engine DJ (live install)` is the real thing; `Project copy` is a spare
  copy for practising, and changing it affects nothing Engine DJ uses.
* **Force** — only needed if you want to switch while Engine DJ is still open.
* **Refresh** — re-reads the state.

There is also a **Set up Custom Engine (first run)** button along the top. A fresh clone is
deliberately small — no venv, no model, no ffmpeg binary — so the CUSTOM button has nothing to
run until the Python side exists. This one button builds all of it:

1. finds `uv` (beside the app, on `PATH`, or in the venv) and downloads the standalone
   `uv.exe` from Astral's GitHub releases if it is nowhere to be found;
2. makes sure Python 3.12 is available (`uv python install 3.12`);
3. rebuilds `.venv` from `requirements.txt` (`uv venv --seed` + `pip install`. The `--seed`
   is what puts pip inside the venv - a plain `uv venv` has none, and the install after it
   would stop with "No module named pip");
4. recreates `.ffmpeg\ffmpeg.exe` through `separate.ensure_ffmpeg()`, **before** the model
   step, because `audio-separator` raises if it cannot find `ffmpeg` on `PATH`;
5. checks the installed stack actually imports (`python -c "import ... audio_separator.separator"`)
   and names the missing module if it does not — a venv can install cleanly and still be
   unusable, and finding that out before the 900 MB download is worth one extra step;
6. downloads the vocal model with `audio-separator --download_model_only`;
7. pre-warms the demucs `htdemucs_ft` weights so the first real separation does not stall.

Every step is streamed into the log panel with what it is doing and why it failed, and the
whole run is safe to repeat — anything already installed is detected and skipped. When it
finishes it says **all set up** and leaves the engine choice to you: press **Use CUSTOM stems**
to switch, or **Use ORIGINAL stems** to stay on the stock processor. It never flips the engine
by itself.

The same setup without a window, for scripting a fresh clone:

```
switch-app\StemsEngineSwitch.exe --setup                  # log to stdout
switch-app\StemsEngineSwitch.exe --setup setup-log.txt    # and write it to a file
```

`--setup` exits `0` when everything is ready and `1` when a step failed.

The app is a front end for `engine-switch.ps1` below: every button runs that script and
shows its output, so the tested logic is the only thing that touches files. (The setup button is
the exception — it is this binary's own code, because upgrading a venv is not something the
switch script does.)

## The same thing from a terminal

```
powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1                      # status
powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine adopt       # learn the stock baseline
powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine custom      # use the custom engine
powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine vendor      # back to stock
```

Add `-WhatIf` to any of them to see what would happen without touching a file.

## Where things live

| file | role |
|---|---|
| `%LOCALAPPDATA%\AIR Music Technology\EnginePrime\bin\stems-processor.exe` | what Engine DJ actually spawns |
| `%LOCALAPPDATA%\...\bin\stems-processor.vendor.exe` | the original zplane processor, renamed in place, never copied or rewritten |
| `stems-lab\shim\stems-processor.exe` | the custom-slot binary (26 KB) that gets installed as the active processor |
| `stems-lab\switch-state.json` | which bytes are the baseline, and which engine is active |
| `stems-lab\switch-log.txt` | every action the switch took, with hashes |

Nothing else is touched, apart from one small file the switch writes itself: `engine.json`
beside the installed shim, holding `{"lab": "<the folder this script lives in>"}`. That is how
the installed shim finds the lab (see "First run on a fresh clone or a new PC"), and it is rewritten on
every `-Engine custom`. `NNPredictionDispatcher_on.dll` is deliberately left alone, and
the Engine Library is never written to.

## Reversal

`-Engine vendor` is the whole rollback: it deletes the small custom file and renames
`stems-processor.vendor.exe` back to `stems-processor.exe`. Because the original is only
ever *renamed* — never copied, overwritten or deleted — the rollback is instant and there
is no large restore to perform.

If you ever want a second safety net, the project's own
[bin/stems-processor.exe](../bin/stems-processor.exe) is a byte-identical copy of stock
(md5 `e416e195bfe3aa0aafe0759ebdfb2ca8`); it is the reference the test harness checks
against, so an accidental overwrite is always detectable.

## What the switch guarantees

* **Rename-only.** The stock bytes are never rewritten, so the original cannot be corrupted.
* **Hash-verified.** Every step is hashed before and after; a mismatch aborts instead of continuing.
* **Always leaves a processor behind.** If a step dies halfway, the layout is repaired so the app
  still finds a working binary rather than an empty slot.
* **Idempotent.** Running the same mode twice is a no-op.
* **Refuses to guess.** With no recorded baseline it will not assume a file is the original.
* **Won't run against the live install while Engine DJ is open** unless you pass `-Force`.

## The two-step first run

`adopt` records which bytes are the stock processor. It moves nothing:

```
-Engine adopt     -> records the hash, e.g. e416e195bfe3aa0aafe0759ebdfb2ca8
-Engine custom    -> renames the stock file to stems-processor.vendor.exe and copies the shim in
-Engine vendor    -> deletes the shim, renames the stock file back
```

## The custom slot

`stems-lab\shim\stems-processor.exe` (source: `shim\StemsShim.cs`) is the real engine: it speaks
the host's stdio protocol itself and hands each job to the resident service
(`engine\engine_service.py`), which runs the cascade measured in `COMPARE.md` — vocals from
`vocals_mel_band_roformer`, then `htdemucs_ft` on the residual, so the four stems still sum to
the mix.

The stock processor is no longer on the separation path, but it is still the safety net: if the
engine is missing, cannot start, or cannot serve the job, the shim delegates to
`stems-processor.vendor.exe` and Engine DJ gets exactly the old result instead of a broken set.
The shim's log says which of the two ran. Once the app has streamed the whole track there is no
way back to the stock processor for *that* track, so a job that misses the engine is finished
with silence and the reason is logged.

The binary is rebuilt from `shim\StemsShim.cs` (see "Rebuilding"); install it with
`-Engine custom`, or point at another binary with `-CustomExe <path>`.

## Limitations worth knowing

* **Engine DJ can overwrite the custom engine itself.** Its binary contains
  `Download and Extract Stems Processor`, `stems-processor.tar.zst`,
  `https://enginedj.com/downloads/windows-stems` and `Stems Processor Path`, so an in-app stems
  update re-extracts the stock processor over the active file. Re-run `-Engine custom` afterwards;
  `-Status` will show the change. If a *new* stock version appears, re-run `-Engine adopt -Force`
  to move the baseline to it.
* **The switch does not invalidate existing stems.** Tracks already separated keep their
  `.stems` files, so switching engines will not re-separate them on its own. Whether the app
  re-runs or skips them is decided by its database (`m.db` / `stm.db`), which the switch
  deliberately does not touch.
* **The demucs stage is not bit-reproducible, so do not compare stem files by hash.** Two runs
  of the same install on the same machine produce stem bytes that differ by a few percent
  (measured: ~4–10% RMS on drums/bass/other, ~0.1–1.3% on stem energy, correlation 0.997+),
  because CPU convolutions and their reductions are not deterministic and the CUDA path differs
  from the CPU one again. The vocals stage *is* deterministic and bit-identical. Compare
  energies, correlations or how a stem sounds, not the bytes.
* **The stdio protocol is reproduced from measurements, so a changed host would break it.**
  Both directions are planar float32, `action=block` / `action=done` / `returnFrames` /
  `done=true`, with the four stems in 8 channels as vocals, bass, drums, other — all of it read
  off a real stock capture (the header of `shim\StemsShim.cs` records the evidence). If a future
  Engine DJ speaks something else, the shim's log will show it and `-Engine vendor` is one
  click away.

## Verifying it yourself

```
powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-engine-switch.ps1
powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-shim-delegation.ps1
.\stems-lab\switch-app\StemsEngineSwitch.exe --selftest stems-lab\switch-app\selftest-report.txt
```

The third command checks the app's own plumbing headlessly, including the machine-readable
status it reads (`-Engine status -Json`), and writes a pass/fail report.

The first runs the switch through every state (adopt, dry run, install, repeat, missing binary,
restore, round trips, ambiguous state) inside a sandbox with its own state file, and asserts at
the end that the project copy and the live install still hold the stock bytes. The second builds
a sandbox whose stock processor is a **hard link** to the real one — same bytes, no second copy —
and checks that the shim starts it and passes its handshake through, including the failure path
when the stock binary is missing.

Both exit `0` only if every check passes.

## Nothing is left behind

A finished job cleans up after itself: once every stem of the track has gone back to Engine DJ
and the session ends, the shim deletes that job's render (the four stem WAVs and manifest under
`engine\cache\`) and the copy of the input it fed the engine. The shim's log records both, with
the size reclaimed.

* A job that **fails** keeps its render and its input copy, so a retry after the fix costs
  nothing.
* Leftovers from a job that never ended (a crash, a kill, a power cut) are swept by a later job
  once nothing has written to them for an hour (input copies) or six hours (renders). The sweep
  is age-based, not count-based, so a job that is still writing can never have its files taken
  away, and an entry a cache hit was served from counts as fresh material.
* Only the newest five shim logs (one per job, written in the shim's own folder) are kept.
* `STEMS_KEEP_CACHE=1` / `STEMS_KEEP_SESSIONS=1` switch the deletion and the sweep off, one each,
  for a debugging run.

After a normal track the scratch folders are empty: a 6-minute track no longer parks 130-260 MB
in `engine\cache\` forever.

## Rebuilding

Both binaries are plain C# compiled by the .NET Framework compiler that ships with Windows — no
SDK needed:

```
C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe -nologo -optimize+ -target:exe
    -out:stems-lab\shim\stems-processor.exe stems-lab\shim\StemsShim.cs
```

(for the switch app: `-target:winexe` and `switch-app\StemsEngineSwitch.cs`). Then install it
with `-Engine custom`; `-Status` prints the new hash.

## First run on a fresh clone or a new PC

Nothing in this repo is pinned to this machine. A fresh clone is small on purpose — the big
model, the ffmpeg binary and the reference captures are not in it, because they either rebuild
or download on first use.

**The short way:** run the switch app and press **Set up Custom Engine (first run)**. It does
everything below for you — uv, Python 3.12, the venv, the model, ffmpeg, the demucs weights —
and tells you when it is done so you can pick an engine. The rest of this section is the manual
equivalent, which is what the button runs.

What it does, once:

1. **Rebuild the venv.** The included `.venv` is deliberately not in the repo (it is 5 GB of
   machine-specific binaries with absolute paths). Rebuild it with 64-bit Python 3.12, the
   version this lab was built with:

   ```
   uv venv --seed --python 3.12 .venv   # or: py -3.12 -m venv .venv, which includes pip
   .venv\Scripts\python.exe -m pip install -r requirements.txt
   ```

   `--seed` is not optional: a plain `uv venv` contains no pip, so the second line fails with
   "No module named pip".

   That installs everything the service and `separate.py` need: numpy, soundfile, torch,
   torchaudio, demucs, audio-separator, imageio-ffmpeg and onnxruntime. All versions in
   `requirements.txt` are pinned and real on PyPI.

   `audioread` is pinned there for a reason: `audio-separator` imports it at module level and
   does not declare it, and `librosa` 1.0 — which it does depend on — stopped bringing it in.
   Without that pin the install succeeds and then every `audio-separator` command dies with
   `ModuleNotFoundError: No module named 'audioread'`. After the install you can check it in one
   line: `.venv\Scripts\python.exe -c "import audio_separator.separator"`.

2. **First separation pulls in the rest automatically.** The first time a track is separated:

   * `separate.py` / the service ask torch what the machine has and pick `cpu` when there is no
     CUDA device. `STEMS_DEVICE=cpu` forces CPU on a machine whose GPU should be left alone.
   * `ensure_ffmpeg()` (called by the service and by `separate.py`) recreates
     `.ffmpeg\ffmpeg.exe` from the `imageio-ffmpeg` cache the venv step just installed — so the
     84 MB ffmpeg binary is not in the repo either.
   * the vocal stage (`run_audio_separator`) runs `audio-separator.exe --model_filename
     vocals_mel_band_roformer.ckpt --model_file_dir models\`. With an empty `models\` that
     command downloads the 871 MB `vocals_mel_band_roformer.ckpt` (plus a small yaml and a
     `download_checks.json`) from Hugging Face into `models\`. It does not need to be in the
     repo.
   * the residual stage (`run_demucs`) uses `demucs.api.Separator(model="htdemucs_ft")`, which
     downloads the `htdemucs_ft` weights (about 4 × 84 MB safetensors) into the user profile's
     Hugging Face cache on first use if they are not there.

   So on a machine with no NVIDIA GPU nothing extra is needed — the CPU path is the default and
   the one real trap (audio-separator grabbing a GPU anyway) is handled by starting it with
   `CUDA_VISIBLE_DEVICES=-1`.

3. **Run the switch app** from the cloned folder. With a fresh Engine DJ install there is no
   recorded baseline, so click **Use ORIGINAL stems** first (that click only *learns* the stock
   hash — it changes nothing) and then **Use CUSTOM stems**. The second click also rewrites
   `engine.json` beside the installed shim, which is the only thing the shim needs to find the
   cloned lab.

Two things deliberately do not move with the folder: `switch-state.json` describes one machine's
Engine DJ install (which is why step 3 may start with the ORIGINAL click), and the installed shim
itself — that is what the CUSTOM click installs.

## A PC with no NVIDIA GPU

Separation just runs on the CPU; nothing has to be configured. The service asks torch what the
machine has and picks `cpu` when there is no CUDA device; `STEMS_DEVICE=cpu` forces it on a
machine whose GPU should be left alone, and both the ping reply and the job log name the device
that ran.

* The audio-separator stage has no device flag of its own and would grab a GPU regardless, so a
  CPU run starts it with `CUDA_VISIBLE_DEVICES=-1` — the GPU is hidden from that child process,
  which is what makes it choose the CPU. (`-1`, not an empty string: an empty value leaves torch
  claiming CUDA exists with zero devices, which crashes that stage's device probe instead of
  falling back.)
* Install the CPU build from `requirements.txt` (`onnxruntime==1.30.0`). The CUDA torch wheels
  do work on a CPU-only machine, they are just about 3 GB larger than they need to be.

## What is in the repo

The custom engine is the shim plus the resident service, and this is the whole of what it reads
at runtime from the repo:

| path | role |
|---|---|
| `stems-lab\shim\stems-processor.exe` | the binary `-Engine custom` installs (source: `shim\StemsShim.cs`) |
| `stems-lab\shim\StemsShim.cs` | source of the shim |
| `stems-lab\switch-app\StemsEngineSwitch.exe` | the switch app binary |
| `stems-lab\switch-app\StemsEngineSwitch.cs` | source of the switch app |
| `stems-lab\engine-switch.ps1` | the tested switch logic the app drives |
| `stems-lab\engine\engine_service.py` | the resident service |
| `stems-lab\separate.py` | the cascade the service imports |
| `stems-lab\requirements.txt` | pinned deps to rebuild `.venv` |
| `stems-lab\tests\test-engine-switch.ps1` | switch harness |
| `stems-lab\tests\test-shim-delegation.ps1` | shim delegation harness |
| `stems-lab\stem-player\` | the local stem auditioner |
| `stems-lab\tools\`, `stems-lab\disasm.txt` | notes and scripts from the stock-binary analysis |
| `stems-lab\*.md` | this file and the lab's notes |

Everything that is not in that table is either **regenerable on first use** (the venv, the
`models\vocals_mel_band_roformer.ckpt` that audio-separator downloads, `.ffmpeg\ffmpeg.exe` that
`ensure_ffmpeg` recreates, the `htdemucs_ft` weights that demucs downloads) or
**verification evidence** (`engine\references\` and `engine\stock\` — real captures used when
checking the shim and switch, not needed to run the engine). Those are kept on disk here but are
not in the repo, which is why the clone is small.

The switch app and `engine-switch.ps1` resolve everything relative to themselves, so neither cares
where the folder is. The installed shim resolves the lab as `STEMS_LAB`, then the `engine.json`
beside it, then the path compiled into it, and every `-Engine custom` rewrites that `engine.json` —
so moving or renaming the folder is a one-click fix: run the switch from the new location.
