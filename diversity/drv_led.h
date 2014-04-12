#ifndef DRV_LED_H_
#define DRV_LED_H_

struct uint8_t_ledPwmValuesPercent { //Percent used
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

void initLed(void);
void updateLEDs(uint8_t_ledPwmValuesPercent ledvalues);
void setupGreenAndRedLEDs(void);
void setupBlueLED(void);
uint16_t convertPercentToCounterNumber_16Bit(uint8_t percentValue);
uint8_t convertPercentToCounterNumber_8Bit(uint8_t percentValue);

#endif /* DRV_LED_H_ */
