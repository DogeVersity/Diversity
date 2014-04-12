
#include <avr/io.h>
#include "def.h"
#include "drv_led.h"

void initLed(void){
	uint8_t_ledPwmValuesPercent initialLEDPercentages ={100,100,100};
	setupGreenAndRedLEDs();
	setupBlueLED();
	updateLEDs(initialLEDPercentages);

}

void updateLEDs(uint8_t_ledPwmValuesPercent ledvalues)
{
	OCR1A=convertPercentToCounterNumber_16Bit(ledvalues.red);  //
	OCR1B=convertPercentToCounterNumber_8Bit(ledvalues.green);
	OCR2A=convertPercentToCounterNumber_8Bit(ledvalues.blue);
}

void setupGreenAndRedLEDs(void)
{
	//Setup for Red and Green LEDs, 8kHz pwm
	DDRB|=(1<<RED)|(1<<GREEN); // Enable Outputs for Red and Green LEDs
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1) | (1<<WGM11); // Set up PWM For PB1(red) and PB2(green). PB1 and PB2 toggle on compare match.
	TCCR1B|=(1 << WGM12)|(1 << WGM13); // Fast pwm non inverted.
	ICR1=0xffff; // ISCR1 used for "TOP", with ICR1 set to 0xffff, 16bit pwm can be used.
	TCCR1B |= (1 << CS11); // Start timer, clock divided by 8
}

void setupBlueLED(void)
{
	DDRB|=(1<<BLUE); // Enable output for Blue LED.
	TCCR2A |= (1 << WGM21) | (1 << WGM20) |(1<<COM2A1); // Fast pwm non inverted top = 0xff.
	TCCR2B |= (1 << CS21); // Divide clock by 8
}
uint16_t convertPercentToCounterNumber_16Bit(uint8_t percentValue) // For the 16 bit register (OCR1A and OCR1B)
{
	return (uint16_t)(percentValue/100)*0xffff;
}
uint8_t convertPercentToCounterNumber_8Bit(uint8_t percentValue){ // For the 8 bit register (OCR2)
	return (uint8_t)(percentValue/100)*0xff;
}
