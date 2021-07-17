#include "esp_log.h"
#include "esp_err.h"

#include "driver/gpio.h"
#include "driver/adc.h"

#include "bmp280.h"

#ifndef APP_CPU_NUM
#define APP_CPU_NUM PRO_CPU_NUM
#endif

#define SDA_PIN 21
#define SCL_PIN 22

#define SensorTAG "[ Sensors ]"
#define ldr ADC1_CHANNEL_5

typedef struct {
    float pressure; 
    float temperature; 
    float humidity; 
    u_int8_t luminosity;
} SensorData;


bmp280_params_t params;
bmp280_t dev;

bool bme280p;

SensorData data;

esp_err_t get_ldr_data();
esp_err_t get_bmp_data();
esp_err_t get_sensors_data(float *temperature, float *pressure, float *humidity, float *luminosity);
char* get_serialize_sensors_data();
esp_err_t init_sensors();
