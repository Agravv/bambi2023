#include "init.h"

extern enum dir direction;
extern enum dir prev_direction;

// touch slider input
void lesense_input(void) {
	int slidePos = CAPLESENSE_getSliderPosition();
	// the maximum value of the touch slider's input is 48
	// if the touch the right end of the slider
	if(slidePos > 24) {
		switch(direction) {
		case 0: 											// current direction: RIGHT
			direction = DOWN;					// new direction
			prev_direction = RIGHT;			// previous direction
			break;
		case 1: 											// current direction: LEFT
			direction = UP;							// new direction
			prev_direction = LEFT;				// previous direction
			break;
		case 2:											// current direction: UP
			direction = RIGHT;					// new direction
			prev_direction = UP; 				// previous direction
			break;
		case 3:											// current direction: DOWN
			direction = LEFT;						// new direction
			prev_direction = DOWN;			// previous direction
			break;
		}
	}
	// if the touch the left end of the slider
	else if (slidePos <= 24 && slidePos > -1) {
		switch(direction) {
				case 0:									// current direction: RIGHT
					direction = UP;					// new direction
					prev_direction = RIGHT;	// previous direction
					break;
				case 1:									// current direction: LEFT
					direction = DOWN;			// new direction
					prev_direction = LEFT;		// previous direction
					break;
				case 2:									// current direction: UP
					direction = LEFT;				// new direction
					prev_direction = UP;			// previous direction
					break;
				case 3:									// current direction: DOWN
					direction = RIGHT;			// new direction
					prev_direction = DOWN;	// previous direction
					break;
				}
	}
	// if we dont touch the slider at all
	else if(slidePos == -1) {
		prev_direction = direction;
	}
}

volatile uint32_t msTicks; // counts 1ms timeTicks

void SysTick_Handler(void) {
	msTicks++;				 //  increment counter necessary in Delay()
}

// Delays number of msTick Systicks
void Delay(uint32_t dlyTicks) {
	uint32_t curTicks;
	curTicks = msTicks;
	while((msTicks- curTicks)<dlyTicks);
}

// initialising LCD display
void init_lcd(void) {
	//void SegmentLCD_Init(bool useBoost)
	// @param useBoost Set to use voltage boost
	SegmentLCD_Init(false);		// false == not using voltage boost
}

//Initializes the capacitive sense system without LESENSE.
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
