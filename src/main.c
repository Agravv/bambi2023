/* Device Support Library */
#include "em_device.h"
#include "em_chip.h"

#include "em_emu.h"
#include "em_cmu.h"
#include "em_lcd.h"
#include "em_gpio.h"
#include "em_rtc.h"

/* Drivers */
#include "vddcheck.h"
#include "caplesense.h"

#include "bsp.h"


int main(void)
{
  /* Chip errata */
  CHIP_Init();

  CAPLESENSE_Init(false);
  BSP_LedsInit();
  BSP_LedSet(1);

  /* Infinite loop */
  while (1) {
	  int sliderPos = CAPLESENSE_getSliderPosition();
	  if(sliderPos != -1) {
		  BSP_LedSet(1);
	  } else
		  BSP_LedClear(1);
  }
}
