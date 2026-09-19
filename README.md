# Laboratório ESP32-S3 + MPU6050 — ESP-IDF, Docker e Wokwi

Template didático para executar uma atividade embarcada sem placa física no Windows.

## Objetivo

Compilar firmware C com ESP-IDF dentro de um Dev Container e executar no Wokwi usando um ESP32-S3 virtual conectado a um MPU6050 via I2C.

## Fluxo

Windows -> Docker/Dev Container -> ESP-IDF -> build -> Wokwi -> ESP32-S3 -> MPU6050 -> monitor serial.

## Comece aqui

Leia nesta ordem:

1. `docs/00-roadmap.md`
2. `docs/01-instalacao-windows.md`
3. `docs/02-devcontainer.md`
4. `docs/03-wokwi.md`
5. `docs/04-circuito.md`
6. `docs/05-build-simulacao.md`
7. `docs/06-entrega.md`
8. `docs/07-troubleshooting.md`

## Comandos principais

No terminal do Dev Container:

```bash
idf.py --version
idf.py set-target esp32s3
idf.py build
```

Depois, no VS Code, execute `Wokwi: Start Simulator`.

## Circuito

| MPU6050 | ESP32-S3 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 8 |
| SCL | GPIO 9 |

## Resultado esperado

O firmware valida o sensor pelo registrador `WHO_AM_I` e imprime aceleração e giroscópio no monitor serial.

## Git

Depois de validar tudo:

```bash
git init
git add .
git commit -m "feat: laboratorio ESP32-S3 MPU6050 com Wokwi"
```

Crie o repositório remoto e faça o push normalmente.

## Observação

O template usa a imagem Docker `espressif/idf:latest` apenas para facilitar a primeira inicialização. Depois de obter um ambiente funcional, fixe uma versão específica da imagem no `.devcontainer/Dockerfile` para evitar mudanças durante a disciplina.
