# 1. Preparar o Windows

## Instale

1. WSL2.
2. Docker Desktop usando backend WSL2.
3. Visual Studio Code.
4. Git.

No VS Code, instale:

- Dev Containers
- Wokwi for VS Code
- ESP-IDF

> Para este laboratório não é necessário configurar USB passthrough, porta COM ou drivers da placa, pois não será usada uma placa física.

## Verificação

Abra PowerShell na raiz do projeto e execute:

```powershell
.\scripts\check-host.ps1
```

Os itens essenciais são Docker e WSL2 funcionando.
