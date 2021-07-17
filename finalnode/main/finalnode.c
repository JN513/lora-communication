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

#include "mqtt_client.h"
#include "lmic.h"

#include "get_sensors_data.h"

const char *TAG = "finalnode";

gpio_num_t led = GPIO_NUM_2;

void setup(void);

void app_main(void){
    // Iniciando sistema

    setup();
}

void setup(void){
    // Iniciando configurações

    ESP_LOGI(TAG, "Iniciando Configurações...");

    // Iniciando Sensores

    ESP_ERROR_CHECK(init_sensors());
}
