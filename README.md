# Entrega — ESP32-S3 + MPU6050 com ESP-IDF e Wokwi

Repositório de entrega da atividade de IA Embarcada e Modelos Compactos. O projeto executa, sem placa física, um firmware C para ESP32-S3 que se comunica com um MPU6050 virtual via I2C.

## Enunciado atendido

Compilar o firmware com ESP-IDF em um Dev Container e executar a simulação no Wokwi, utilizando um ESP32-S3 conectado a um MPU6050 via I2C. A aplicação deve identificar o sensor pelo registrador `WHO_AM_I` e apresentar dados de acelerômetro e giroscópio no monitor serial.

## Resultado obtido

- Target: ESP32-S3;
- I2C: SDA no GPIO 8 e SCL no GPIO 9;
- MPU6050 identificado em `0x68`;
- build concluído sem erros;
- acelerômetro e giroscópio lidos e exibidos no monitor serial.

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

## Evidências

| Evidência | Comprovação |
|---|---|
| [ESP-IDF configurado](docs/evidencias/01-esp-idf-version.png) | `idf.py --version` executado no Dev Container |
| [Circuito no Wokwi](docs/evidencias/02_circuito_wokwi_leitura_mpu6050.png) | ESP32-S3 e MPU6050 conectados por I2C |
| [Build concluído](docs/evidencias/03-build-sucesso.png) | Compilação para ESP32-S3 sem erros |
| [Monitor serial](docs/evidencias/04-monitor-serial.png) | `WHO_AM_I = 0x68` e leituras ACC/GYRO |

## Observação

A imagem do Dev Container está fixada em `espressif/idf:v5.5.5` para tornar a compilação reproduzível.
