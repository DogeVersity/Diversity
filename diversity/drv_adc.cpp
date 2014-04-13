#include <avr/io.h>
#include <avr/interrupt.h>
#include "drv_adc.h"
ISR(ADC_vect) {

	switch ADMUX {
		case 0x40: // ADMUX top 4 bits set to 0x4 and bottom set depending on which channel is read
		RSSI.channelOne=readADCRegisters();
		ADMUX=0x41; // Read Channel Two next
		break;
		case 0x41:
		RSSI.channelTwo=readADCRegisters();
		ADMUX=0x42; //Read Channel Three next
		break;
		case 0x42:
		RSSI.channelThree=readADCRegisters();
		ADMUX=0x43; //Read Channel Four next;
		break;
		case 0x43:
		RSSI.channelFour=readADCRegisters();
		ADMUX=0x40; //Read Channel One next
		break;
	}

}

void initializeADC(void) {
	ADMUX |= (1 << REFS0); //VCC used as AREF
	ADCSRA |= (1 << ADIE) | (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1)
			| (1 << ADPS2); //125kHz clock, ADC interrupt enabled
	sei();
	// enable global interrupts
	ADCSRA |= 1 << ADSC; // Enable adc conversion

}

uint16_t readADCRegisters(void) {
	uint8_t lowBits = ADCL;
	return (ADCH << 8 | lowBits);
}

uint8_t decideVideoOutput(void) { //Returns 0 if there is a problem along the way i.e all RSSI values are the same
	if ((RSSI.channelOne > RSSI.channelTwo) && (RSSI.channelOne > RSSI.channelThree) && (RSSI.channelOne > RSSI.channelFour)) {
		return 1;
	}
	else if ((RSSI.channelTwo > RSSI.channelOne) && (RSSI.channelTwo > RSSI.channelThree) && (RSSI.channelTwo > RSSI.channelFour)) {
		return 2;
	}
	else if ((RSSI.channelThree > RSSI.channelOne) && (RSSI.channelThree > RSSI.channelTwo) && (RSSI.channelThree > RSSI.channelFour)) {
		return 3;
	}
	else if ((RSSI.channelFour > RSSI.channelOne) && (RSSI.channelFour > RSSI.channelTwo) && (RSSI.channelFour > RSSI.channelThree)) {
		return 4;
	}
	else
		return 0;

}
