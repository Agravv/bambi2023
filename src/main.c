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

/* Drivers */
#include "vddcheck.h"
#include "caplesense.h"

#include "bsp.h"

volatile int slidePos;
void scanCb(void) {
	slidePos = CAPLESENSE_getSliderPosition();
	if(slidePos > 20) {
		BSP_LedSet(0);
		BSP_LedClear(1);
	} else if (slidePos < 20 && slidePos > -1) {
		BSP_LedClear(0);
		BSP_LedClear(1);
	} else {
		BSP_LedSet(1);
		BSP_LedClear(0);
	}
}
void chCb(void) {

}

int main(void)
{
  /* Chip errata */
  CHIP_Init();
  SegmentLCD_Init(false);

  CAPLESENSE_Init(false);
  BSP_LedsInit();
  BSP_LedClear(0);
  BSP_LedClear(1);
  CAPLESENSE_setupCallbacks(scanCb, chCb);


  /* Infinite loop */
  while (1) {
	  	  int pos = CAPLESENSE_getSliderPosition();
	  	  SegmentLCD_Number(pos);
	  }
  }
