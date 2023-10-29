#include "game_end.h"

extern int length;
extern position snake[37];

uint8_t collided(void) {
	int return_value = 0;
	for(int i =1; i < length; i++) {
		if(snake[0].dig_pos == snake[i].dig_pos && snake[0].seg_pos == snake[i].seg_pos) {
			return_value = 1;
			break;
		}
	}
	return return_value;
}

void blink_decimal_points(void) {
	while(1) {
		// Decimal points on
		SegmentLCD_Symbol(LCD_SYMBOL_DP2, 1);
		SegmentLCD_Symbol(LCD_SYMBOL_DP3, 1);
		SegmentLCD_Symbol(LCD_SYMBOL_DP4, 1);
		SegmentLCD_Symbol(LCD_SYMBOL_DP5, 1);
		SegmentLCD_Symbol(LCD_SYMBOL_DP6, 1);

		// delay
		for(int i = 0; i < 300000; i++)
		{}

		// 	Decimal points off
		SegmentLCD_Symbol(LCD_SYMBOL_DP2, 0);
		SegmentLCD_Symbol(LCD_SYMBOL_DP3, 0);
		SegmentLCD_Symbol(LCD_SYMBOL_DP4, 0);
		SegmentLCD_Symbol(LCD_SYMBOL_DP5, 0);
		SegmentLCD_Symbol(LCD_SYMBOL_DP6, 0);

		// delay
		for(int i = 0; i < 300000; i++)
		{}
	}
}
