#include "game_handler.h"

extern position snake[37];
extern uint8_t length;
extern SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];


// Prints the snake on the LCD display
void show_snake(void) {
	for(uint8_t i = 0; i < length; i++) {
		switch(snake[i].seg_pos) {
		case 0:
			lowerCharSegments[snake[i].dig_pos].a = 1;
			break;
		case 1:
			lowerCharSegments[snake[i].dig_pos].b = 1;
			break;
		case 2:
			lowerCharSegments[snake[i].dig_pos].c = 1;
			break;
		case 3:
			lowerCharSegments[snake[i].dig_pos].d = 1;
			break;
		case 4:
			lowerCharSegments[snake[i].dig_pos].e = 1;
			break;
		case 5:
			lowerCharSegments[snake[i].dig_pos].f = 1;
			break;
		case 6:
			lowerCharSegments[snake[i].dig_pos].g = 1;
			lowerCharSegments[snake[i].dig_pos].m = 1;
			break;
		}
	}
	SegmentLCD_LowerSegments(lowerCharSegments);
}

void game(void) {
	// Starting position
	snake[0].dig_pos = 0;
	snake[0].seg_pos = 6;

	generate_apple();						// Generate apple in a random position
	show_apple();							// Print the randomly generated apple to the LCD display
	show_snake();							// Print the snake to the LCD display

	// The game finishes, when the snake moves on itself
	while(!collided()) {
		display_snake_length();				// The length of the snake is shown on the upper LCD segment
		perform_moving();					// Move the snake across the segments according to the touch slider's input
	}
	game_end();								// Blink the decimal points, game ending state
}
