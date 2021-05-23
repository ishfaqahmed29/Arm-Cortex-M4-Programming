#include "mbed.h"	

#define JOY_UP PA_4	
#define JOY_RIGHT PC_0	
#define JOY_CENTER PB_5	
#define JOY_LEFT PC_1	
#define RED_LED PB_4	
#define GREEN_LED PC_7	
#define BLUE_LED PA_9	

// Output LEDs
DigitalOut LED_out_red(RED_LED);	
DigitalOut LED_out_green(GREEN_LED);
DigitalOut LED_out_blue(BLUE_LED);

// Input Joystick Interrupts 
InterruptIn button_up(JOY_UP);	
InterruptIn button_right(JOY_RIGHT);	
InterruptIn button_center(JOY_CENTER);	
InterruptIn button_left(JOY_LEFT);	

// ISR for JOY_LEFT
void joy_left_handler()
{
	LED_out_red = !button_left; // red LED will blink
}

// ISR for JOY_RIGHT
void joy_right_handler()
{
	LED_out_green = !button_right;	// green LED will blink
}

// ISR for JOY_UP
void joy_up_handler()
{
	LED_out_blue = !button_up;	// blue LED will blink
}

// ISR for JOY_CENTER
void joy_center_handler()
{
	// all LEDs will blink to give colour white
	LED_out_blue = !button_center;
	LED_out_green = !button_center;
	LED_out_red = !button_center;
}

int main()
{
	__enable_irq();
	
	// initially turn off all LEDs
	LED_out_blue = 1;
	LED_out_green = 1;
	LED_out_red = 1;
	
	// Attach the address of the ISR to the rising edge
	button_up.rise(&joy_up_handler);
	button_right.rise(&joy_right_handler);
	button_left.rise(&joy_left_handler);
	button_center.rise(&joy_center_handler);

	// Attach the address of the ISR to the falling edge
	button_up.fall(&joy_up_handler);
	button_right.fall(&joy_right_handler);	
	button_left.fall(&joy_left_handler);
	button_center.fall(&joy_center_handler);	
	
	// sleep on exit
	while(1)
	{
		__wfi(); // wait for interrupt to reduce power consumption
	}
}
