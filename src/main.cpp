#include <Arduino.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "ST7735_LCD/ST7735.h"

#define CONFIG_ST7735_HOST_SUPERMINI

// #define CONFIG_IDF_TARGET_ESP32

#define PIN_LED_BUILTIN 8U

void setup() {
  gpio_pad_select_gpio(PIN_LED_BUILTIN);
  gpio_set_direction((gpio_num_t)PIN_LED_BUILTIN, GPIO_MODE_OUTPUT);
  st7735_init();
  st7735_invert_color(1);
  // st7735_draw_string(5, 5, "Teste TFT", COLOR_BLUE, COLOR_BLACK, 9);
}

void loop() {
  gpio_set_level((gpio_num_t)PIN_LED_BUILTIN, 1);
  ESP_LOGI("","LED ligado");
  delay(500);
  gpio_set_level((gpio_num_t)PIN_LED_BUILTIN, 0);
  ESP_LOGI("","LED desligado");
  delay(500);
}
