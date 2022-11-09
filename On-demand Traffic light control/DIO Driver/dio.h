

#ifndef DIO_H_
#define DIO_H_

#include "../types.h"

// all internal driver typdefs
// all driver macros
// all driver function prototypes

void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

enum ports {PORT_A, PORT_B, PORT_C, PORT_D};
enum pinDirection {INPUT = 0, OUTPUT = 1};
enum pinValue {LOW = 0, HIGH = 1};

#endif