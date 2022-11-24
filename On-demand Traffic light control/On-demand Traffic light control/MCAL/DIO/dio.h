/*
 * dio.h
 *
 * Created: 11/11/2022 4:40:50 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../UTILITIES/types.h"
#include "../../UTILITIES/registers.h"

// macros/enums
enum ports {PORT_A, PORT_B, PORT_C, PORT_D};
enum pinDirection {INPUT = 0, OUTPUT = 1};
enum pinValue {LOW = 0, HIGH = 1};
typedef enum DIO_ERR {DIO_OK, WRONG_PORT, WRONG_PIN, WRONG_DIRECTION, WRONG_VALUE} DIO_ERR;
	
// helper macro functions
#define SET_BIT(pinNumber, portNumber) portNumber |= (1<<pinNumber)
#define CLEAR_BIT(pinNumber, portNumber) portNumber &= ~(1<<pinNumber)

// DIO manipulation functions
DIO_ERR DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
DIO_ERR DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
DIO_ERR DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
DIO_ERR DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* DIO_H_ */