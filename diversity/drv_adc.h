/*
 * drv_adc.h
 *
 *  Created on: 13 Apr 2014
 *      Author: Wills
 */

#ifndef DRV_ADC_H_
#define DRV_ADC_H_

struct uint16_t_RSSIReading{
	uint16_t channelOne; // Corresponds to RSSI for Video-1
	uint16_t channelTwo; // Corresponds to RSSI for Video-2
	uint16_t channelThree; //Corresponds to RSSI for Video-3
	uint16_t channelFour; // Corresponds to RSSI for Video-4 (Built in video receiver)
};
uint16_t_RSSIReading RSSI;// Stores RSSI for all channels
uint8_t decideVideoOutput(void);
uint16_t readADCRegisters(void);// Sets video source and returns which channel it is using.
void initializeADC(void); // Sets up ADC registers
#endif /* DRV_ADC_H_ */