#include "timer_handler.h"

void perform_moving(void)
{
	Delay(10);								//provides a pleasant speed of play
	lesense_input();						// registers the input from touch slider, changes the direction of the movement accordingly
	move();									// executes the current step according to the given direction
	clear_lower_lcd_screen();
	show_snake();						// printing snake on the LCD
	show_apple();						// printing apple on the LCD
}
