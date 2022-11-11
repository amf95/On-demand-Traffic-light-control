
#include "button.h"

void BUTTON_init(uint8_t pinNumber, uint8_t portNumber){
    DIO_init(pinNumber, portNumber, INPUT);
}

void BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *vlaue){
    DIO_read(pinNumber, portNumber, vlaue);
}