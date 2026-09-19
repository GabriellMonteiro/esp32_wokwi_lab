FROM espressif/idf:latest

WORKDIR /workspaces/esp32_wokwi_lab

# Ferramentas auxiliares úteis no laboratório.
RUN apt-get update \
    && apt-get install -y --no-install-recommends git curl ca-certificates \
    && rm -rf /var/lib/apt/lists/*
