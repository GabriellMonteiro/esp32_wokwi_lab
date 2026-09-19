# 4. Circuito virtual

O laboratório usa MPU6050 por I2C.

| MPU6050 | ESP32-S3 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 8 |
| SCL | GPIO 9 |

## Conceito

- SDA: linha de dados do I2C.
- SCL: linha de clock do I2C.
- O endereço padrão usado pelo firmware é `0x68`.
- `WHO_AM_I` deve retornar `0x68`.

O `diagram.json` e o `main.c` precisam usar os mesmos GPIOs.
