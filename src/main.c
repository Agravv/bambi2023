#include <stdlib.h>
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
	  // Generates a "random" seed for the srand() function via the touch slider input
	  // srand() sets the seed which is used by rand() in generate_apple.c to generate random numbers
	  // rand() call without srand() sets the seed to 1
	  int slider = CAPLESENSE_getSliderPosition();
	  if(slider != -1){			// slider == 1 when the touch slider is untouched
		  srand(slider);
		  game();
	  }
  }
}
