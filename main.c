#include <atmel_start.h>
#include "SAMD21_onewire.h" //include our Onewire library

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	delay_ms(500);
	
	gpio_toggle_pin_level(PINA0);
	gpio_toggle_pin_level(PINA1);
	gpio_toggle_pin_level(PINA2);
	gpio_toggle_pin_level(PINA3);
	gpio_toggle_pin_level(PINA4);
	gpio_toggle_pin_level(PINA5);
	gpio_toggle_pin_level(PINA6);
	
	while (1) {
		Onewire_ResetPulse();
		if(Onewire_DetectPresence()){
			Onewire_WriteData(ONEWIRE_SKIP_ROM, 1);
			Onewire_WriteData(ONEWIRE_CONVERT_T, 1);
			delay_ms(1000);
			Onewire_WriteData(ONEWIRE_SKIP_ROM, 1);
			Onewire_WriteData(ONEWIRE_SCRATCHPAD_READ, 1);
			Onewire_ReadData(2);
			gpio_set_pin_level(PINA0, Onewire_Data[0] & 16);
			gpio_set_pin_level(PINA1, Onewire_Data[0] & 32);
			gpio_set_pin_level(PINA2, Onewire_Data[0] & 64);
			gpio_set_pin_level(PINA3, Onewire_Data[0] & 128);
			gpio_set_pin_level(PINA4, Onewire_Data[1] & 1);
			gpio_set_pin_level(PINA5, Onewire_Data[1] & 2);
			gpio_set_pin_level(PINA6, Onewire_Data[1] & 4);
		}
		else{
			gpio_toggle_pin_level(PINA0);
			gpio_toggle_pin_level(PINA1);
			gpio_toggle_pin_level(PINA2);
			gpio_toggle_pin_level(PINA3);
			gpio_toggle_pin_level(PINA4);
			gpio_toggle_pin_level(PINA5);
			gpio_toggle_pin_level(PINA6);
			delay_ms(500);
		}
	}
}
