# Checklist da atividade

## Entrega validada
- [x] Firmware compilado para ESP32-S3 sem erros
- [x] Simulação do Wokwi validada com MPU6050
- [x] `WHO_AM_I = 0x68` confirmado
- [x] Leituras de acelerômetro e giroscópio confirmadas
- [x] Evidências incluídas no repositório
- [x] Repositório Git publicado: `GabriellMonteiro/esp32_wokwi_lab`

## Ambiente
- [ ] Docker Desktop instalado e iniciado
- [ ] WSL2 funcionando
- [ ] VS Code instalado
- [ ] Extensão Dev Containers instalada
- [ ] Extensão Wokwi instalada
- [ ] Conta Wokwi criada/logada
- [ ] Projeto aberto dentro do Dev Container
- [ ] `idf.py --version` funciona

## Projeto
- [ ] Target configurado como `esp32s3`
- [ ] `idf.py build` termina sem erros
- [ ] `wokwi.toml` aponta para `.bin` e `.elf` corretos
- [ ] `diagram.json` contém ESP32-S3 + MPU6050
- [ ] SDA está no GPIO 8
- [ ] SCL está no GPIO 9
- [ ] Alimentação e GND estão corretos

## Execução
- [ ] Wokwi inicia pelo VS Code
- [ ] `WHO_AM_I = 0x68` aparece
- [ ] Acelerômetro é impresso
- [ ] Giroscópio é impresso

## Evidências
- [ ] Screenshot da configuração ESP-IDF
- [ ] Screenshot do circuito Wokwi
- [ ] Screenshot do build sem erros
- [ ] Screenshot do monitor serial
- [ ] Repositório Git publicado
