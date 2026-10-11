<#
test-engine-switch.ps1 - exercises stems-lab\engine-switch.ps1 end to end.

Everything happens inside a sandbox directory under stems-lab\tests\. The real
Engine DJ install, the project's bin\ copy and the real switch-state.json are
never touched: the sandbox has its own state and log files.

  powershell -ExecutionPolicy Bypass -File stems-lab\tests\test-engine-switch.ps1
#>
[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'

$LabRoot      = Split-Path -Parent $PSScriptRoot          # stems-lab
$SwitchScript = Join-Path $LabRoot 'engine-switch.ps1'
$CustomExe    = Join-Path $LabRoot 'shim\stems-processor.exe'
$Sandbox      = Join-Path $PSScriptRoot 'sandbox'
$BinDir       = Join-Path $Sandbox 'bin'
$StateFile    = Join-Path $Sandbox 'state.json'
$LogFile      = Join-Path $Sandbox 'log.txt'

$ActiveName = 'stems-processor.exe'
$VendorName = 'stems-processor.vendor.exe'
$DllName    = 'NNPredictionDispatcher_on.dll'

$script:Pass = 0
$script:Fail = 0
$script:Failures = @()

function Check([string]$name, [bool]$ok, [string]$detail = '') {
    if ($ok) {
        $script:Pass++
        Write-Host ("  PASS  {0}" -f $name) -ForegroundColor DarkGreen
    } else {
        $script:Fail++
        $script:Failures += $name
        Write-Host ("  FAIL  {0}  {1}" -f $name, $detail) -ForegroundColor Red
    }
}

function HashOf([string]$file) {
    if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { return $null }
    return (Get-FileHash -LiteralPath $file -Algorithm MD5).Hash.ToLowerInvariant()
}

function New-Fixture([string]$path, [int]$size, [int]$seed) {
    $rnd = New-Object System.Random($seed)
    $bytes = New-Object byte[] $size
    $rnd.NextBytes($bytes)
    [System.IO.File]::WriteAllBytes($path, $bytes)
}

function Invoke-Switch {
    param([string[]]$SwitchArgs)
    $out = Join-Path $Sandbox 'child-out.txt'
    $argList = @(
        '-NoProfile', '-ExecutionPolicy', 'Bypass',
        '-File', ('"' + $SwitchScript + '"'),
        '-Path', ('"' + $BinDir + '"'),
        '-StateFile', ('"' + $StateFile + '"'),
        '-LogFile', ('"' + $LogFile + '"')
    ) + $SwitchArgs
    Remove-Item -LiteralPath $out -Force -ErrorAction SilentlyContinue
    $err = Join-Path $Sandbox 'child-err.txt'
    $p = Start-Process -FilePath 'powershell.exe' -ArgumentList $argList -Wait -PassThru -NoNewWindow `
         -RedirectStandardOutput $out -RedirectStandardError $err
    $script:LastOut = if (Test-Path -LiteralPath $out) { Get-Content -LiteralPath $out -Raw } else { '' }
    if ($p.ExitCode -ne 0) {
        # surface the child's own diagnostics: a silent nonzero exit is untestable
        Write-Host ('    child exit {0}, args: {1}' -f $p.ExitCode, ($SwitchArgs -join ' ')) -ForegroundColor DarkYellow
        if (Test-Path -LiteralPath $err) {
            $e = Get-Content -LiteralPath $err
            $e | Select-Object -First 12 | ForEach-Object { Write-Host ('    | {0}' -f $_) -ForegroundColor DarkYellow }
        }
        $script:LastOut = $script:LastOut
    }
    return $p.ExitCode
}

# ------------------------------------------------------------------ setup ----

Write-Host ''
Write-Host 'setting up sandbox' -ForegroundColor Cyan
if (Test-Path -LiteralPath $Sandbox) { Remove-Item -LiteralPath $Sandbox -Recurse -Force }
New-Item -ItemType Directory -Path $BinDir -Force | Out-Null

New-Fixture (Join-Path $BinDir $ActiveName) 300000 12345   # stands in for the 415 MB stock processor
New-Fixture (Join-Path $BinDir $DllName)    40000  999     # stands in for NNPredictionDispatcher_on.dll

$vendorHash = HashOf (Join-Path $BinDir $ActiveName)
$dllHash    = HashOf (Join-Path $BinDir $DllName)

# What the real installs look like before this suite runs. Section 15 compares against this
# snapshot instead of demanding a stock install, because the live engine is a user choice - a
# deliberately installed custom engine is not a failure of this suite, but a change caused by
# this run would be.

$projBinPath = Join-Path (Split-Path -Parent $LabRoot) 'bin\stems-processor.exe'
$liveBinPath = Join-Path $env:LOCALAPPDATA 'AIR Music Technology\EnginePrime\bin\stems-processor.exe'
$realBefore  = @{}
foreach ($realPath in @($projBinPath, $liveBinPath)) {
    $realBefore[$realPath] = [pscustomobject]@{
        hash   = HashOf $realPath
        vendor = Test-Path -LiteralPath (Join-Path (Split-Path -Parent $realPath) 'stems-processor.vendor.exe')
    }
}
$customHash = HashOf $CustomExe
Write-Host ("  sandbox bin   {0}" -f $BinDir)
Write-Host ("  fake vendor   {0}" -f $vendorHash)
Write-Host ("  custom shim   {0}" -f $customHash)

# ------------------------------------------------------------- the tests -----

Write-Host ''
Write-Host '1. status before any baseline' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'status')
Check 'status exits 0' ($rc -eq 0) "exit=$rc"
Check 'status reports no baseline' ($script:LastOut -match 'no baseline recorded')
Check 'no backup file created by status' (-not (Test-Path -LiteralPath (Join-Path $BinDir $VendorName)))

Write-Host ''
Write-Host '2. custom before any baseline is refused' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
Check 'refused with a nonzero exit' ($rc -ne 0) "exit=$rc"
Check 'active file untouched' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)

Write-Host ''
Write-Host '3. adopt records the baseline without moving anything' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'adopt')
Check 'adopt exits 0' ($rc -eq 0) "exit=$rc"
Check 'active file still present and unchanged' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)
Check 'no backup file created by adopt' (-not (Test-Path -LiteralPath (Join-Path $BinDir $VendorName)))
Check 'status says stock' ($script:LastOut -match 'engine: stock')
Check 'status shows the recorded baseline' ($script:LastOut -match $vendorHash)

Write-Host ''
Write-Host '4. adopt is idempotent' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'adopt')
Check 'second adopt exits 0' ($rc -eq 0) "exit=$rc"
Check 'baseline unchanged' ($script:LastOut -match 'baseline already recorded')
Check 'active file untouched' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)
Write-Host ''
Write-Host '4b. machine-readable status for the switch app' -ForegroundColor Cyan
$beforeJson = @((HashOf (Join-Path $BinDir $ActiveName)), (HashOf (Join-Path $BinDir $VendorName)))
$rc = Invoke-Switch @('-Engine', 'status', '-Json')
Check 'json status exits 0' ($rc -eq 0) "exit=$rc"
$j = $null
try { $j = $script:LastOut | ConvertFrom-Json } catch { }
Check 'stdout parses as JSON' ($null -ne $j) $script:LastOut
Check 'json reports the bin directory' ($j.bin -eq $BinDir) ("got " + $j.bin)
Check 'json reports the stock engine' ($j.engine -eq 'vendor') ("got " + $j.engine)
Check 'json carries the baseline hash' ($j.baselineHash -eq $vendorHash)
Check 'json carries the active hash' ($j.activeHash -eq $vendorHash)
Check 'json output contains nothing but JSON' (($script:LastOut.Trim() -like '{*') -and ($script:LastOut.Trim() -like '*}'))
$afterJson = @((HashOf (Join-Path $BinDir $ActiveName)), (HashOf (Join-Path $BinDir $VendorName)))
Check 'json status moved nothing' (($beforeJson -join '|') -eq ($afterJson -join '|'))

Write-Host ''
Write-Host '5. dry run changes nothing' -ForegroundColor Cyan
$before = @(HashOf (Join-Path $BinDir $ActiveName), HashOf (Join-Path $BinDir $VendorName))
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'), '-WhatIf')
Check 'dry run exits 0' ($rc -eq 0) "exit=$rc"
Check 'dry run announced the copy' ($script:LastOut -match 'WHATIF')
$after = @(HashOf (Join-Path $BinDir $ActiveName), HashOf (Join-Path $BinDir $VendorName))
Check 'dry run left the files alone' (($before -join '|') -eq ($after -join '|'))

Write-Host ''
Write-Host '6. install the custom engine' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
Check 'install exits 0' ($rc -eq 0) "exit=$rc"
Check 'active file is the custom binary' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $customHash)
Check 'vendor bytes survived as the backup' ((HashOf (Join-Path $BinDir $VendorName)) -eq $vendorHash)
Check 'status says custom' ($script:LastOut -match 'engine: custom')

Write-Host ''
Write-Host '7. installing custom twice is a no-op' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
Check 'second install exits 0' ($rc -eq 0) "exit=$rc"
Check 'already-on-custom reported' ($script:LastOut -match 'already on the custom engine')
Check 'active file still custom' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $customHash)

Write-Host ''
Write-Host '8. a missing custom binary fails without damage' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + (Join-Path $Sandbox 'does-not-exist.exe') + '"'))
Check 'nonzero exit' ($rc -ne 0) "exit=$rc"
Check 'active file still custom' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $customHash)
Check 'backup still vendor' ((HashOf (Join-Path $BinDir $VendorName)) -eq $vendorHash)

Write-Host ''
Write-Host '9. restore the stock engine' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'vendor')
Check 'restore exits 0' ($rc -eq 0) "exit=$rc"
Check 'active file is the stock bytes again' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)
Check 'backup name is gone' (-not (Test-Path -LiteralPath (Join-Path $BinDir $VendorName)))
Check 'status says stock' ($script:LastOut -match 'engine: stock')

Write-Host ''
Write-Host '10. restoring twice is a no-op' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'vendor')
Check 'second restore exits 0' ($rc -eq 0) "exit=$rc"
Check 'already-stock reported' ($script:LastOut -match 'already stock')
Check 'active file unchanged' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)

Write-Host ''
Write-Host '11. round trip twice' -ForegroundColor Cyan
$ok = $true
for ($i = 1; $i -le 2; $i++) {
    $rc1 = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
    $rc2 = Invoke-Switch @('-Engine', 'vendor')
    if ($rc1 -ne 0 -or $rc2 -ne 0) { $ok = $false }
    if ((HashOf (Join-Path $BinDir $ActiveName)) -ne $vendorHash) { $ok = $false }
}
Check 'custom/vendor round trip twice returns to stock' $ok

Write-Host ''
Write-Host '12. duplicate active+backup is resolved by -Engine vendor' -ForegroundColor Cyan
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
Copy-Item -LiteralPath (Join-Path $BinDir $VendorName) -Destination (Join-Path $BinDir $ActiveName) -Force
$rc = Invoke-Switch @('-Engine', 'vendor')
Check 'exits 0' ($rc -eq 0) "exit=$rc"
Check 'one stock file remains' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)
Check 'no backup left behind' (-not (Test-Path -LiteralPath (Join-Path $BinDir $VendorName)))
Check 'duplicate was reported' ($script:LastOut -match 'byte-identical')

Write-Host ''
Write-Host '13. unrecorded state: install must not guess' -ForegroundColor Cyan
Remove-Item -LiteralPath $StateFile -Force
Copy-Item -LiteralPath (Join-Path $BinDir $ActiveName) -Destination (Join-Path $BinDir $VendorName) -Force
$rc = Invoke-Switch @('-Engine', 'custom', '-CustomExe', ('"' + $CustomExe + '"'))
Check 'refuses without a baseline' ($rc -ne 0) "exit=$rc"
Check 'files left as they were' ((HashOf (Join-Path $BinDir $ActiveName)) -eq $vendorHash)

Write-Host ''
Write-Host '14. the companion dll was never touched' -ForegroundColor Cyan
Check 'dll hash unchanged' ((HashOf (Join-Path $BinDir $DllName)) -eq $dllHash)

Write-Host ''
Write-Host '15. the real files were never touched' -ForegroundColor Cyan
$projBin = $projBinPath
$liveBin = $liveBinPath
$liveActive = $realBefore[$liveBin].hash
$liveEngine = 'unknown file'
if ($null -eq $liveActive) { $liveEngine = 'not found' }
elseif ($liveActive -eq 'e416e195bfe3aa0aafe0759ebdfb2ca8') { $liveEngine = 'stock processor' }
elseif ($liveActive -eq '41b30700a9fc52d109a15e1dc5f06b0d') { $liveEngine = 'custom engine (shim)' }
Write-Host ("  live install before this run: {0}  ({1})" -f $liveEngine, $liveActive)
Check 'project bin still holds the stock processor' ((HashOf $projBin) -eq 'e416e195bfe3aa0aafe0759ebdfb2ca8') ("found " + (HashOf $projBin))
Check 'live install unchanged by this run' ((HashOf $liveBin) -eq $realBefore[$liveBin].hash) ("before " + $realBefore[$liveBin].hash + ", now " + (HashOf $liveBin))
Check 'project bin unchanged by this run' ((HashOf $projBin) -eq $realBefore[$projBin].hash)
Check 'no vendor backup appeared in the project bin' ((Test-Path -LiteralPath (Join-Path (Split-Path -Parent $projBin) 'stems-processor.vendor.exe')) -eq $realBefore[$projBin].vendor)
Check 'no vendor backup appeared in the live install' ((Test-Path -LiteralPath (Join-Path (Split-Path -Parent $liveBin) 'stems-processor.vendor.exe')) -eq $realBefore[$liveBin].vendor)

# ---------------------------------------------------------------- summary ----

Write-Host ''
Write-Host ('{0} passed, {1} failed' -f $script:Pass, $script:Fail) -ForegroundColor ($(if ($script:Fail) { 'Red' } else { 'Green' }))
if ($script:Fail) {
    Write-Host 'failed checks:' -ForegroundColor Red
    $script:Failures | ForEach-Object { Write-Host ("  - {0}" -f $_) -ForegroundColor Red }
    exit 1
}
exit 0
