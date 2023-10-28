#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H

typedef struct pos {
	uint8_t dig_pos;
	uint8_t seg_pos;
} position;

enum dir {
	RIGHT, LEFT, UP, DOWN
};

#endif
