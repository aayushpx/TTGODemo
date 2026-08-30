#include <stdint.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define GPIO_OUT_W1TS    0x60004008
#define GPIO_OUT_W1TC    0x6000400C
#define GPIO_ENABLE_W1TS 0x60004024
#define GPIO_IN          0x6000403C

volatile uint32_t *GPIO_OUTPUT_W1TS =
  (volatile uint32_t *)GPIO_OUT_W1TS;

volatile uint32_t *GPIO_OUTPUT_W1TC =
  (volatile uint32_t *)GPIO_OUT_W1TC;

volatile uint32_t *GPIO_ENABLE =
  (volatile uint32_t *)GPIO_ENABLE_W1TS;

volatile uint32_t *GPIO_INPUT =
  (volatile uint32_t *)GPIO_IN;

void app_main(void)
{
  *GPIO_ENABLE = (1 << 4);

  while (1) {

    uint32_t input = *GPIO_INPUT;

    if (input & (1 << 0)) {
      *GPIO_OUTPUT_W1TS = (1 << 4);
    } else {
      *GPIO_OUTPUT_W1TC = (1 << 4);
    }

    printf("GPIO0 = %lu\n",
           (unsigned long)(input & 1));

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}
