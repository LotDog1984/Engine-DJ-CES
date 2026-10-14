<#
test-shim-engine-handles.ps1 - the engine the shim starts must not be able to keep the app's
pipes open, and it must be told which app it belongs to.

The bug (reported 2026-10-14, after a 13-track batch): Engine DJ would not close. The shim starts
the resident engine service, .NET's Process.Start always passes bInheritHandles=TRUE, and the
handles this shim holds for the app's pipes are inheritable - the app made them so. So the service
inherited the write end of this session's stdout pipe, the shim exited, and the app's read on that
pipe still never reached end-of-file: a python process was holding a duplicate of the write end
for as long as it lived. Nothing stopped that process either, so the app waited on a pipe (and on
the engine's models sitting on the GPU) that was never going to end.

This harness plays the app: it starts the shim with redirected stdio, drives a session, and then
asks the only question that matters - after the shim is gone, and while the engine it started is
still running, does the shim's stdout reach end-of-file?

It also checks the engine service was started at all, so the pipe check cannot pass vacuously, and
that it was handed the pid to watch (the app's), which is what makes it go away with the app.

The "engine" is a sandbox lab whose .venv\Scripts\python.exe is a compiled sleeper: it ignores its
arguments and stays alive, which is exactly the shape of a resident engine service. No venv, no
models, no torch, and the whole suite runs in seconds.

Two things worth knowing when running this:
  * the sleeper is named python.exe (the path the shim looks for), so leftover sleepers are found
    by their image path, not by process name. They are killed at the start and in the finally.
  * do not pipe this script's output into something else while an old build is under test: a
    pre-fix shim passes its own inherited handles on to the sleeper, which then holds the pipe
    open - the very bug this covers. Redirect to a file, or watch it in a console.

  powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-shim-engine-handles.ps1
  powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-shim-engine-handles.ps1 -Shim <path to another stems-processor.exe>
#>
[CmdletBinding()]
param(
    [string]$Shim = ''
)

$ErrorActionPreference = 'Stop'

$LabRoot = Split-Path -Parent $PSScriptRoot
$Sandbox = Join-Path $PSScriptRoot 'sandbox\shim-engine'
$Lab = Join-Path $Sandbox 'lab'
if (-not $Shim) { $Shim = Join-Path $LabRoot 'shim\stems-processor.exe' }
$Shim = (Resolve-Path -LiteralPath $Shim).Path

$script:Pass = 0
$script:Fail = 0
$script:Failures = @()

function Check([string]$name, [bool]$ok, [string]$detail = '') {
    if ($ok) { $script:Pass++; Write-Host ("  PASS  {0}" -f $name) -ForegroundColor DarkGreen }
    else { $script:Fail++; $script:Failures += $name; Write-Host ("  FAIL  {0}  {1}" -f $name, $detail) -ForegroundColor Red }
}

# The stand-in engine is the sandbox lab's own python.exe, so a leftover from a crashed run is a
# process whose image lives under the lab - never "all python processes on this machine".
function Get-LabSleepers {
    $pattern = Join-Path $Lab '*'
    @(Get-Process -ErrorAction SilentlyContinue | Where-Object {
        $path = $null
        try { $path = $_.Path } catch { }
        return ($path -and ($path -like $pattern))
    })
}

function Stop-LabSleepers {
    foreach ($p in (Get-LabSleepers)) { try { $p.Kill() } catch { } }
    for ($i = 0; $i -lt 20 -and (Get-LabSleepers).Count -gt 0; $i++) { Start-Sleep -Milliseconds 150 }
}

function Invoke-ShimSession {
    param(
        [string]$logPath,
        [bool]$finishStream,      # $true: send action=done and take the silence path; $false: just close stdin
        [int]$watchSeconds = 30,
        [int]$graceSeconds = 1
    )

    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = $Shim
    $psi.Arguments = '-s vocals -hv 1.0.0 -pv 1.6.0'
    $psi.UseShellExecute = $false
    $psi.CreateNoWindow = $true
    $psi.RedirectStandardInput = $true
    $psi.RedirectStandardOutput = $true
    $psi.RedirectStandardError = $true
    $psi.WorkingDirectory = $Sandbox
    $psi.EnvironmentVariables['STEMS_LAB'] = $Lab
    $psi.EnvironmentVariables['STEMS_SHIM_LOG'] = $logPath
    $psi.EnvironmentVariables['STEMS_ENGINE_WATCH_SECONDS'] = [string]$watchSeconds   # ignored by a pre-fix build
    $psi.EnvironmentVariables['STEMS_ENGINE_GRACE_SECONDS'] = [string]$graceSeconds    # ignored by a pre-fix build
    $psi.EnvironmentVariables['STEMS_KEEP_SESSIONS'] = '1'

    $p = [System.Diagnostics.Process]::Start($psi)
    # This task is the point of the whole suite: it completes only when the shim's stdout reaches
    # end-of-file. With the bug, a process the shim started is still holding that pipe open, so it
    # never completes no matter how long the harness waits.
    $outTask = $p.StandardOutput.ReadToEndAsync()
    $errTask = $p.StandardError.ReadToEndAsync()

    $block = New-Object byte[] (1024 * 2 * 4)     # one maxBlockSize block of float32 stereo silence
    $bin = $p.StandardInput.BaseStream
    function Write-Text([string]$text) {
        $bytes = [Text.Encoding]::ASCII.GetBytes($text)
        $bin.Write($bytes, 0, $bytes.Length)
        $bin.Flush()
    }
    Write-Text "version=1.0.0`nnumChannels=2`nsampleRate=44100`nmaxBlockSize=1024`n`n"
    Write-Text "action=block`nnumSamples=1024`n`n"
    $bin.Write($block, 0, $block.Length)
    $bin.Flush()

    # Give the shim's engine watchdog time to notice there is no engine and start the service: the
    # checks below are meaningless if nothing was started, so the log is asserted on afterwards.
    Start-Sleep -Milliseconds 4000

    if ($finishStream) { Write-Text "action=done`n`n" }
    try { $p.StandardInput.Close() } catch { }

    $exited = $p.WaitForExit(30000)
    if (-not $exited) {
        try { $p.Kill() } catch { }
        Start-Sleep -Milliseconds 500
    }

    $eof = $outTask.Wait(5000)                    # <-- the app's "is the processor finished" wait
    $err = ''
    try { if ($errTask.Wait(3000)) { $err = $errTask.Result } } catch { }

    return [pscustomobject]@{
        exited   = $exited
        exitCode = $(if ($exited) { $p.ExitCode } else { $null })
        eof      = $eof
        err      = $err
        log      = $(if (Test-Path -LiteralPath $logPath) { Get-Content -LiteralPath $logPath -Raw } else { '' })
    }
}

# ------------------------------------------------------------------- sandbox ----

Write-Host ''
Write-Host 'setting up the engine sandbox (a sleeper standing in for the resident service)' -ForegroundColor Cyan
Stop-LabSleepers
if (Test-Path -LiteralPath $Sandbox) { Remove-Item -LiteralPath $Sandbox -Recurse -Force }
New-Item -ItemType Directory -Path $Sandbox -Force | Out-Null

$sleeperSource = Join-Path $Sandbox 'Sleeper.cs'
@'
using System.Threading;
static class Sleeper
{
    // Stands in for the resident engine service: started by the shim, ignores its arguments, and
    // stays alive exactly the way a python holding torch and demucs would.
    static void Main() { Thread.Sleep(Timeout.Infinite); }
}
'@ | Set-Content -LiteralPath $sleeperSource -Encoding ASCII

& "$env:WINDIR\Microsoft.NET\Framework64\v4.0.30319\csc.exe" -nologo -optimize+ -target:exe `
    ("-out:" + (Join-Path $Sandbox 'engine-stub.exe')) $sleeperSource | Out-Null
if (-not (Test-Path -LiteralPath (Join-Path $Sandbox 'engine-stub.exe'))) { throw 'the sleeper stub did not compile' }

# The lab the shim will consider "engine installed": the files it checks for, and nothing else.
New-Item -ItemType Directory -Path (Join-Path $Lab 'engine') -Force | Out-Null
New-Item -ItemType Directory -Path (Join-Path $Lab '.venv\Scripts') -Force | Out-Null
Set-Content -LiteralPath (Join-Path $Lab 'engine\engine_service.py') -Value '# never executed in this suite' -Encoding ASCII
Copy-Item -LiteralPath (Join-Path $Sandbox 'engine-stub.exe') -Destination (Join-Path $Lab '.venv\Scripts\python.exe') -Force

Write-Host ("  shim   {0}" -f $Shim)
Write-Host ("  lab    {0}" -f $Lab)

try {

    # --------------------------------------------------------- 1. the pipe leak ---

    Write-Host ''
    Write-Host '1. the app sees end-of-file on the processor pipe even while the engine is still alive' -ForegroundColor Cyan
    $r1 = Invoke-ShimSession -logPath (Join-Path $Sandbox 'shim-1.log') -finishStream $false
    $alive1 = (Get-LabSleepers).Count

    Check 'the shim started an engine service' ($r1.log -match 'started the engine service') ("log: " + $r1.log)
    Check 'the engine it started is still running (so this is a pipe test, not an engine-exit test)' ($alive1 -ge 1) ("alive=" + $alive1)
    Check 'the shim itself exited' ($r1.exited) 'a pre-fix build sits in its 600 s engine grace period here'
    Check 'the shim stdout reached end-of-file within 5 s of the shim exiting' ($r1.eof) 'the app would sit here waiting forever'

    $watchPid = ''
    if ($r1.log -match 'watching the app pid (\d+)') { $watchPid = $Matches[1] }
    Check 'the engine was told which app it belongs to (--watch-pid)' ($watchPid -eq [string]$PID) ("watch pid in log: '$watchPid', harness pid $PID")

    # --------------------------------------------- 2. a whole session, no engine ---

    Write-Host ''
    Write-Host '2. a full session with no engine ends in silence, and still leaves no pipe held open' -ForegroundColor Cyan
    Stop-LabSleepers
    $r2 = Invoke-ShimSession -logPath (Join-Path $Sandbox 'shim-2.log') -finishStream $true -graceSeconds 1
    $alive2 = (Get-LabSleepers).Count

    Check 'the shim exited on its own' ($r2.exited) ("exited=" + $r2.exited)
    Check 'it finished the session with silence instead of hanging the app' (
        $r2.exitCode -eq 3 -and $r2.log -match 'FATAL engine unavailable'
    ) ("exit=" + $r2.exitCode + " log: " + $r2.log)
    Check 'a resident engine from this run is still alive' ($alive2 -ge 1) ("alive=" + $alive2)
    Check 'and the shim stdout still reached end-of-file' ($r2.eof) 'the app would sit here waiting forever'

} finally {
    # Nothing of this suite may outlive it - least of all a sleep that holds a pipe open.
    Stop-LabSleepers
}

Write-Host ''
Write-Host ('{0} passed, {1} failed' -f $script:Pass, $script:Fail) -ForegroundColor ($(if ($script:Fail) { 'Red' } else { 'Green' }))
if ($script:Fail) {
    Write-Host 'failed checks:' -ForegroundColor Red
    $script:Failures | ForEach-Object { Write-Host ("  - {0}" -f $_) -ForegroundColor Red }
    exit 1
}
Write-Host ("sandbox kept for inspection: {0}" -f $Sandbox) -ForegroundColor DarkGray
exit 0
