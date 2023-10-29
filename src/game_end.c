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
	// for some reason the DP6 decimal point wont blink
//	while(1) {
//		// Decimal points on
//		SegmentLCD_Symbol(LCD_SYMBOL_DP2, 1);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP3, 1);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP4, 1);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP5, 1);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP6, 1);
//
//		// delay
//		for(int i = 0; i < 300000; i++)
//		{}
//
//		// 	Decimal points off
//		SegmentLCD_Symbol(LCD_SYMBOL_DP2, 0);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP3, 0);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP4, 0);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP5, 0);
//		SegmentLCD_Symbol(LCD_SYMBOL_DP6, 0);
//
//		// delay
//		for(int i = 0; i < 300000; i++)
//		{}
//	}


	while(1) {
		 // 0xA0001000, 0x1000, 0x1001 : setting only the decimal points
		  LCD_SegmentSetLow(7, 0xF00FF000, 0xA0001000);
		  LCD_SegmentSetLow(6, 0xF00FF000, 0x1000);
		  LCD_SegmentSetLow(5, 0xF00FF000, 0x1001);

		  // delay
		  for(int i = 0; i < 300000; i++)
		  {}

		  // 0x0 : clearing the lower display
		  LCD_SegmentSetLow(7, 0xF00FF000, 0x0);
		  LCD_SegmentSetLow(6, 0xF00FF000, 0x0);
		  LCD_SegmentSetLow(5, 0xF00FF000, 0x0);
		  // delay
		  for(int i = 0; i < 300000; i++)
		  {}
	}
}

void game_end(void) {
	LESENSE_IntDisable(0x10000);
	blink_decimal_points();
}
