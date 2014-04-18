#include <avr/io.h>
#include "drv_gpio.h"
void initGPIO() {
	DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD5) | (1<<PD4); //tied high. PD2 and PD3 control MAX4311 video multiplexer
	DDRB |= (1<<PB5);
	PORTD |= (1 << PD4); // Enabled video multiplexer
	PORTB |= (1 << PB5);
	updateVideoOutputSelectionOnGPIO(4); // Default channel set to Four. Due to internal receiver
}
//Sets the outputs PD2 and PD3 depending on which RSSI signal is strongest
// Could do it with one mask but easier to break, strongest Channel function can return 0!
void updateVideoOutputSelectionOnGPIO(uint8_t strongestChannel) {
	switch (strongestChannel) {
	case 1:
		PORTD &= ~(1 << PD3) & ~(1 << PD2);
		break;
	case 2:
		PORTD &= ~(1 << PD3);
		PORTD |= (1 << PD2);
		break;
	case 3:
		PORTD &= ~(1 << PD2);
		PORTD |= (1 << PD3);
		break;
	case 4:
		PORTD |= (1 << PD3) | (1 << PD2);
		break;
	default:
		PORTD |= PORTD |= (1 << PD3) | (1 << PD2);
		break;
	}
}
