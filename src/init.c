#include "init.h"

volatile int slidePos;
void scanCb(void) {
	slidePos = CAPLESENSE_getSliderPosition();
	if(slidePos > 24) {

	} else if (slidePos <= 24 && slidePos > -1) {

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
