#include "timer_handler.h"

void own_timer(int duration)
{
	for(int i = 0; i < duration; i++)
	{}
	move();
	clear_lower_lcd_screen();
	show_snake();
}
