#include "freertos/FreeRTOS.h"
#include "graphics.h"
#include "fonts.h"
void app_main(void)
{
  graphics_init();
  cls(0);
  setFont(FONT_DEJAVU18);
  print_xy("Hello World!", CENTER, CENTER);
  flip_frame();
  volatile uint32_t *en = (uint32_t *) 0x3FF44020;
  volatile uint32_t *out = (uint32_t *) 0x3FF44004;
  *en |= (1 << 4);    
  // Configure GPIO 4 as an output
  while (1) {
    *out |= (1 << 4);  // Set GPIO 4 HIGH
    vTaskDelay(pdMS_TO_TICKS(500));
    *out &= ~(1 << 4);  // Set GPIO 4 LOW
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
