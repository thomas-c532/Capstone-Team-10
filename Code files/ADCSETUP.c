#include "stm32f4xx.h"

void ADCSETUP(void);

void ADCSETUP(void)
{
	
	static unsigned int volatile i,j,k;
	
	RCC->APB2ENR |= 0x00000100;													/*ADC1 Clock Enable; xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx*/
	ADC1->CR2 |= 0x00000003;														/*Exits deep-power-down mode and sets ADC to continuous mode; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx11*/
/*	
	ADC1->CFGR |= 0x00003000;														/*Configures ADC1 to continuous mode, Overrun Mode turned on; xxxx xxxx xxxx xxxx xx11 xxxx xxxx xxxx/
//	ADC1->SQR1 &= 0xFFFFF830;													/*Clear Regular Channel Sequence Length and SQ1 bits; xxxx xxxx xxxx xxxx xxxx x000 00xx 0000/
//
	ADC1->SQR1 &= 0xFFFE0830;														/*Clear Regular Channel Sequence Length and SQ1, SQ2 bits; xxxx xxxx xxxx xxx0 0000 x000 00xx 0000/
	ADC1->SQR1 |= 0x00010180;														/*SQ1 select channel 5 for PA[1]; xxxx xxxx xxxx xxx1 0000 x001 10xx xxxx/
	ADC1->CR |= 0x00000001;															/*Enables ADC1; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1/	
	while(!(ADC1->ISR & 0x00000001));
	ADC1->CR |= 0x00000004;															/*Starts regular conversions in ADC1; xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx/
	
	*/ // FIX THIS SOON
}	