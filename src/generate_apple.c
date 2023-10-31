#include "generate_apple.h"

extern position apple;
extern position snake[37];
extern uint8_t length;

extern SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

uint8_t temp_dig;
uint8_t temp_seg;

const uint8_t segments_in_digit_1_to_6[5] = {0,3,4,5,6};			// Possible segments in case of digits 1 to 6
const uint8_t segments_in_digit_7[7] = {0,3,4,5,6,1,2};				// Possible segments for digit 7

// Randomly generates the apple's position on the LCD
void generate_apple(void) {
	// Digit 1 is represented by index 0, ... , digit 7 is represented by index 6

	uint8_t failed_generation = 1;
	while(failed_generation) {
		temp_dig = rand() % 7;

		// Digit 7
		if(temp_dig == 6) {
			temp_seg = segments_in_digit_7[rand()%7];
		}
		// Digit 1 to 6
		else {
			temp_seg = segments_in_digit_1_to_6[rand()%5];
		}
		failed_generation = 0;
		// failed_generation increases if the snake's position is conflicting the newly generated apple
		// if so, the while cycle generates a new one
		for(uint8_t i = 0; i < length; i++) {
			if(snake[i].dig_pos == temp_dig && snake[i].seg_pos == temp_seg) {
				failed_generation++;
			}
		}
	}
	// The previously tested new apple position is set for the apple
	apple.dig_pos = temp_dig;
	apple.seg_pos = temp_seg;
}

// Prints the apple on the LCD display
void show_apple(void) {
	// Switch case for the segment positions
	switch(apple.seg_pos) {
	case 0:
		lowerCharSegments[apple.dig_pos].a = 1;
		break;
	case 1:
		lowerCharSegments[apple.dig_pos].b = 1;
		break;
	case 2:
		lowerCharSegments[apple.dig_pos].c = 1;
		break;
	case 3:
		lowerCharSegments[apple.dig_pos].d = 1;
		break;
	case 4:
		lowerCharSegments[apple.dig_pos].e = 1;
		break;
	case 5:
		lowerCharSegments[apple.dig_pos].f = 1;
		break;
	case 6:
		lowerCharSegments[apple.dig_pos].g = 1;
		lowerCharSegments[apple.dig_pos].m = 1;
		break;
	}
	SegmentLCD_LowerSegments(lowerCharSegments);			// Print to the LCD
}
