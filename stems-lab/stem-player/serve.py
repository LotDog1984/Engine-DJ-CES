"""Local server for the stem auditioner: static files with HTTP Range support + /api/tracks.

The browser needs to stream four 40-90 MB WAVs at once and seek inside them, so this serves
the lab directory with real Range responses and handles requests on threads. Opened by
stem-player/index.html in the Preview panel.

    .venv/Scripts/python.exe stem-player/serve.py
"""
from __future__ import annotations

import datetime
import http.server
import json
import mimetypes
import pathlib
import re
import sys
import urllib.parse

HERE = pathlib.Path(__file__).resolve().parent
LAB = HERE.parent
STEM_NAMES = ("vocals", "drums", "bass", "other")
LABELS = HERE / "labels.json"          # cache key -> human label, optional

RENDERS: dict[str, str] = {             # .stems files worth listing, by file name
    "test1-custom.stems": "Test 1 - custom engine",
    "test2-original.stems": "Test 2 - original engine",
}
RENDER_NOTE = ("A .stems payload only Engine DJ's own decoder reads: ffmpeg, faad/VLC and the "
               "browser all refuse it, the stock engine's render as much as ours "
               "(see stem-player/probe.html). These can be heard on the SC4, or in Engine DJ "
               "itself - not in this player.")


def labels() -> dict:
    try:
        return json.loads(LABELS.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}


def renders() -> list[dict]:
    """The app's own .stems files, listed with the reason they cannot be played here."""
    out = []
    for path in sorted((LAB / "tests" / "stems-ab").glob("*.stems")):
        try:
            rel = path.resolve().relative_to(LAB)
        except ValueError:
            continue
        out.append({
            "label": RENDERS.get(path.name, path.name),
            "file": path.name,
            "url": "/" + rel.as_posix(),
            "bytes": path.stat().st_size,
            "playable": False,
            "note": RENDER_NOTE,
        })
    return out


# Matched by file-name prefix, first hit wins - so the longer, more specific prefixes come
# first. "custom-test1-sum" would otherwise also claim "custom-test1-sum-fixed.wav" and label
# the corrected render as the pitched one.
REFERENCE_LABELS = {                 # engine/references/*.wav, by file-name prefix
    "custom-test1-sum-fixed": "Test 1: the FIXED custom render's four stems summed (matches the source)",
    "custom-newtest-sum-fixed": "New Test: the FIXED custom render's four stems summed (matches the source)",
    "test1-app-stream-repaired": "Test 1: the captured stream with the planes put back - identical to the source file",
    "test1-app-stream-as-old-shim-wrote": "Test 1: the captured stream as the old shim wrote it - pitched (evidence, kept when sessions are pruned)",
    "app-stream-repaired": "The same captured bytes with the planes put back in order - what the app really sent",
    "app-stream-2026": "The app's captured stream as the old shim wrote it - pitched, for comparison",
    "source-file": "The same track decoded from its file with ffmpeg - what it should sound like",
    "source-test1": "Test 1: the source file decoded with ffmpeg",
    "source-New_Test": "New Test: the source file decoded with ffmpeg",
    "custom-test1-sum": "Test 1: the OLD custom render's four stems summed (pitched)",
    "stock-test1-sum": "Test 1: the stock render's four stems summed (reference)",
    "excerpt-30s": "A 30 s excerpt used for the shim harness runs",
}


def references() -> list[dict]:
    """Plain WAVs kept for A/B: the app's own stream and the source it came from."""
    out = []
    root = LAB / "engine" / "references"
    for path in sorted(root.glob("*.wav")):
        try:
            rel = path.resolve().relative_to(LAB)
        except ValueError:
            continue
        label = next((v for k, v in REFERENCE_LABELS.items() if path.name.startswith(k)), path.stem)
        out.append({"label": label, "file": path.name, "url": "/" + rel.as_posix(),
                    "mb": round(path.stat().st_size / 1048576, 1)})
    return out


def tracks() -> list[dict]:
    """Every separation this server can play, newest first, as URLs it can serve.

    engine/cache is what our engine handed the app (the shim's engine service writes it), and
    engine/stock is a render captured from Engine DJ's own processor and decoded out of its
    stream (tests/scan-return-frames.py). Both use the same manifest, so the two renders of one
    track sit next to each other in the player and can be A/B'd.
    """
    out = []
    known = labels()
    for kind, root in (("custom", LAB / "engine" / "cache"), ("stock", LAB / "engine" / "stock")):
        for manifest in root.glob("*/manifest.json"):
            try:
                data = json.loads(manifest.read_text(encoding="utf-8"))
            except (OSError, ValueError):
                continue
            stems = data.get("stems") or {}
            if sorted(stems) != sorted(STEM_NAMES):
                continue
            urls = {}
            for name, path in stems.items():
                try:
                    rel = pathlib.Path(path).resolve().relative_to(LAB)
                except ValueError:
                    continue
                urls[name] = "/" + rel.as_posix()
            if len(urls) != len(STEM_NAMES):
                continue
            when = datetime.datetime.fromtimestamp(manifest.stat().st_mtime)
            out.append({
                "key": manifest.parent.name,
                "kind": kind,
                "label": known.get(manifest.parent.name, ""),
                "seconds": data.get("seconds"),
                "realtime_factor": data.get("realtime_factor"),
                "created": when.strftime("%Y-%m-%d %H:%M"),
                "mtime": manifest.stat().st_mtime,
                "stems": urls,
            })
    out.sort(key=lambda t: t["mtime"], reverse=True)
    for t in out:
        del t["mtime"]
    return out


class Handler(http.server.BaseHTTPRequestHandler):
    server_version = "stems-lab/1.0"

    def log_message(self, fmt, *args):        # keep the console readable
        sys.stderr.write("  %s\n" % (fmt % args))

    def _json(self, payload) -> None:
        body = json.dumps(payload).encode("utf-8")
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self) -> None:                 # noqa: N802 (http.server naming)
        path = urllib.parse.urlparse(self.path).path
        if path == "/api/tracks":
            self._json(tracks())
            return
        if path == "/api/renders":
            self._json(renders())
            return
        if path == "/api/references":
            self._json(references())
            return
        if path in ("/", ""):
            self.send_response(302)
            self.send_header("Location", "/stem-player/index.html")
            self.end_headers()
            return

        target = (LAB / urllib.parse.unquote(path).lstrip("/")).resolve()
        try:
            target.relative_to(LAB)            # never serve outside the lab
        except ValueError:
            self.send_error(403, "outside the lab")
            return
        if not target.is_file():
            self.send_error(404, "no such file")
            return

        ctype = mimetypes.guess_type(str(target))[0] or "application/octet-stream"
        size = target.stat().st_size
        start, end = 0, size - 1
        partial = False
        header = self.headers.get("Range")
        if header:
            m = re.match(r"bytes=(\d*)-(\d*)$", header.strip())
            if m:
                if m.group(1):
                    start = int(m.group(1))
                if m.group(2):
                    end = min(int(m.group(2)), size - 1)
                if not m.group(1) and m.group(2):       # suffix range: last N bytes
                    start = max(0, size - int(m.group(2)))
                if start > end or start >= size:
                    self.send_response(416)
                    self.send_header("Content-Range", f"bytes */{size}")
                    self.end_headers()
                    return
                partial = True

        length = end - start + 1
        self.send_response(206 if partial else 200)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(length))
        self.send_header("Accept-Ranges", "bytes")
        if partial:
            self.send_header("Content-Range", f"bytes {start}-{end}/{size}")
        self.end_headers()

        try:
            with target.open("rb") as fh:
                fh.seek(start)
                remaining = length
                while remaining > 0:
                    chunk = fh.read(min(1 << 20, remaining))
                    if not chunk:
                        break
                    self.wfile.write(chunk)
                    remaining -= len(chunk)
        except (BrokenPipeError, ConnectionResetError):
            pass                               # the browser seeking away is normal


def main() -> int:
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8777
    server = http.server.ThreadingHTTPServer(("127.0.0.1", port), Handler)
    actual = server.server_address[1]
    (HERE / "server.port").write_text(str(actual), encoding="utf-8")
    print(f"[serve] http://127.0.0.1:{actual}/stem-player/index.html", flush=True)
    print(f"[serve] serving {LAB}", flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
