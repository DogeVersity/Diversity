#include <avr/io.h>
#include "def.h"
#include "drv_led.h"
#include "drv_GPIO.h"
// By default starts with outputting internal video. Switches video source depending on RSSI
int main()
{
	initGPIO();
	initLed();
	while (true) {

	}
}
