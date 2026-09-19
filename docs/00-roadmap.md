# Roadmap didático

A ordem recomendada é proposital: valide uma camada antes de adicionar a próxima.

1. Windows como host.
2. Docker Desktop + WSL2.
3. VS Code + Dev Containers.
4. Abrir o projeto dentro do container.
5. Validar `idf.py --version`.
6. Compilar para ESP32-S3.
7. Configurar conta/extensão Wokwi.
8. Validar o circuito virtual.
9. Executar o firmware.
10. Conferir `WHO_AM_I`.
11. Conferir leituras no monitor serial.
12. Capturar evidências.
13. Publicar no Git.

## Arquitetura

Windows -> Docker/Dev Container -> ESP-IDF -> build (.bin/.elf) -> Wokwi -> ESP32-S3 virtual -> MPU6050 virtual -> monitor serial.

O Docker isola a toolchain. O Wokwi simula o hardware.
