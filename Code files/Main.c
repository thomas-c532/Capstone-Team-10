#include <stdlib.h>
#include <stdio.h>
#include "SetupFunctions.h"
#include "stm32f4xx.h"

int main(void) 
{	
uint8_t READING[10];
uint8_t DUMMY1;
uint8_t DUMMY2 = 0;

	PINSETUP();
	TIMERSETUP();	
	ADCSETUP();
	DMASETUP((uint32_t) READING);
	
	while(1)
	{
		DUMMY1 = ((READING[1] * 0x004E) / 0x00B7);
		DUMMY2 = READING[0] - DUMMY1;
		if(READING[0] < 0x004E && READING[0] > 0x0010)
		{
			TIM3->CCR1 = READING[0];
		}
		if(READING[0] >= 0x004E)
		{
				TIM3->CCR1 = 0x004E;
		}
		if(DUMMY2 < 0x0001)
		{
			
		}
	}
}


	/*DMA streams are set in circular mode, so they should continously update. The only thing that should have to be put in 
	the main code are the conversion factors of ADC input to a usuable value, and then storing those values in a memory lcoation.
	That memory location will be determined in the DMASETUP.c file and will start to stream data*/

	/*RANGE OF VALUES FOR CCR REGISTER FOR SERVOS
				0010-004E	*/


