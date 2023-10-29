#include "timer_handler.h"

void own_timer(int duration)
{
	Delay(10);
	lesense_input();
	move();
	//prev_direction = direction;
	clear_lower_lcd_screen();
	show_snake();
	show_apple();
}
