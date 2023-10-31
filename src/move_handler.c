#include "move_handler.h"

extern enum dir direction;
extern enum dir prev_direction;
extern position snake[37];
extern uint8_t length;
extern position apple;

// Touch slider input
void lesense_input(void) {
	int slidePos = CAPLESENSE_getSliderPosition();
	// The maximum value of the touch slider's input is 48
	// This occurs when the right end of the slider is touched
	if(slidePos > 24) {
		switch(direction) {
		case 0: 								// Current direction: RIGHT
			direction = DOWN;					// New direction
			prev_direction = RIGHT;				// Previous direction
			break;
		case 1: 								// Current direction: LEFT
			direction = UP;						// New direction
			prev_direction = LEFT;				// Previous direction
			break;
		case 2:									// Current direction: UP
			direction = RIGHT;					// New direction
			prev_direction = UP; 				// Previous direction
			break;
		case 3:									// Current direction: DOWN
			direction = LEFT;					// New direction
			prev_direction = DOWN;				// Previous direction
			break;
		}
	}
	// If the left end of the slider is touched
	else if (slidePos <= 24 && slidePos > -1) {
		switch(direction) {
				case 0:							// Current direction: RIGHT
					direction = UP;				// New direction
					prev_direction = RIGHT;		// Previous direction
					break;
				case 1:							// Current direction: LEFT
					direction = DOWN;			// New direction
					prev_direction = LEFT;		// Previous direction
					break;
				case 2:							// Current direction: UP
					direction = LEFT;			// New direction
					prev_direction = UP;		// Previous direction
					break;
				case 3:							// Current direction: DOWN
					direction = RIGHT;			// New direction
					prev_direction = DOWN;		// Previous direction
					break;
				}
	}
	// If we don't touch the slider at all
	else if(slidePos == -1) {
		prev_direction = direction;
	}
}

// Increase the digit position of a given part of the snake
void inc_dig_pos(uint8_t index) {
	if(snake[index].dig_pos == 6) {
		snake[index].dig_pos = 0;
	}
	else {
		snake[index].dig_pos++;
	}
}

// Decrease the digit position of a given part of the snake
void dec_dig_pos(uint8_t index) {
	if(snake[index].dig_pos == 0) {
		snake[index].dig_pos = 6;
	}
	else {
		snake[index].dig_pos--;
	}
}

// Perform 1 tile move based on head position, and desired direction
void move(void) {
	if(snake[0].dig_pos == apple.dig_pos && snake[0].seg_pos == apple.seg_pos) {
		snake[length].dig_pos = snake[length-1].dig_pos;
		snake[length].seg_pos = snake[length-1].seg_pos;
	}
	// Move all parts of the snake forward, except the head
	for(uint8_t i = length - 1; i>0; i--) {
		snake[i].dig_pos = snake[i-1].dig_pos;
		snake[i].seg_pos = snake[i-1].seg_pos;
	}
	if(snake[0].dig_pos == apple.dig_pos && snake[0].seg_pos == apple.seg_pos) {
		length++;
		generate_apple();
	}
	switch(snake[0].seg_pos) {
		// Top horizontal
		// Only possible previous directions are left or right
		case 0:
			switch(direction) {
				case UP:
					if(prev_direction == RIGHT) {
						// Digit 7 is an exceptional case with 2 extra segments
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 2;
						}
						else {
							// Moves 1 digit to the right to reach the correct segment
							snake[0].seg_pos = 4;
							inc_dig_pos(0);
						}
					}
					// If direction was not right, then it must have been left
					else {
						// Stays on the same digit
						snake[0].seg_pos = 4;
					}
					break;
				case DOWN:
					if(prev_direction == RIGHT) {
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 1;
						}
						else {
							// Moves 1 digit to the right to reach the correct segment
							snake[0].seg_pos = 5;
							inc_dig_pos(0);
						}
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 5;
					}
					break;
				// Snake can not turn 180 degrees, no need to check prev. direction
				case LEFT:
					dec_dig_pos(0);
					break;
				case RIGHT:
					inc_dig_pos(0);
					break;
			}
			break;
		// Middle horizontal (6-g, 10-m segment)
		case 6:
			switch(direction) {
				case UP:
					if(prev_direction == RIGHT) {
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 1;
						}
						else {
							// Moves 1 digit to the right to reach the correct segment
							snake[0].seg_pos = 5;
							inc_dig_pos(0);
						}
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 5;
					}
					break;
				case DOWN:
					if(prev_direction == RIGHT) {
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 2;
						}
						else {
							// Moves 1 digit to the right
							snake[0].seg_pos = 4;
							inc_dig_pos(0);
						}
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 4;
					}
					break;
				case LEFT:
					dec_dig_pos(0);
					break;
				case RIGHT:
					inc_dig_pos(0);
					break;
			}
			break;
		// Bottom horizontal
		case 3:
			switch(direction) {
				case UP:
					if(prev_direction == RIGHT) {
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 2;
						}
						else {
							// Moves 1 digit to the right to reach the correct segment
							snake[0].seg_pos = 4;
							inc_dig_pos(0);
						}
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 4;
					}
					break;
				case DOWN:
					if(prev_direction == RIGHT) {
						if(snake[0].dig_pos == 6) {
							snake[0].seg_pos = 1;
						}
						else {
							// Moves 1 digit to the right to reach the correct segment
							snake[0].seg_pos = 5;
							inc_dig_pos(0);
						}
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 5;
					}
					break;
				case LEFT:
					dec_dig_pos(0);
					break;
				case RIGHT:
					inc_dig_pos(0);
					break;
			}
			break;
		// Bottom vertical
		case 4:
			switch(direction) {
				case UP:
					snake[0].seg_pos = 5;
					break;
				case DOWN:
					snake[0].seg_pos = 5;
					break;
				case LEFT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 6;
						dec_dig_pos(0);
					}
					else {
						snake[0].seg_pos = 3;
						dec_dig_pos(0);
					}
					break;
				case RIGHT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 6;
					}
					else {
						snake[0].seg_pos = 3;
					}
					break;
			}
			break;
		// Top vertical
		case 5:
			switch(direction) {
				case UP:
					snake[0].seg_pos = 4;
					break;
				case DOWN:
					snake[0].seg_pos = 4;
					break;
				case LEFT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 0;
						dec_dig_pos(0);
					}
					else {
						snake[0].seg_pos = 6;
						dec_dig_pos(0);
					}
					break;
				case RIGHT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 0;
					}
					else {
						snake[0].seg_pos = 6;
					}
					break;
			}
			break;
		// On digit 7, it is possible to be on segments number 1 and 2
		case 1:
			switch(direction) {
				case UP:
					snake[0].seg_pos = 2;
					break;
				case DOWN:
					snake[0].seg_pos = 2;
					break;
				case LEFT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 0;
					}
					else {
						snake[0].seg_pos = 6;
					}
					break;
				case RIGHT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 0;
						inc_dig_pos(0);
					}
					else {
						snake[0].seg_pos = 6;
						inc_dig_pos(0);
					}
					break;
			}
			break;
		case 2:
			switch(direction) {
				case UP:
					snake[0].seg_pos = 1;
					break;
				case DOWN:
					snake[0].seg_pos = 1;
					break;
				case LEFT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 6;
					}
					else {
						snake[0].seg_pos = 3;
					}
					break;
				case RIGHT:
					if(prev_direction == UP) {
						snake[0].seg_pos = 6;
						inc_dig_pos(0);
					}
					else {
						snake[0].seg_pos = 3;
						inc_dig_pos(0);
					}
					break;
			}
			break;
	}
}

void perform_moving(void)
{
	Delay(10);							// Provides a pleasant speed of play
	lesense_input();					// Registers the input from touch slider, changes the direction of the movement accordingly
	move();								// Executes the current step according to the given direction
	clear_lower_lcd_screen();
	show_snake();						// Print snake on the LCD
	show_apple();						// Print apple on the LCD
}
