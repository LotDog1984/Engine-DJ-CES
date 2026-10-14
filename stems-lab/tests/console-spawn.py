"""Spawn a console probe exactly the way the engine spawns audio-separator, and report what it got.

This is the middle of the console-window check: the suite starts it (see test-console-window.py) and
it does what `separate.py`'s run_audio_separator() does at the one line that matters -

    out, err = _child_output(tmpdir)
    subprocess.run(cmd, stdout=out, stderr=err, **flags)     flags = CHILD_FLAGS if out else {}

- with the probe in place of audio-separator.exe, so the answer comes from the real decision and not
from a copy of it. `--no-flags` drops CREATE_NO_WINDOW, which is the case that used to pop a window;
it is only used to show this check can fail.

  python tests/console-spawn.py <report path> [--no-flags]
"""
import pathlib
import subprocess
import sys

LAB = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(LAB))

import separate  # noqa: E402

HERE = pathlib.Path(__file__).resolve().parent
report_path = pathlib.Path(sys.argv[1])
probe_report = report_path.with_name(report_path.stem + "-probe.txt")
tmpdir = report_path.parent / "sessions" / report_path.stem
tmpdir.mkdir(parents=True, exist_ok=True)

wanted_flags = "--no-flags" not in sys.argv
out, err = separate._child_output(tmpdir)
flags = separate.CHILD_FLAGS if (out is not None and wanted_flags) else {}
lines = [
    f"child_stdout={'separator.log of its own' if out is not None else 'this process std handles'}",
    f"separate_handed_it_flags={'yes' if (out is not None) else 'no'}",
    f"flags_used={'CREATE_NO_WINDOW' if flags else 'none'}",
]
try:
    subprocess.run([sys.executable, str(HERE / "console-probe.py"), str(probe_report)],
                   check=True, stdout=out, stderr=err, **flags)
    lines.append("probe=" + probe_report.read_text(encoding="utf-8").strip())
except subprocess.CalledProcessError as exc:
    lines.append(f"probe=failed (exit {exc.returncode})")
finally:
    if out is not None:
        out.close()

text = "\n".join(lines)
report_path.write_text(text, encoding="utf-8")
print(text, flush=True)
