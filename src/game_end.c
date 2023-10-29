#include "game_end.h"

extern uint8_t length;
extern position snake[37];

// check if the snake bites its own body
// return value == 1: collision
// return value == 0: no collision
uint8_t collided(void) {
	uint8_t return_value = 0;
	for(uint8_t i =1; i < length; i++) {
		// checks if the snake's head and any of the body parts are on the same segment
		if(snake[0].dig_pos == snake[i].dig_pos && snake[0].seg_pos == snake[i].seg_pos) {
			return_value = 1;
			break;
		}
	}
	return return_value;
}

// if the game ends, the decimal points are blinking
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
		// em_lcd.c --> void LCD_SegmentSetLow(int com, uint32_t mask, uint32_t bits)
		 // 0xA0001000, 0x1000, 0x1001 : setting only the decimal points
		  LCD_SegmentSetLow(7, 0xF00FF000, 0xA0001000);
		  LCD_SegmentSetLow(6, 0xF00FF000, 0x1000);
		  LCD_SegmentSetLow(5, 0xF00FF000, 0x1001);
		  Delay(3);

		  // 0x0 : clearing the lower display
		  LCD_SegmentSetLow(7, 0xF00FF000, 0x0);
		  LCD_SegmentSetLow(6, 0xF00FF000, 0x0);
		  LCD_SegmentSetLow(5, 0xF00FF000, 0x0);
		 Delay(3);
	}
}

void game_end(void) {
	//LESENSE_IntDisable(0x10000);
	clear_lower_lcd_screen();
	blink_decimal_points();
}
