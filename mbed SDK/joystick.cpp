#include "mbed.h"	

#define JOY_UP PA_4		
#define JOY_RIGHT PC_0	
#define JOY_CENTER PB_5	
#define JOY_LEFT PC_1	
#define RED_LED PB_4	
#define GREEN_LED PC_7	
#define BLUE_LED PA_9	

// Interface to read the joystick value from the digital pins defining the position of the joystick
BusIn my_bus_in(JOY_UP, JOY_RIGHT, JOY_LEFT, JOY_CENTER);

// Interface to create a number of digital out pins that can be read as one value
BusOut my_bus_out(BLUE_LED, GREEN_LED, RED_LED);

int main()
{
    while(1)
	{
		// check which switch was pressed and light up the corresponding LED(s)
		if(my_bus_in == 0x8)			// if JOY_CENTER pressed up, turn all LED colours on
			my_bus_out = 0;				
		else
			my_bus_out = ~my_bus_in;	// toggle the LEDs according to input
	}
}
