#include "game_end.h"

extern uint8_t length;
extern position snake[37];

// Check if the snake bites its own body
// Return value == 1: collision
// Return value == 0: no collision
uint8_t collided(void) {
	uint8_t return_value = 0;
	for(uint8_t i =1; i < length; i++) {
		// Checks if the snake's head and any of the body parts are on the same segment
		if(snake[0].dig_pos == snake[i].dig_pos && snake[0].seg_pos == snake[i].seg_pos) {
			return_value = 1;
			break;
		}
	}
	return return_value;
}

// If the game ends, the decimal points start blinking
void blink_decimal_points(void) {

	while(1) {
			// em_lcd.c --> void LCD_SegmentSetLow(int com, uint32_t mask, uint32_t bits)
			// Set the correct segments for blinking (decimal points)
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
	clear_lower_lcd_screen();
	blink_decimal_points();
}
