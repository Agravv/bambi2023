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
#include "segmentlcd_individual.h"

/* Drivers */
#include "vddcheck.h"

#include "bsp.h"

#include "init.h"
#include "game_handler.h"
#include "display_snake_length.h"
#include "game_end.h"
#include "generate_apple.h"

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
	  	  //game();

	  // random apple gen function test code
//							  generate_apple();
//							  show_apple();
  }}
