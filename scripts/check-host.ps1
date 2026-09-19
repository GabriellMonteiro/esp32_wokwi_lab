$ErrorActionPreference = "Continue"

Write-Host "=== Verificacao do host Windows ===" -ForegroundColor Cyan

function Check-Command($name) {
  $cmd = Get-Command $name -ErrorAction SilentlyContinue
  if ($cmd) {
    Write-Host "[OK] $name -> $($cmd.Source)" -ForegroundColor Green
  } else {
    Write-Host "[FALTA] $name" -ForegroundColor Yellow
  }
}

Check-Command "docker"
Check-Command "code"
Check-Command "git"

Write-Host "`nDocker:" -ForegroundColor Cyan
docker --version

Write-Host "`nWSL:" -ForegroundColor Cyan
wsl --status

Write-Host "`nSe Docker e WSL2 estiverem OK, abra a pasta no VS Code e use 'Dev Containers: Reopen in Container'." -ForegroundColor Cyan
