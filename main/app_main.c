#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "app_main";

#define BLINK_GPIO 5
#define CONFIG_BLINK_PERIOD 1000
#define HIGH_LEVEL_MS 200

static void blink_led(void *pvParameter)
{
    bool s_led_state = false;
    while (1)
    {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state ? "ON" : "OFF");
        gpio_set_level(BLINK_GPIO, s_led_state);
        TickType_t delay_time = s_led_state ? HIGH_LEVEL_MS : (CONFIG_BLINK_PERIOD - HIGH_LEVEL_MS);
        s_led_state = !s_led_state;
        vTaskDelay(pdMS_TO_TICKS(delay_time));
    }
}

void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    ESP_LOGI(TAG, "App started.");
    
    ESP_LOGI(TAG, "Configuring LED GPIO...");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    ESP_LOGI(TAG, "Configuration done.");
    
    xTaskCreate(blink_led, "led_blink_task", 2048, NULL, 5, NULL);
}