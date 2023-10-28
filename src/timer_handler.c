#include "timer_handler.h"
extern enum dir prev_direction;
extern enum dir direction;

void own_timer(int duration)
{
	for(int i = 0; i < duration; i++)
		{}
	LESENSE_IntDisable(0x10000);
	move();
	prev_direction = direction;
	clear_lower_lcd_screen();
	show_snake();
	LESENSE_IntEnable(0x10000);


}
