# 7. Troubleshooting

## `idf.py` não existe

Confirme que o VS Code foi reaberto no Dev Container. No terminal, o prompt deve estar executando dentro do container.

## Docker não inicia

Valide WSL2 e Docker Desktop no Windows.

## Build funciona, mas Wokwi não inicia

Confirme:

1. se `idf.py build` terminou com sucesso;
2. se existem os arquivos `.bin` e `.elf` dentro de `build/`;
3. se os nomes em `wokwi.toml` correspondem ao nome do projeto em `CMakeLists.txt`.

## Erro I2C / sensor não responde

Confira:

- SDA GPIO 8;
- SCL GPIO 9;
- VCC em 3V3;
- GND;
- endereço `0x68`.

## Aviso de API I2C legada

O exemplo usa a API I2C clássica do ESP-IDF por ser didática e amplamente reconhecida. Algumas versões recentes podem apresentar aviso de depreciação, sem impedir o build. Em uma aula posterior, você pode migrar para a API nova `i2c_master`.
