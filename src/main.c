#include "em_chip.h"
#include "segmentlcd.h"
#include "init.h"
#include "display_snake_length.h"
#include "game_handler.h"
#include "lcd_handler.h"
#include "game_variables.h"

SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

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
