#include "lcd_handler.h"

extern SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[];
extern SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[];

// clears any input on the lower LCD
void clear_lower_lcd_screen(void)
{
	for(uint8_t i = 0; i < SEGMENT_LCD_NUM_OF_LOWER_CHARS; i++) {
		lowerCharSegments[i].raw = 0;
	}
	SegmentLCD_LowerSegments(lowerCharSegments);
}

// clears any input on the upper LCD
void clear_upper_lcd_screen(void)
{
	for (uint8_t i = 0; i < SEGMENT_LCD_NUM_OF_UPPER_CHARS; i++){
		upperCharSegments[i].raw = 0;
	}
	SegmentLCD_UpperSegments(upperCharSegments);
}
