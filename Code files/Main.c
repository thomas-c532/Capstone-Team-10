#include <stdlib.h>
#include <stdio.h>
#include "SetupFunctions.h"
#include "stm32f4xx.h"

int main(void) {
	
uint8_t READING[10];	
// uint8_t OUT1;	
	
	PINSETUP();
	TIMERSETUP();	
	ADCSETUP();
	DMASETUP((uint32_t) READING);
	
	while(1)
	{

	}
}

	/*DMA streams are set in circular mode, so they should continously update. The only thing that should have to be put in 
	the main code are the conversion factors of ADC input to a usuable value, and then storing those values in a memory lcoation.
	That memory location will be set in the DMASETUP.c and will start to stream data*/
