#include "em_chip.h"
#include "segmentlcd.h"
#include "init.h"
#include "display_snake_length.h"
#include "game_handler.h"
#include "lcd_handler.h"
#include "game_variables.h"

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  init();

  /* Infinite loop */
  while (1) {
	  	  game();
  }
}
