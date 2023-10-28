/* Device Support Library */
#include "em_device.h"
#include "em_chip.h"

#include "em_emu.h"
#include "em_cmu.h"
#include "em_lcd.h"
#include "em_gpio.h"
//#include "gpiointerrupt.c"
#include "em_rtc.h"
#include "segmentlcd.h"
#include "em_lesense.h"

/* Drivers */
#include "vddcheck.h"
#include "caplesense.h"

#include "bsp.h"

#include "game_handler.h"
#include "display_snake_length.h"
#include "game_end.h"
#include "generate_apple.h"

typedef struct position {
	uint8_t dig_pos;
	uint8_t seg_pos;
} position;

enum dir {
	right, left, up, down
};

position snake[37];
uint8_t length = 1;
enum dir direction = right;

position apple;




int main(void)
{
  /* Chip errata */
  CHIP_Init();

  init();

  /* Infinite loop */
  while (1) {
	  	  game();
  }
