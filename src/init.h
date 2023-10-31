#ifndef INIT_H
#define INIT_H

#include "em_cmu.h"
#include "em_lcd.h"
#include "em_lesense.h"
#include "caplesense.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include "game_variables.h"

void SysTick_Handler(void);
void Delay(uint32_t dlyTicks);
void init_elsense(void);
void init_lcd(void);
void init(void);

#endif
