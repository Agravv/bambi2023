//#include "timer_handler.h"
////extern enum dir prev_direction;
////extern enum dir direction;
//
//void own_timer(int duration)
//{
//	LESENSE_IntEnable(0x10000);
//
//	Delay(10);
//
//	LESENSE_IntDisable(0x10000);
//	move();
//	//prev_direction = direction;
//	clear_lower_lcd_screen();
//	show_snake();
//	show_apple();
//}
#include "timer_handler.h"
//extern enum dir prev_direction;
//extern enum dir direction;

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
