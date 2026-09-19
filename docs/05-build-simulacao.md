# 5. Build e simulação

Dentro do Dev Container:

```bash
idf.py set-target esp32s3
idf.py build
```

Quando o build terminar sem erros, inicie o Wokwi.

A saída esperada começa aproximadamente assim:

```text
I (...) MPU6050: Iniciando I2C em SDA=8, SCL=9
I (...) MPU6050: Inicializando MPU6050...
I (...) MPU6050: WHO_AM_I = 0x68
I (...) MPU6050: MPU6050 pronto.
I (...) MPU6050: ACC[g] x=... y=... z=... | GYRO[dps] x=... y=... z=...
```

Se o `WHO_AM_I` não for `0x68`, investigue primeiro circuito, GPIOs e endereço I2C.
