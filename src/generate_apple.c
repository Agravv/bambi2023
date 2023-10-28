#include "generate_apple.h"

extern position apple;
extern position snake[37];
extern int length;

extern SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

uint8_t temp_dig;
uint8_t temp_seg;

const int seg_dig1_6[5] = {0,3,4,5,6};
const int seg_dig7[7] = {0,3,4,5,6,1,2};

void generate_apple(void) {
	int bad_gen = 1;
	while(bad_gen) {
		temp_dig = rand() % 7;
		if(temp_dig == 6) {
			temp_seg = seg_dig7[rand()%7];
		} else {
			temp_seg = seg_dig1_6[rand()%5];
		}
		bad_gen = 0;
		for(int i = 0; i < length; i++) {
			if(snake[i].dig_pos == temp_dig && snake[i].seg_pos == temp_seg) {
				bad_gen++;
			}
		}
	}
	apple.dig_pos = temp_dig;
	apple.seg_pos = temp_seg;
}

void show_apple(void) {
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
	SegmentLCD_LowerSegments(lowerCharSegments);
}
