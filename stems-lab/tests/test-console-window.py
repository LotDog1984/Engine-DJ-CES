"""No visible console window, at any depth of a job.

Engine DJ starts the shim with redirected pipes; the shim starts the engine service with a console
that has no window; the engine spawns `audio-separator.exe` - also a console program - for the vocal
model. A console program whose parent has **no console at all** is given a new one, and Windows 11
opens that as a visible Windows Terminal window in the middle of the screen. That is the pop-up this
suite exists to prevent, measured on a real job on 2026-10-14 (the window was titled
`.venv\\Scripts\\python.exe`, the launcher the engine is started through).

Two different lines keep it away, and this checks the one that a job cannot show from the outside:

  * the engine is created with CREATE_NO_WINDOW (shim\\StemsShim.cs, StartOwnProcess) instead of
    DETACHED_PROCESS. A console with no window, which its children then *inherit*. Only a real job
    can reach that, so `test-engine-end-to-end.ps1` asserts the engine's own `console window=` line
    for it, on the start path the app itself uses.
  * `audio-separator.exe` is spawned with CREATE_NO_WINDOW as well (separate.py, CHILD_FLAGS), and
    that is checked here by running the spawn decision itself: this suite starts a parent with no
    console (DETACHED_PROCESS, which is a console-less engine) and lets separate.py spawn a probe
    that reports what it was given. The probe is engine_service.describe_console(), the same
    function the engine logs with, so a log line and a test cannot disagree.

The matrix, measured 2026-10-14 (each cell a probe run, `tests/console-spawn.py`):

  | parent                        | CREATE_NO_WINDOW | probe reports        |
  |-------------------------------|------------------|----------------------|
  | hidden-console engine         | yes              | `console window=none`|
  | hidden-console engine         | no               | `console window=none`|  (inherits it)
  | console-less (DETACHED)       | yes              | `console window=none`|  <- the guard
  | console-less (DETACHED)       | no               | `console window=visible`| <- the pop-up

So the flag is what stands between a console-less engine and a window per track, and the last row is
how this check was shown to be able to fail. That row pops a real window, so it is opt-in:
`--show-window` runs it and asserts `visible`, which is the only way to prove the check is not
vacuous. The default run pops nothing.

Needs no venv packages, no models and no GPU - only a python on PATH is not enough, it uses the
interpreter it is started with:

  .venv\\Scripts\\python.exe tests\\test-console-window.py
  .venv\\Scripts\\python.exe tests\\test-console-window.py --show-window   (pops the window)
"""
import pathlib
import shutil
import subprocess
import sys

LAB = pathlib.Path(__file__).resolve().parent.parent
HERE = pathlib.Path(__file__).resolve().parent
MIDDLE = HERE / "console-spawn.py"
SCRATCH = HERE / "sandbox" / "console-window"

# The venv's python.exe is a launcher that re-spawns the real interpreter as a child - which is how
# a window appeared in the first place - so the engine-like cells start the launcher, exactly as the
# shim does. The console-less cell must be a process Windows will not give a console of its own, and
# a launcher would spawn one for its child, so that cell uses the interpreter underneath it.
LAUNCHER = sys.executable
REAL = getattr(sys, "_base_executable", sys.executable)

CHECKS = []


def check(name, ok, detail=""):
    CHECKS.append(bool(ok))
    print(("PASS  " if ok else "FAIL  ") + name + (f"   [{detail}]" if detail else ""))


def spawn(parent, use_flags, label):
    """Start the middle process as the given kind of parent and read what it reported."""
    report = SCRATCH / f"{label}.txt"
    args = [str(report)] + ([] if use_flags else ["--no-flags"])
    if parent == "engine":
        exe, flags = LAUNCHER, subprocess.CREATE_NO_WINDOW
    else:
        exe, flags = REAL, subprocess.DETACHED_PROCESS
    output = report.with_suffix(".out")
    with open(output, "wb") as handle:
        subprocess.run([exe, str(MIDDLE)] + args, cwd=str(LAB), creationflags=flags,
                       stdout=handle, stderr=subprocess.STDOUT)
    text = report.read_text(encoding="utf-8") if report.exists() else ""
    fields = dict(line.split("=", 1) for line in text.splitlines() if "=" in line)
    return fields, output.read_text(encoding="utf-8", errors="replace")


def windowless(fields):
    """`none` and `hidden` are both a job the user never sees; anything else is a window."""
    return fields.get("probe") in ("console window=none", "console window=hidden")


def main():
    show_window = "--show-window" in sys.argv[1:]
    print("no visible console window at any depth of a job")
    print(f"  launcher (what the shim starts) {LAUNCHER}")
    print(f"  interpreter underneath it       {REAL}")
    if SCRATCH.exists():
        shutil.rmtree(SCRATCH, ignore_errors=True)
    SCRATCH.mkdir(parents=True, exist_ok=True)

    # The engine's situation: no console at all, and its output is not a console.
    fields, output = spawn("console-less", True, "consoleless-flagged")
    check("separate.py hands the child its own output instead of an inherited handle",
          fields.get("separate_handed_it_flags") == "yes", output.strip())
    check("a child of a console-less engine gets CREATE_NO_WINDOW",
          fields.get("flags_used") == "CREATE_NO_WINDOW", output.strip())
    check("so it has no window of its own", windowless(fields), fields.get("probe", output.strip()))

    # The engine the shim actually starts: CREATE_NO_WINDOW, so its children inherit a hidden
    # console and none of them can allocate a visible one, flags or no flags.
    fields, output = spawn("engine", True, "engine-flagged")
    check("a child of the hidden-console engine in the shim's configuration has no window",
          windowless(fields), fields.get("probe", output.strip()))
    fields, output = spawn("engine", False, "engine-unflagged")
    check("it has none even without the flag, because that console is inherited, not created",
          windowless(fields), fields.get("probe", output.strip()))

    if show_window:
        # The control: the same spawn with the flag dropped, from a parent with no console. It pops
        # the window this whole suite is about - run it only to prove the check above can fail.
        fields, output = spawn("console-less", False, "consoleless-unflagged")
        check("with the flag dropped, that same child is given a visible window (this is the pop-up)",
              fields.get("probe") == "console window=visible", fields.get("probe", output.strip()))
    else:
        print("note  the window-popping control cell was not run; pass --show-window to prove the")
        print("      check above can fail (it puts a terminal window on screen for a moment)")

    failed = CHECKS.count(False)
    print()
    print(f"{len(CHECKS) - failed}/{len(CHECKS)} checks passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
