#include "game_handler.h"

extern position snake[];
extern uint8_t length;
extern enum dir direction;
//extern position apple;
extern enum dir prev_direction;
extern SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

// Increase the digit position of a given part of the snake
void inc_dig_pos(int index) {
	if(snake[index].dig_pos == 6) {
		snake[index].dig_pos = 0;
	}
	else {
		snake[index].dig_pos++;
	}
}

// Decrease the digit position of a given part of the snake
void dec_dig_pos(int index) {
	if(snake[index].dig_pos == 0) {
		snake[index].dig_pos = 6;
	}
	else {
		snake[index].dig_pos--;
	}
}

// Perform 1 tile move based on head position, and desired direction
void move(void) {
	// Move all parts of the snake forward, except the head
	for(int i = length - 1; i<0; i--) {
		snake[i].dig_pos = snake[i-1].dig_pos;
		snake[i].seg_pos = snake[i-1].seg_pos;
	}
	// Currently in a horizontal row
	switch(snake[0].seg_pos) {
		// Top horizontal, only possible directions are up, down, or right
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
						}
						inc_dig_pos(0);
					}
					else {
						// Stays on the same digit
						snake[0].seg_pos = 5;
					}
					break;
				// Snake can not turn 180 degrees, no need to scheck prev. direction
				case LEFT:
					dec_dig_pos(0);
					break;
				case RIGHT:
					inc_dig_pos(0);
					break;
			}
			break;
		// Middle horizontal
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
		// Top vertical, only possible previous
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
		// Bottom vertial
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

void show_snake(void) {
	for(int i = 0; i < length; i++) {
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
	snake[0].dig_pos = 1;
	snake[0].seg_pos = 6;

	int timer = 900000;
	while(1) {
		own_timer(timer);
	}

}
