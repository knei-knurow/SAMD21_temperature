/*
 * SAMD21_onewire.h
 *
 * Created: 10.11.2023 18:02:55
 *  Author: Komputer_3
 */ 


#ifndef SAMD21_ONEWIRE
#define SAMD21_ONEWIRE

#include "driver_init.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ONEWIRE_SEARCH_ROM 0xF0			//ROM commands
#define ONEWIRE_READ_ROM 0x33
#define ONEWIRE_MATCH_ROM 0x55
#define ONEWIRE_SKIP_ROM 0xCC
#define ONEWIRE_ALARM_SEARCH 0xEC

#define ONEWIRE_CONVERT_T 0x44			//Temperature command

#define ONEWIRE_SCRATCHPAD_WRITE 0xBE	//Memory commands
#define ONEWIRE_SCRATCHPAD_READ 0x4E
#define ONEWIRE_SCRATCHPAD_COPY 0x48
#define ONEWIRE_RECALL_E2 0xB8
#define ONEWIRE_READ_POWER_SUPPLY 0xB4

void Onewire_ResetPulse();
void Onewire_DetectPresence();

bool Onewire_SensorPresent = false;

#ifdef __cplusplus
}
#endif
#endif /* SAMD21_ONEWIRE */