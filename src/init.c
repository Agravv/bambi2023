#include "init.h"

extern enum dir direction;
extern enum dir prev_direction;

volatile int slidePos;
void scanCb(void) {
	LESENSE_IntDisable(0x10000);
	slidePos = CAPLESENSE_getSliderPosition();
	if(slidePos > 24) {
		switch(direction) {
		case 0: 											// current direction: RIGHT
			direction = DOWN;					// new direction
			prev_direction = RIGHT;
			break;
		case 1: 											// current direction: LEFT
			direction = UP;							// new direction
			prev_direction = LEFT;
			break;
		case 2:											// current direction: UP
			direction = RIGHT;					// new direction
			prev_direction = UP;
			break;
		case 3:											// current direction: DOWN
			direction = LEFT;						// new direction
			prev_direction = DOWN;
			break;
		}
		//LESENSE_IntDisable(0x10000);
	} else if (slidePos <= 24 && slidePos > -1) {
		switch(direction) {
				case 0:									// current direction: RIGHT
					direction = UP;					// new direction
					prev_direction = RIGHT;
					break;
				case 1:									// current direction: LEFT
					direction = DOWN;			// new direction
					prev_direction = LEFT;
					break;
				case 2:									// current direction: UP
					direction = LEFT;				// new direction
					prev_direction = UP;
					break;
				case 3:									// current direction: DOWN
					direction = RIGHT;			// new direction
					prev_direction = DOWN;
					break;
				}
		//LESENSE_IntDisable(0x10000);
	} else if(slidePos == -1) {
		prev_direction = direction;
		LESENSE_IntEnable(0x10000);
	}

}

void chCb(void) {

}

void init_lcd(void) {
	SegmentLCD_Init(false);
}

void init_elsense(void) {
	CAPLESENSE_Init(false);
	CAPLESENSE_setupCallbacks(scanCb, chCb);
}

void init(void) {
	init_lcd();

	init_elsense();
}
