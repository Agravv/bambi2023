#ifndef GAME_END_H
#define GAME_END_H

#include "em_device.h"
#include "em_chip.h"
#include "lcd_handler.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include "game_variables.h"

uint8_t collided(void);
void blink_decimal_points(void);

#endif
