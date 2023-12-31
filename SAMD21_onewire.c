/*
 * SAMD21_onewire.c
 *
 * Created: 10.11.2023 18:06:15
 *  Author: Komputer_3
 */ 

#include "SAMD21_onewire.h"
#include "driver_init.h"

void Onewire_ResetPulse(){
	gpio_set_pin_direction(TEMP, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(TEMP, false);
	delay_us(500);
	gpio_set_pin_direction(TEMP, GPIO_DIRECTION_IN);
}

bool Onewire_DetectPresence(){
	int8_t LoopCountdown = 100;	//Adjust the countdown if needed
	bool SensorPresent = false;
	gpio_set_pin_direction(TEMP, GPIO_DIRECTION_IN);
	gpio_set_pin_level(PINA5, true);
	while(!SensorPresent && LoopCountdown > 0){
		SensorPresent = !gpio_get_pin_level(TEMP);
		LoopCountdown--;
		delay_us(1);
	}
	gpio_set_pin_level(PINA5, false);
	return SensorPresent;
}

void Onewire_WriteData(uint64_t data, uint8_t bytes){
	for(uint8_t i=0; i<bytes*8; i++){
		gpio_set_pin_direction(TEMP, GPIO_DIRECTION_OUT);
		gpio_set_pin_level(TEMP, false);
		delay_us(2 + (70 * !((data >> i) & 1)));			//For sending 1 we set the bus low for ~2 us. For 0 for ~70 us (60 to 240)
		gpio_set_pin_direction(TEMP, GPIO_DIRECTION_IN);
		delay_us(100);
	}
}

void Onewire_ReadData(uint8_t bytes){
	for(int i=0; i<bytes*8; i++){
		gpio_set_pin_direction(TEMP, GPIO_DIRECTION_OUT);
		gpio_set_pin_level(TEMP, false);					//Initiating a Read Time Slot
		delay_us(2);
		gpio_set_pin_level(PINA5, true);
		gpio_set_pin_direction(TEMP, GPIO_DIRECTION_IN);
		delay_us(5);
		gpio_set_pin_level(PINA5, false);
		Onewire_Data[i/8] |= gpio_get_pin_level(TEMP) << (i%8);
		delay_us(60);
	}
	Onewire_ResetPulse();
}