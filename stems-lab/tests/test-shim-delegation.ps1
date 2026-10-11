<#
test-shim-delegation.ps1 - proves the custom-slot shim really delegates to the
stock processor, without touching the live install or copying 415 MB.

It builds a sandbox whose stems-processor.vendor.exe is a hard link to the real
stock binary (same bytes, no second copy) plus the companion dll, drops the shim
in as stems-processor.exe, and runs the shim the way Engine DJ would: with
`-s <stem> -hv <hostVersion> -pv <procVersion>` and a line on stdin.

Success looks like the stock processor's own handshake line coming back through
the shim's stdout, which only happens if the child started and both pipes work.

  powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-shim-delegation.ps1
#>
[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'

$LabRoot = Split-Path -Parent $PSScriptRoot
$ProjBin = Join-Path (Split-Path -Parent $LabRoot) 'bin'
$Shim    = Join-Path $LabRoot 'shim\stems-processor.exe'
$Sandbox = Join-Path $PSScriptRoot 'shim-run'

$script:Pass = 0
$script:Fail = 0
$script:Failures = @()

function Check([string]$name, [bool]$ok, [string]$detail = '') {
    if ($ok) { $script:Pass++; Write-Host ("  PASS  {0}" -f $name) -ForegroundColor DarkGreen }
    else { $script:Fail++; $script:Failures += $name; Write-Host ("  FAIL  {0}  {1}" -f $name, $detail) -ForegroundColor Red }
}

function Run-Shim([string]$dir, [string[]]$shimArgs, [int]$timeoutMs, [hashtable]$env = $null) {
    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = Join-Path $dir 'stems-processor.exe'
    $psi.Arguments = ($shimArgs -join ' ')
    $psi.UseShellExecute = $false
    $psi.RedirectStandardInput = $true
    $psi.RedirectStandardOutput = $true
    $psi.RedirectStandardError = $true
    $psi.WorkingDirectory = $dir
    # The mode decision the shim makes depends on its own environment (which lab to use, whether
    # to force delegation), so the sandbox has to pin it rather than inherit whatever the shell has.
    if ($env) { foreach ($k in $env.Keys) { $psi.EnvironmentVariables[[string]$k] = [string]$env[$k] } }

    $p = [System.Diagnostics.Process]::Start($psi)
    $outTask = $p.StandardOutput.ReadToEndAsync()
    $errTask = $p.StandardError.ReadToEndAsync()
    try { $p.StandardInput.Write("hello`n"); $p.StandardInput.Flush() } catch { }

    $exited = $p.WaitForExit($timeoutMs)
    if (-not $exited) {
        # Closing the pipe is what the real app does at the end of a session, and the shim
        # answers it by finishing and exiting on its own. Killing first can cut the stream
        # read off mid-flight, which once made a healthy shim look like it produced nothing;
        # give it a moment to leave cleanly before falling back to a kill.
        try { $p.StandardInput.Close() } catch { }
        $exited = $p.WaitForExit(3000)
    }
    if (-not $exited) { try { $p.Kill() } catch { } ; Start-Sleep -Milliseconds 500 }
    $out = ''; $err = ''
    try { if ($outTask.Wait(3000)) { $out = $outTask.Result } } catch { }
    try { if ($errTask.Wait(3000)) { $err = $errTask.Result } } catch { }

    return [pscustomobject]@{ out = $out; err = $err; exited = $exited; exitCode = $(if ($exited) { $p.ExitCode } else { $null }) }
}

# ------------------------------------------------------------------ setup ----

Write-Host ''
Write-Host 'setting up the delegation sandbox (hard links, no copies)' -ForegroundColor Cyan
Get-Process -Name 'Engine DJ' -ErrorAction SilentlyContinue | Out-Null
if (Test-Path -LiteralPath $Sandbox) { Remove-Item -LiteralPath $Sandbox -Recurse -Force }
New-Item -ItemType Directory -Path $Sandbox -Force | Out-Null

$vendorSource = Join-Path $ProjBin 'stems-processor.exe'
$dllSource    = Join-Path $ProjBin 'NNPredictionDispatcher_on.dll'
if (-not (Test-Path -LiteralPath $vendorSource)) { throw "stock processor not found: $vendorSource" }

New-Item -ItemType HardLink -Path (Join-Path $Sandbox 'stems-processor.vendor.exe') -Target $vendorSource | Out-Null
if (Test-Path -LiteralPath $dllSource) {
    New-Item -ItemType HardLink -Path (Join-Path $Sandbox 'NNPredictionDispatcher_on.dll') -Target $dllSource | Out-Null
}
Copy-Item -LiteralPath $Shim -Destination (Join-Path $Sandbox 'stems-processor.exe') -Force

# The live install may hold either processor depending on which engine the user has installed, so
# the invariant this suite enforces is "this run did not modify it" - recorded here, compared below.
$liveBin    = Join-Path $env:LOCALAPPDATA 'AIR Music Technology\EnginePrime\bin\stems-processor.exe'
$liveBefore = $(if (Test-Path -LiteralPath $liveBin) { (Get-FileHash -LiteralPath $liveBin -Algorithm MD5).Hash } else { '(none)' })

$vendorHash = (Get-FileHash -LiteralPath (Join-Path $Sandbox 'stems-processor.vendor.exe') -Algorithm MD5).Hash
Write-Host ("  sandbox  {0}" -f $Sandbox)
Write-Host ("  vendor   {0} (hard link to {1})" -f $vendorHash, (Split-Path -Leaf $vendorSource))

# ------------------------------------------------------------- the tests -----

Write-Host ''
$forced = @{ STEMS_FORCE_DELEGATE = '1' }

Write-Host '1. forced delegation runs the stock processor and passes its handshake through' -ForegroundColor Cyan
$r = Run-Shim $Sandbox @('-s', 'vocals', '-hv', '1.0.0', '-pv', '1.6.0') 15000 $forced
Check 'stock handshake appeared on the shim stdout' ($r.out -match 'preparing=initialising') ("stdout: " + ($r.out -replace "`n", '\n'))
Check 'a session token came through' ($r.out -match 'session=[A-Z0-9]+')
Check 'stdout carried protocol only, never shim diagnostics' (-not ($r.out -match 'shim start|delegating|capture enabled|engine ')) ("stdout: " + ($r.out -replace "`n", '\n'))
Check 'the shim log recorded the delegation' (
    (Get-ChildItem -LiteralPath $Sandbox -Filter 'stems-shim-*.log' | ForEach-Object { Get-Content -LiteralPath $_.FullName -Raw }) -match 'delegating to the stock processor'
)

Write-Host ''
Write-Host '2. the shim is engine-agnostic about the stem argument' -ForegroundColor Cyan
$r2 = Run-Shim $Sandbox @('-s', 'drums', '-hv', '1.0.0', '-pv', '1.6.0') 15000 $forced
Check 'handshake appeared for -s drums as well' ($r2.out -match 'preparing=initialising')

Write-Host ''
Write-Host '3. no engine and no stock processor fails loudly and does not pretend' -ForegroundColor Cyan
Remove-Item -LiteralPath (Join-Path $Sandbox 'stems-processor.vendor.exe') -Force
$emptyLab = Join-Path $Sandbox 'empty-lab'
New-Item -ItemType Directory -Path $emptyLab -Force | Out-Null
$r3 = Run-Shim $Sandbox @('-s', 'vocals', '-hv', '1.0.0', '-pv', '1.6.0') 20000 @{ STEMS_LAB = $emptyLab }
Check 'exit code is nonzero' ($r3.exitCode -ne 0 -and $null -ne $r3.exitCode) ("exit=" + $r3.exitCode)
Check 'the reason is on stderr, not stdout' ([string]::IsNullOrWhiteSpace($r3.out) -and $r3.err -match 'neither the engine nor the stock processor') ("stderr: " + $r3.err)

Write-Host ''
Write-Host '4. an installed engine is used without asking, even with no stock processor' -ForegroundColor Cyan
$r4 = Run-Shim $Sandbox @('-s', 'vocals', '-hv', '1.0.0', '-pv', '1.6.0') 25000
Check 'the custom engine answered the handshake itself' ($r4.out -match 'preparing=initialising') ("stdout: " + ($r4.out -replace "`n", '\n'))
Check 'it reports custom mode, not delegation' ($r4.err -match 'custom mode') ("stderr: " + $r4.err)

Write-Host ''
Write-Host '5. the real install was not touched' -ForegroundColor Cyan
Check 'project bin still holds the stock processor' ((Get-FileHash -LiteralPath $vendorSource -Algorithm MD5).Hash -eq 'e416e195bfe3aa0aafe0759ebdfb2ca8')
$liveAfter = $(if (Test-Path -LiteralPath $liveBin) { (Get-FileHash -LiteralPath $liveBin -Algorithm MD5).Hash } else { '(none)' })
Write-Host ("  live install processor is {0}" -f $liveAfter)
Check 'this run did not modify the live install' ($liveAfter -eq $liveBefore) ("before=$liveBefore after=$liveAfter")
Check 'no shim log leaked into the project bin' (-not (Get-ChildItem -LiteralPath $ProjBin -Filter 'stems-shim-*.log' -ErrorAction SilentlyContinue))

# ---------------------------------------------------------------- summary ----

Write-Host ''
Write-Host ('{0} passed, {1} failed' -f $script:Pass, $script:Fail) -ForegroundColor ($(if ($script:Fail) { 'Red' } else { 'Green' }))
if ($script:Fail) {
    Write-Host 'failed checks:' -ForegroundColor Red
    $script:Failures | ForEach-Object { Write-Host ("  - {0}" -f $_) -ForegroundColor Red }
    exit 1
}
Write-Host ("sandbox kept for inspection: {0}" -f $Sandbox) -ForegroundColor DarkGray
Write-Host 'note: the vendor file in that sandbox is a hard link to the project copy - no extra disk, and deleting it cannot affect the original.' -ForegroundColor DarkGray
exit 0
