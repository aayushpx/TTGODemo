// #include "freertos/FreeRTOS.h"
// #include "graphics.h"
// #include "fonts.h"
// void app_main(void)
// {
//   graphics_init();
//   cls(0);
//   setFont(FONT_DEJAVU18);
//   print_xy("Hello World!", CENTER, CENTER);
//   flip_frame();
//   volatile uint32_t *en = (uint32_t *) 0x3FF44020;
//   volatile uint32_t *out = (uint32_t *) 0x3FF44004;
//   *en |= (1 << 4);    
//   // Configure GPIO 4 as an output
//   while (1) {
//     *out |= (1 << 4);  // Set GPIO 4 HIGH
//     vTaskDelay(pdMS_TO_TICKS(500));
//     *out &= ~(1 << 4);  // Set GPIO 4 LOW
//     vTaskDelay(pdMS_TO_TICKS(500));
//   }
// }

#include <soc/uart_struct.h>
#include <esp_timer.h>
#include <graphics.h>
#include <fonts.h>
#include <driver/gpio.h>
void app_main() {
  graphics_init();
  uint64_t current_time, last_time=esp_timer_get_time();
  for(int i=0;i<135*240;i++) {
    frame_buffer[i]=i*2;
  }
  flip_frame();
  while(gpio_get_level(0));
  setFont(FONT_UBUNTU16);
  while(1) {
    cls(0);
    for(int i=0;i<10;i++) {
      draw_line(rand()%display_width,rand()%display_height,
                rand()%display_width,rand()%display_height,rand());
    }
    current_time = esp_timer_get_time();
    draw_rectangle(0,0,80,16,rgbToColour(30,30,100));
    gprintf("FPS:%.2f\n", 1.0e6f / (current_time - last_time));
    last_time = current_time;
    flip_frame();
  }
}
