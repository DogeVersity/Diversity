

#ifndef DRV_GPIO_H_
#define DRV_GPIO_H_

void initGPIO(void); // Sets up the GPIO for the video multiplexer
void updateVideoOutputSelectionOnGPIO(uint8_t strongestChannel); // Updates PD2 and PD3 depending on which RSSI channel has the strongest signal



#endif /* DRV_GPIO_H_ */
