/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD21 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define PINA0 GPIO(GPIO_PORTA, 2)
#define PINA1 GPIO(GPIO_PORTA, 4)
#define PINA4 GPIO(GPIO_PORTA, 8)
#define PINA5 GPIO(GPIO_PORTA, 9)
#define PINA2 GPIO(GPIO_PORTA, 10)
#define PINA3 GPIO(GPIO_PORTA, 11)
#define PINA6 GPIO(GPIO_PORTB, 8)
#define TEMP GPIO(GPIO_PORTB, 9)

#endif // ATMEL_START_PINS_H_INCLUDED
