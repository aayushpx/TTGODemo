#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "graphics.h"
#include "fonts.h"
#include "driver/gpio.h"

void app_main(void) {
  graphics_init();
  cls(0);
  setFont(FONT_DEJAVU18);
  print_xy("Namaste", CENTER, CENTER);
  flip_frame();

  gpio_set_direction(38, GPIO_MODE_OUTPUT); // backlight

  while(1) {
    gpio_set_level(38, 1); 
    vTaskDelay(pdMS_TO_TICKS(500));
    gpio_set_level(38, 0); 
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
