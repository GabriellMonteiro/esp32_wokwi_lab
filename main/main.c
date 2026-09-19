#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_err.h"
#include "esp_log.h"

#define I2C_PORT            I2C_NUM_0
#define I2C_SDA_GPIO        8
#define I2C_SCL_GPIO        9
#define I2C_FREQ_HZ         100000
#define I2C_TIMEOUT_MS      1000

#define MPU6050_ADDR        0x68
#define REG_PWR_MGMT_1      0x6B
#define REG_GYRO_CONFIG     0x1B
#define REG_ACCEL_CONFIG    0x1C
#define REG_ACCEL_XOUT_H    0x3B
#define REG_WHO_AM_I        0x75

static const char *TAG = "MPU6050";

static esp_err_t mpu6050_write_reg(uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    return i2c_master_write_to_device(
        I2C_PORT,
        MPU6050_ADDR,
        data,
        sizeof(data),
        pdMS_TO_TICKS(I2C_TIMEOUT_MS)
    );
}

static esp_err_t mpu6050_read_regs(uint8_t reg, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(
        I2C_PORT,
        MPU6050_ADDR,
        &reg,
        1,
        data,
        len,
        pdMS_TO_TICKS(I2C_TIMEOUT_MS)
    );
}

static esp_err_t i2c_init(void)
{
    const i2c_config_t config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_SDA_GPIO,
        .scl_io_num = I2C_SCL_GPIO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_FREQ_HZ,
        .clk_flags = 0,
    };

    ESP_ERROR_CHECK(i2c_param_config(I2C_PORT, &config));
    return i2c_driver_install(I2C_PORT, config.mode, 0, 0, 0);
}

static esp_err_t mpu6050_init(void)
{
    esp_err_t err;

    // Acorda o sensor (sleep = 0)
    err = mpu6050_write_reg(REG_PWR_MGMT_1, 0x00);
    if (err != ESP_OK) return err;

    // Giroscópio em ±250 °/s
    err = mpu6050_write_reg(REG_GYRO_CONFIG, 0x00);
    if (err != ESP_OK) return err;

    // Acelerômetro em ±2 g
    err = mpu6050_write_reg(REG_ACCEL_CONFIG, 0x00);
    if (err != ESP_OK) return err;

    uint8_t who_am_i = 0;
    err = mpu6050_read_regs(REG_WHO_AM_I, &who_am_i, 1);
    if (err != ESP_OK) return err;

    ESP_LOGI(TAG, "WHO_AM_I = 0x%02X", who_am_i);
    if (who_am_i != 0x68) {
        ESP_LOGE(TAG, "MPU6050 nao identificado. Esperado 0x68.");
        return ESP_ERR_INVALID_RESPONSE;
    }

    return ESP_OK;
}

static int16_t be16(const uint8_t *p)
{
    return (int16_t)((p[0] << 8) | p[1]);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Iniciando I2C em SDA=%d, SCL=%d", I2C_SDA_GPIO, I2C_SCL_GPIO);
    ESP_ERROR_CHECK(i2c_init());

    ESP_LOGI(TAG, "Inicializando MPU6050...");
    ESP_ERROR_CHECK(mpu6050_init());
    ESP_LOGI(TAG, "MPU6050 pronto.");

    while (1) {
        uint8_t raw[14];
        esp_err_t err = mpu6050_read_regs(REG_ACCEL_XOUT_H, raw, sizeof(raw));

        if (err == ESP_OK) {
            int16_t ax_raw = be16(&raw[0]);
            int16_t ay_raw = be16(&raw[2]);
            int16_t az_raw = be16(&raw[4]);
            int16_t gx_raw = be16(&raw[8]);
            int16_t gy_raw = be16(&raw[10]);
            int16_t gz_raw = be16(&raw[12]);

            float ax = ax_raw / 16384.0f;
            float ay = ay_raw / 16384.0f;
            float az = az_raw / 16384.0f;
            float gx = gx_raw / 131.0f;
            float gy = gy_raw / 131.0f;
            float gz = gz_raw / 131.0f;

            ESP_LOGI(TAG, "ACC[g] x=% .3f y=% .3f z=% .3f | GYRO[dps] x=% .3f y=% .3f z=% .3f",
                     ax, ay, az, gx, gy, gz);
        } else {
            ESP_LOGE(TAG, "Falha na leitura I2C: %s", esp_err_to_name(err));
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
