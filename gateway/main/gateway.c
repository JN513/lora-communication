#include <stdio.h>
#include <string.h>
#include <stdint.h>
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

#include "mqtt_client.h"
#include "lmic.h"

const char *TAG = "MQTT_GATEWAY";

const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rst = 14,
    .dio = { 26, 34, 35 },
    .spi = { /* MISO = */ 19, /* MOSI = */ 27, /* SCK = */ 5 },
    .rxtx = LMIC_UNUSED_PIN,
};


gpio_num_t led = GPIO_NUM_34;

TaskHandle_t mqtt_task;

void setup(void);

void app_main(void){
    printf("MQTT GATEWAY\n");
    ESP_LOGI(TAG, "Olá");

    // vTaskDelay(4000 / portTICK_PERIOD_MS);

    // esp_restart();
}

void setup(void) {

}
