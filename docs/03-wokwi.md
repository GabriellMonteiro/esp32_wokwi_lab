# 3. Configurar o Wokwi

1. Crie ou acesse sua conta no Wokwi.
2. No VS Code, confirme que a extensão Wokwi está instalada.
3. Faça login/licenciamento conforme solicitado pela extensão.
4. Garanta que o projeto já foi compilado antes de iniciar a simulação.

Arquivos usados:

- `wokwi.toml`: informa ao Wokwi quais artefatos compilados executar.
- `diagram.json`: descreve o hardware virtual e as conexões.

Após cada alteração relevante no firmware:

```bash
idf.py build
```

Depois execute `Wokwi: Start Simulator` pela paleta de comandos.
