#include "display_snake_length.h"

extern uint8_t length;
extern SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];

void display_snake_length(void) {
	clear_upper_lcd_screen();

	// Format of the output:  01, 02, 03....
	uint8_t single = length % 10;
	uint8_t decimal = (uint8_t)(length/10);
	switch(single) {
			case 0:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				upperCharSegments[0].e = 1;
				upperCharSegments[0].f = 1;
				break;
			case 1:
				upperCharSegments[0].b = 1;
				upperCharSegments[0].c = 1;
				break;
			case 2:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].e = 1;
				upperCharSegments[0].d = 1;
				break;
			case 3:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				break;
			case 4:
				upperCharSegments[0].f = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].c = 1;
				break;
			case 5:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].f = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				break;
			case 6:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].f = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].e = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				break;
			case 7:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].c = 1;
				break;
			case 8:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				upperCharSegments[0].e = 1;
				upperCharSegments[0].f = 1;
				upperCharSegments[0].g = 1;
				break;
			case 9:
				upperCharSegments[0].a = 1;
				upperCharSegments[0].f = 1;
				upperCharSegments[0].b = 1;
				upperCharSegments[0].g = 1;
				upperCharSegments[0].c = 1;
				upperCharSegments[0].d = 1;
				break;
	}
	switch(decimal)
			{
				case 0:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					upperCharSegments[1].e = 1;
					upperCharSegments[1].f = 1;
					break;
				case 1:
					upperCharSegments[1].b = 1;
					upperCharSegments[1].c = 1;
					break;
				case 2:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].e = 1;
					upperCharSegments[1].d = 1;
					break;
				case 3:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					break;
				case 4:
					upperCharSegments[1].f = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].c = 1;
					break;
				case 5:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].f = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					break;
				case 6:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].f = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].e = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					break;
				case 7:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].c = 1;
					break;
				case 8:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					upperCharSegments[1].e = 1;
					upperCharSegments[1].f = 1;
					upperCharSegments[1].g = 1;
					break;
				case 9:
					upperCharSegments[1].a = 1;
					upperCharSegments[1].f = 1;
					upperCharSegments[1].b = 1;
					upperCharSegments[1].g = 1;
					upperCharSegments[1].c = 1;
					upperCharSegments[1].d = 1;
					break;
			}
	SegmentLCD_UpperSegments(upperCharSegments); // Format of the output:  01, 02, 03....
}
