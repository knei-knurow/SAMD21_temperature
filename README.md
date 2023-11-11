# SAMD21_temperature
 Onewire communication with the DS18B20 digital thermometer on SAMD21G18 on the Seeeduino Xiao board, in C. Output in 7 LEDs representing bits 2^0 to 2^6.
 Project files generated with Atmel Start, all that was added was the code in main.c and SAMD21_onewire.h and .c
 The library is made using Atmel Start's inline functions, so if You want to use the library You need to either clone the repository or make a project using [start.atmel.com](start.atmel.com). Be aware, if You choose to create Your own project, You will need to add a Timer or Dealy component for the delay_us() and delay_ms() functions to work, which are crucial to the library's functioning.
