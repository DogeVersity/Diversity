

#ifndef DEF_H_
#define DEF_H_

#define RSSI0 0 //RSSI Signal pin on PORTC from built in video receiver (V0)
#define RSSI1 1 //RSSI Signal pin 1 on PORTC from external RSSI pins (V1)
#define RSSI2 2 //RSSI Signal pin 2 on PORTC from external RSSI pins (V2)
#define RSSI3 3 //RSSI Signal pin 3 on PORTC from external RSSI pins (V3)

#define UpButton 7 //Pin for UP button on PORTD, active low. Pullups must be enabled.
#define DownButton 0 //Pin for DOWN button on PORTB, active low. Pullups must be enabled.

#define RED 1 // Pin for Red LED on PORTB
#define GREEN 2 //Pin for Green LED on PORTB
#define BLUE 3 //Pin for Blue LED on PORTB

#endif /* DEF_H_ */
