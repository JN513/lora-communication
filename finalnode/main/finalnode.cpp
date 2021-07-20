#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"
#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "driver/gpio.h"
#include "driver/adc.h"

#include "get_sensors_data.h"

const char *TAG = "finalnode";

void setup(void);
void loop(void);

extern "C" void app_main(void){
    // Iniciando sistema

    setup();
    loop();
}

void setup(void){
    // Iniciando configurações

    ESP_LOGI(TAG, "Iniciando Configurações...");

    // Iniciando Sensores

    //ESP_ERROR_CHECK(init_sensors());

    // Iniciando Lora
}

void loop(void){
    // Iniciando loop
    ESP_LOGI(TAG, "Iniciando Loop");

    while(1){
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}