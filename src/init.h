#ifndef INIT_H
#define INIT_H

#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "em_rtc.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include "game_handler.h"
#include "em_lcd.h"

#include "em_lesense.h"
#include "caplesense.h"
#include "game_variables.h"
#include "vddcheck.h"


void lesense_input(void);
void init_elsense(void);
void init_lcd(void);
void init(void);

#endif
