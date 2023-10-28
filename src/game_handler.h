#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include "game_variables.h"
#include "timer_handler.h"
#include "segmentlcd.h"
#include "display_snake_length.h"
#include "segmentlcd_individual.h"

void dec_dig_pos(int index);
void inc_dig_pos(int index);
void move(void);
void show_snake(void);
void game(void);

#endif
