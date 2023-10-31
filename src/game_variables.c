#include "game_variables.h"

										// Array of the snake's positions
position snake[37];						// There are 37 playable segments on the LCD, so the snake can not be longer than 37

uint8_t length = 1;						// The initial length of the snake is 1 segment

enum dir direction = RIGHT;				// Default value = RIGHT (it is starting from the left side of the screen and going right)

enum dir prev_direction = RIGHT;		// We initialise the previous direction to RIGHT, it is used by the move() function

position apple;							// Contains the apple's position

SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];
