

#ifndef DRV_ADC_H_
#define DRV_ADC_H_
#include "drv_led.h"
struct uint16_t_RSSIReading{
	uint16_t channelOne; // Corresponds to RSSI for Video-1
	uint16_t channelTwo; // Corresponds to RSSI for Video-2
	uint16_t channelThree; //Corresponds to RSSI for Video-3
	uint16_t channelFour; // Corresponds to RSSI for Video-4 (Built in video receiver)
};
uint8_t decideVideoOutput(void);
uint16_t readADCRegisters(void);// Sets video source and returns which channel it is using.
void initializeADC(void); // Sets up ADC registers
uint8_t_ledPwmValuesPercent decideLEDColours(uint8_t strongestRSSIChannel);
#endif /* DRV_ADC_H_ */
