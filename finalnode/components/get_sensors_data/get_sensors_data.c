#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "get_sensors_data.h"


long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

esp_err_t get_ldr_data(){
    u_int16_t valor = adc1_get_raw(ldr);

    data.luminosity = map(valor, 0, 4095, 0, 100);

    ESP_LOGI(SensorTAG, "Luminosity: %d", data.luminosity);

    return ESP_OK;
}

esp_err_t get_bmp_data(){
    if (bmp280_read_float(&dev, &data.temperature, &data.pressure, &data.humidity) != ESP_OK){
        ESP_LOGI(SensorTAG, "Temperature/pressure reading failed\n");
    }

    ESP_LOGI(SensorTAG, "Pressure: %.2f Pa, Temperature: %.2f C", data.pressure, data.temperature);
    if (bme280p)
        ESP_LOGI(SensorTAG, ", Humidity: %.2f\n", data.humidity);
    else
        ESP_LOGI(SensorTAG, "\n");

    return ESP_OK;
}

esp_err_t get_sensors_data(float *temperature, float *pressure, float *humidity, u_int8_t *luminosity){
    *temperature = data.temperature;
    *pressure = data.pressure;
    *humidity = data.humidity;
    *luminosity = data.luminosity;

    ESP_LOGI(SensorTAG, "Valores retornados com sucesso");

    return ESP_OK;
}

char * get_serialize_sensors_data(){
    char *payload;

    payload = (char *)malloc(60);

    sprintf(payload, "{\"temp\":%.2f,\"humi\":%.2f,\"lumi\":%d,\"pres\":%.2f}", \
        data.temperature, data.humidity, data.luminosity, data.pressure);

    ESP_LOGI(SensorTAG, "Payload retornado com sucesso");

    return payload;
}

esp_err_t init_sensors(){
    ESP_LOGI(SensorTAG, "Iniciando Sensores");

    ESP_LOGI(SensorTAG, "Iniciando Sensores Analogicos");

    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_12Bit));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ldr, ADC_ATTEN_DB_11));

    ESP_LOGI(SensorTAG, "Sensores Analogicos Iniciados com sucesso");

    ESP_LOGI(SensorTAG, "Iniciando Sensores I2C");

    ESP_LOGI(SensorTAG, "Iniciando I2C");

    ESP_ERROR_CHECK(i2cdev_init());

    ESP_LOGI(SensorTAG, "I2C Iniciada com sucesso");

    bmp280_init_default_params(&params);

    memset(&dev, 0, sizeof(bmp280_t));

    ESP_LOGI(SensorTAG, "Iniciando bmp280");

    ESP_ERROR_CHECK(bmp280_init_desc(&dev, BMP280_I2C_ADDRESS_0, 0, SDA_PIN, SCL_PIN));
    ESP_ERROR_CHECK(bmp280_init(&dev, &params));

    ESP_LOGI(SensorTAG, "BMP280 iniciado");

    bme280p = dev.id == BME280_CHIP_ID;
    ESP_LOGI(SensorTAG, "BMP280: found %s\n", bme280p ? "BME280" : "BMP280");

    ESP_LOGI(SensorTAG, "Sensores I2C Iniciados com sucesso");

    return ESP_OK;
}

SensorData getStructData(){
    return data;
}