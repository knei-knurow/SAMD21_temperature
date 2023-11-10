/*
 * SAMD21_onewire.c
 *
 * Created: 10.11.2023 18:06:15
 *  Author: Komputer_3
 */ 

#include "SAMD21_onewire.h"
#include "driver_init.h"

void Onewire_ResetPulse() {
	gpio_set_pin_direction(TEMP, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(TEMP, false);
	delay_us(500);
	gpio_set_pin_direction(TEMP, GPIO_DIRECTION_IN);
}