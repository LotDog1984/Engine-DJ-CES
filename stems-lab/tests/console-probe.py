"""Report the console this process was handed, in the engine's own words.

A console program whose parent has no console is given a *new* console, and Windows 11 opens that as
a visible Windows Terminal window. This probe is the smallest thing that can say whether that
happened to it: it prints `engine_service.describe_console()`, the same function the engine logs at
startup, so the words in a log line and the words in a test cannot drift apart.

  python tests/console-probe.py [<path to write the report to>]
"""
import pathlib
import sys

LAB = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(LAB))
sys.path.insert(0, str(LAB / "engine"))

import engine_service  # noqa: E402  (needs the paths above)

report = engine_service.describe_console()
if len(sys.argv) > 1:
    pathlib.Path(sys.argv[1]).write_text(report, encoding="utf-8")
print(report, flush=True)
