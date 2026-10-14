<#
test-engine-end-to-end.ps1 - a real job, through the real engine, with the shim as the app sees it.

Every other suite stops short of this on purpose: the switch and delegation harnesses use stubs and
the service suites never separate anything. This one plays Engine DJ for one short track, streams it
the way the app does (planar float32, 1024 frames per message), lets the shim start the resident
service, and checks a real separation comes back - through the model load, the cascade, and the
mirroring of the four stems into 8 channels.

It is also the only automated check of the things only the real thing can show:

  * the service is started with bInheritHandles=FALSE (StartOwnProcess in shim\StemsShim.cs) and
    still separates. That start gives the child no handles at all, so it is worth re-measuring
    whenever the start path changes.
  * that same start leaves the engine without a console *window* - the pop-up of 2026-10-14 - which
    the engine reports itself (`[stdio] ... console window=`). test-console-window.py covers the
    spawn one level below this one; this is the only place that covers the shim's own start.
  * the app's read on the processor's stdout still reaches end-of-file while that engine is alive.
    That is the 2026-10-14 bug (Engine DJ would not close) in its original form.
  * the cascade's stage 3 runs on real models: the vocals under-estimate that htdemucs finds in
    the residual is recovered into the vocals stem (the level fix of 2026-10-14). The tone is
    re-randomised per run so the service cannot answer from its cache and hide that stage.

It needs the lab's venv and the vocal model - what "Set up Custom Engine (first run)" installs - and
it writes nothing outside engine\cache and engine\sessions, which a successful job cleans up by
itself. Without those it skips with exit 0 and says so, so it can sit with the suites that need
nothing.

  powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-engine-end-to-end.ps1
#>
[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'

$LabRoot = Split-Path -Parent $PSScriptRoot
$Shim    = Join-Path $LabRoot 'shim\stems-processor.exe'
$Python  = Join-Path $LabRoot '.venv\Scripts\python.exe'
$Model   = Join-Path $LabRoot 'models\vocals_mel_band_roformer.ckpt'
$PortFile = Join-Path $LabRoot 'engine\engine.port'
$EngineLog = Join-Path $LabRoot 'engine\engine.log'
$Scratch = Join-Path $PSScriptRoot 'sandbox\e2e'

$script:Pass = 0
$script:Fail = 0
$script:Failures = @()

function Check([string]$name, [bool]$ok, [string]$detail = '') {
    if ($ok) { $script:Pass++; Write-Host ("  PASS  {0}" -f $name) -ForegroundColor DarkGreen }
    else { $script:Fail++; $script:Failures += $name; Write-Host ("  FAIL  {0}  {1}" -f $name, $detail) -ForegroundColor Red }
}

if (-not (Test-Path -LiteralPath $Python) -or -not (Test-Path -LiteralPath $Model)) {
    Write-Host ''
    Write-Host 'skipped: this lab has no venv / vocal model yet' -ForegroundColor Yellow
    Write-Host ("  looked for {0}" -f $Python)
    Write-Host ("         and {0}" -f $Model)
    Write-Host '  press "Set up Custom Engine (first run)" in the switch app, or follow'
    Write-Host '  "First run on a fresh clone or a new PC" in README-ENGINE-SWITCH.md'
    exit 0
}

# A service that is already up belongs to somebody else - the app, or a debugging session - so this
# suite reuses it and leaves it alone.
$engineWasRunning = Test-Path -LiteralPath $PortFile
Write-Host ''
Write-Host 'a real job through the real engine' -ForegroundColor Cyan
Write-Host ("  shim            {0}" -f $Shim)
Write-Host ("  engine already up: {0}" -f $engineWasRunning)
if (Test-Path -LiteralPath $Scratch) { Remove-Item -LiteralPath $Scratch -Recurse -Force }
New-Item -ItemType Directory -Path $Scratch -Force | Out-Null

$wav = Join-Path $Scratch 'tone.wav'
$planarFile = Join-Path $Scratch 'planar.bin'
# A fresh frequency per run: the service caches by content, and this suite wants the real cascade.
$tone = 200 + (Get-Random -Minimum 0 -Maximum 400)
$logBefore = $(if (Test-Path -LiteralPath $EngineLog) { (Get-Item -LiteralPath $EngineLog).Length } else { 0 })
& $Python -c @"
import array, math, struct, sys, wave
wav, planar = sys.argv[1], sys.argv[2]
sr, secs, freq = 44100, 4.0, float(sys.argv[3])
with wave.open(wav, 'wb') as w:
    w.setnchannels(2); w.setsampwidth(2); w.setframerate(sr)
    frames = bytearray()
    for i in range(int(sr * secs)):
        t = i / sr
        v = 0.4 * math.sin(2 * math.pi * freq * t) + 0.3 * math.sin(2 * math.pi * 880.0 * t)
        if i % (sr // 2) < 40:
            v += 0.5
        s = int(max(-1.0, min(1.0, v)) * 32000)
        frames += struct.pack('<hh', s, s)
    w.writeframes(bytes(frames))
with wave.open(wav, 'rb') as w:
    raw = w.readframes(w.getnframes())
a = array.array('h'); a.frombytes(raw)
with open(planar, 'wb') as fh:                      # the app's own layout: plane per channel
    fh.write(array.array('f', [v / 32768.0 for v in a[0::2]]).tobytes())
    fh.write(array.array('f', [v / 32768.0 for v in a[1::2]]).tobytes())
"@ $wav $planarFile $tone | Out-Null

$planar = [IO.File]::ReadAllBytes($planarFile)
$frames = [int]($planar.Length / 8)

$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = $Shim
$psi.Arguments = '-s vocals -hv 1.0.0 -pv 1.6.0'
$psi.UseShellExecute = $false
$psi.CreateNoWindow = $true
$psi.RedirectStandardInput = $true
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
$psi.WorkingDirectory = $Scratch
$psi.EnvironmentVariables['STEMS_LAB'] = $LabRoot
$psi.EnvironmentVariables['STEMS_SHIM_LOG'] = Join-Path $Scratch 'shim.log'
$psi.EnvironmentVariables['STEMS_ENGINE_WATCH_SECONDS'] = '600'
$psi.EnvironmentVariables['STEMS_ENGINE_GRACE_SECONDS'] = '600'

$p = [System.Diagnostics.Process]::Start($psi)
$outTask = $p.StandardOutput.ReadToEndAsync()
$errTask = $p.StandardError.ReadToEndAsync()
$bin = $p.StandardInput.BaseStream

function Write-Text([string]$text) {
    $bytes = [Text.Encoding]::ASCII.GetBytes($text)
    $bin.Write($bytes, 0, $bytes.Length)
    $bin.Flush()
}
function Write-Chunk([byte[]]$bytes) {
    $bin.Write($bytes, 0, $bytes.Length)
    $bin.Flush()
}

Write-Text "version=1.0.0`nnumChannels=2`nsampleRate=44100`nmaxBlockSize=1024`n`n"
$offset = 0
while ($offset -lt $frames) {
    $n = [Math]::Min(1024, $frames - $offset)
    Write-Text ("action=block`nnumSamples=" + $n + "`n`n")
    $planeBytes = $n * 4
    $chunk = New-Object byte[] ($n * 8)
    [Array]::Copy($planar, $offset * 4, $chunk, 0, $planeBytes)
    [Array]::Copy($planar, ($frames * 4) + ($offset * 4), $chunk, $planeBytes, $planeBytes)
    Write-Chunk $chunk
    $offset += $n
}
Write-Text "action=done`n`n"
$p.StandardInput.Close()

Check 'the shim finished the session on its own' ($p.WaitForExit(600000)) 'the model load or the separation did not finish in ten minutes'
$eof = $outTask.Wait(15000)
$payload = $(if ($eof) { $outTask.Result } else { '' })
$log = $(if (Test-Path -LiteralPath (Join-Path $Scratch 'shim.log')) { Get-Content -LiteralPath (Join-Path $Scratch 'shim.log') -Raw } else { '' })

Check 'it says the custom engine ran, not the stock one' ($log -match 'custom mode') $log
Check 'the engine produced all four stems' ($log -match 'engine produced stems: vocals, bass, drums, other') $log
Check 'the session came back clean' ($log -match 'session return code 0') $log
Check 'exit code 0' ($p.ExitCode -eq 0) ("exit=" + $p.ExitCode)

$returns = ([regex]::Matches($payload, 'returnFrames=(\d+)')) | ForEach-Object { [int]$_.Groups[1].Value }
$total = ($returns | Measure-Object -Sum).Sum
Check 'every input frame came back' ($total -eq $frames) ("returned=$total of $frames")
Check 'the session ended with done=true' ($payload -match 'done=true')
$bytes = [Text.Encoding]::GetEncoding(28591).GetBytes($payload)
$nonZero = 0
foreach ($b in $bytes) { if ($b -ne 0) { $nonZero++ } }
Check 'the returned stream is stem audio, not the silence fallback' ($nonZero -gt ($bytes.Length / 10)) ("non-zero bytes: " + $nonZero + " of " + $bytes.Length)

# The level fix, on the real models: the residual's vocals head is part of the vocals stem now,
# not waste. Read the lines this run added, so a resident engine's older log cannot answer.
$logText = $(if (Test-Path -LiteralPath $EngineLog) { Get-Content -LiteralPath $EngineLog -Raw } else { '' })
$tail = $logText.Substring([Math]::Min([int]$logBefore, $logText.Length))
$recovered = [regex]::Match($tail, '\[stage3\] vocals \+([\d.]+) dB recovered from the residual')
if ($engineWasRunning) {
    Write-Host '  note  an engine was already up before this run, so stage 3 here is whoever started it' -ForegroundColor DarkGray
} else {
    $gain = if ($recovered.Success) { [double]$recovered.Groups[1].Value } else { 0.0 }
    Check 'the vocals under-estimate was recovered into the vocals stem' ($recovered.Success -and $gain -gt 0.2) $tail
}

# ...and, in the same start, no window in front of whoever is using the app. This is the 2026-10-14
# pop-up: the shim starts the engine with no console at all, a console program whose parent has none
# is given a new one, and Windows 11 opens that as a visible Windows Terminal window - during a job,
# and for as long as the resident engine lives after it. The engine reports which it got, in one line
# of its own log, so this needs no window census and cannot go stale. The depth below this one (the
# engine's own child, audio-separator.exe) is covered by test-console-window.py.
$consoleReport = [regex]::Match($tail, '\[stdio\][^\r\n]*console window=(none|hidden|visible)')
if ($engineWasRunning) {
    Write-Host '  note  an engine was already up before this run, so its start (and its console) is not in this tail' -ForegroundColor DarkGray
} else {
    Check 'the engine was started without a window of its own' ($consoleReport.Success -and $consoleReport.Groups[1].Value -ne 'visible') $tail
}

# The 2026-10-14 bug: the shim is gone, the engine it started is not, and the app must still see the
# processor's output end.
$engineAlive = Test-Path -LiteralPath $PortFile
Check 'the engine is still resident after the job (it is meant to be)' ($engineAlive)
Check 'the app saw end-of-file on the processor pipe while that engine was alive' $eof 'the app would sit here waiting forever instead of closing'

if (-not $engineWasRunning -and $engineAlive) {
    $port = (Get-Content -LiteralPath $PortFile -Raw).Trim()
    Write-Host ("  stopping the engine this run started (port {0})" -f $port) -ForegroundColor DarkGray
    try {
        $c = New-Object System.Net.Sockets.TcpClient('127.0.0.1', [int]$port)
        $s = $c.GetStream()
        $b = [Text.Encoding]::ASCII.GetBytes('{"cmd":"stop"}' + "`n")
        $s.Write($b, 0, $b.Length); $s.Flush()
        (New-Object System.IO.StreamReader($s)).ReadLine() | Out-Null
        $c.Close()
    } catch {
        Write-Host ("  could not ask it to stop: " + $_.Exception.Message) -ForegroundColor Yellow
    }
}

Write-Host ''
Write-Host ('{0} passed, {1} failed' -f $script:Pass, $script:Fail) -ForegroundColor ($(if ($script:Fail) { 'Red' } else { 'Green' }))
if ($script:Fail) {
    Write-Host 'failed checks:' -ForegroundColor Red
    $script:Failures | ForEach-Object { Write-Host ("  - {0}" -f $_) -ForegroundColor Red }
    exit 1
}
Write-Host ("sandbox kept for inspection: {0}" -f $Scratch) -ForegroundColor DarkGray
exit 0
