#ifndef GAME_VARIABLES_H
#define GAME_VARIABLES_H

#include "em_device.h"
#include "em_chip.h"

// contains information about apple's and the snake's position on the LCD
typedef struct pos {
	uint8_t dig_pos;					// digit from 1 to 7
	uint8_t seg_pos;				// segment from 0 to 6
} position;

//*    --------- 0,a --------
//*
//*   |     \7,h  |8,j     /        |
//*   |5,f   \     |      /9,k      |1,b
//*   |         \   |   /              |
//*
//*    --- 6,g --   -- 10,m --
//*
//*   |        /       |      \11,n |
//*   |4,e  /13,q |12,p \      |2,c
//*   |    /           |          \     |
//*
//*    --------- 3,d --------

enum dir {
	RIGHT, LEFT, UP, DOWN
};

#endif
