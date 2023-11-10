#include <atmel_start.h>
#include "SAMD21_onewire.h" //include our onewire library

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	while (1) {
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
