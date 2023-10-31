#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include "game_variables.h"
#include "game_end.h"
#include "display_snake_length.h"
#include "generate_apple.h"
#include "move_handler.h"

void dec_dig_pos(uint8_t index);
void inc_dig_pos(uint8_t index);
void move(void);
void show_snake(void);
void game(void);

#endif
