#include <avr/io.h>
#include "def.h"
#include "drv_led.h"
#include "drv_GPIO.h"
#include "drv_adc.h"
// By default starts with outputting internal video. Switches video source depending on RSSI
int main() {
	initGPIO();
	initLed();
	initializeADC();
	while (true) { // Dogeversity prouds itself on performance and only uses an interrupt driven approach.

	}
}
