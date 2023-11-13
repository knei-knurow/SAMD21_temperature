#include <atmel_start.h>
//#include "SAMD21_onewire.h" //include our Onewire library

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	//delay_ms(500);
	
	//uint8_t *data;
	
	while (1) {
		/*gpio_toggle_pin_level(PINA1);
		delay_ms(500);
		Onewire_ResetPulse();
		Onewire_DetectPresence();
		if(Onewire_SensorPresent){
			Onewire_WriteData(ONEWIRE_SKIP_ROM, 1);
			Onewire_WriteData(ONEWIRE_CONVERT_T, 1);
			delay_ms(1000);
			Onewire_WriteData(ONEWIRE_SKIP_ROM, 1);
			Onewire_WriteData(ONEWIRE_SCRATCHPAD_READ, 1);
			data = Onewire_ReadData(3);
			
		}
		else{*/
			gpio_toggle_pin_level(PINA0);
			gpio_toggle_pin_level(PINA1);
			gpio_toggle_pin_level(PINA2);
			gpio_toggle_pin_level(PINA3);
			gpio_toggle_pin_level(PINA4);
			gpio_toggle_pin_level(PINA5);
			gpio_toggle_pin_level(PINA6);
			delay_ms(500);/*
		}*/
	}
}
