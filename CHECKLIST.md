# Checklist da atividade

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
