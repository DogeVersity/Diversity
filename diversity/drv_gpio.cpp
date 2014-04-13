#include <avr/io.h>
#include "drv_gpio.h"
void initGPIO()
{
	DDRB|=(1<<PD2)|(1<<PD3)|(1<<PD4);// PD4 is active low Shutdown, tied high. PD2 and PD3 control MAX4311 video multiplexer
	PORTB|=(1<<PD4); // Enabled video multiplexer
	updateVideoOutputSelectionOnGPIO(4); //Default channel set to Four. Due to internal receiver


}
//Sets the outputs PB2 and PB3 depending on which RSSI signal is strongest
// Could do it with one mask but easier to break, strongest Channel function can return 0!
void updateVideoOutputSelectionOnGPIO(uint8_t strongestChannel)
{
	switch (strongestChannel){
	case 1:
		PORTB&=~(1<<PB3)&~(1<<PB2);
		break;
	case 2:
		PORTB&=~(1<<PB3);
		PORTB|=(1<<PB2);
		break;
	case 3:
		PORTB&=~(1<<PB2);
		PORTB|=(1<<PB3);
		break;
	case 4:
		PORTB|=(1<<PB3) |(1<<PB2);
		break;
	default:
		PORTB|=PORTB|=(1<<PB3) |(1<<PB2);
		break;
	}
}
