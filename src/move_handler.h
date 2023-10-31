#ifndef TIMER_HANDLER_H
#define TIMER_HANDLER_H

#include "generate_apple.h"
#include "game_variables.h"
#include "game_end.h"
#include "display_snake_length.h"

void lesense_input(void);
void perform_moving(void);
void inc_dig_pos(uint8_t index);
void dec_dig_pos(uint8_t index);
void move(void);

#endif
