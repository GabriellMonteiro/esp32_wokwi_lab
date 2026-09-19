# 2. Abrir o ambiente ESP-IDF isolado

1. Abra a pasta do projeto no VS Code.
2. Pressione `Ctrl+Shift+P`.
3. Execute `Dev Containers: Reopen in Container`.
4. Aguarde a construção da imagem.
5. Abra um terminal integrado.
6. Execute:

```bash
idf.py --version
```

Depois configure o alvo:

```bash
idf.py set-target esp32s3
```

E compile:

```bash
idf.py build
```

## O que aprender aqui

O Windows é apenas o host. Compilador, Python, CMake, Ninja e toolchain do ESP-IDF ficam dentro do container.

## Observação sobre a imagem

O template usa `espressif/idf:latest` para reduzir a chance de uma tag inexistente impedir a primeira instalação. Depois que o ambiente estiver funcionando, fixe uma versão específica da imagem para manter as aulas reproduzíveis.
