#include "mbed.h"	

# define Do     0.5	
# define Re     0.45	
# define Mi     0.4	
# define Fa     0.36	
# define So     0.33	
# define La     0.31	
# define Si     0.3	
# define No     0 	

# define b1     0.5	
# define b2     0.25	
# define b3     0.125	
# define b4     0.075	

// Array to store Jingle Bell Notes
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No, Mi,Re,No,Re,Mi, Re,No,So,No};

// Array to store beat lengths of Jingle Bells
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b4,b4,b4,b4, b2,b3,b3,b2,b2, b2,b2,b2,b2};
	
# define pot1 PA_0	
# define pot2 PA_1	
# define SPEAKER PB_10	
	
PwmOut speaker(SPEAKER);	
AnalogIn vol(pot1);	
	
PwmOut pwm_rgb(pot2);	
AnalogIn speed(pot2);	
	
#define RED_LED PB_4	
#define GREEN_LED PC_7	
#define BLUE_LED PA_9	

PwmOut red(RED_LED);	
PwmOut green(GREEN_LED);	
PwmOut blue(BLUE_LED);	

// Static variable for counter
	static int k;	

// Define the time ticker
	Ticker timer;

// Interrupt Service Routine
void timer_ISR()
{
	speaker.period(note[k]*0.01F);	
	timer.attach(&timer_ISR, beat[k]*(speed));	
	speaker.write(vol);	
	red.pulsewidth(note[k+1]);	
	green.pulsewidth(note[k+2]);	
	blue.pulsewidth(note[k+3]);	
	if(k==48)	
		k=0;	
	else
		k=k+1;	
} 

int main()
{
	timer.attach(&timer_ISR, 1);	
	
	while(1)
	{
		__wfi(); 
	}	
}
