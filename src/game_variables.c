#include "game_variables.h"

											// array of the snake's positions
position snake[37];			// there are 37 playable segments on the LCD, so the snake can not be longer than 37

uint8_t length = 1;

enum dir direction = RIGHT;				// default value = RIGHT (it is starting from the left side of the screen and going right)

enum dir prev_direction = RIGHT;		// we initialise the previous direction to RIGHT, it is used by the move() function

position apple;										// contains the apple's position
