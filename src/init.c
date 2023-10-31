#include "init.h"


volatile uint32_t msTicks; // Counts 1ms timeTicks

void SysTick_Handler(void) {
	msTicks++;				 //  Increment counter necessary in Delay()
}

// Delays number of msTick Systicks
void Delay(uint32_t dlyTicks) {
	uint32_t curTicks;
	curTicks = msTicks;
	while((msTicks- curTicks)<dlyTicks);
}

// Initialise LCD display
void init_lcd(void) {
	// void SegmentLCD_Init(bool useBoost)
	// @param useBoost Set to use voltage boost
	SegmentLCD_Init(false);		// false == not using voltage boost
}

// Initializes the capacitive sense system without LESENSE.
void init_elsense(void) {
	// void CAPLESENSE_Init(bool sleep)
	// @param sleep If true, go into sleep mode.
	CAPLESENSE_Init(false);
}

void init(void) {
	CMU_HFRCOBandSet(cmuHFRCOBand_1MHz);

	// Setup SysTick Timer for 1 msec interrupts
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 10)) {
		while (1) ;
	}

	init_lcd();

	init_elsense();
}
