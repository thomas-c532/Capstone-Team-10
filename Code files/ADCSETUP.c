#include "stm32f4xx.h"

void ADCSETUP(void);

void ADCSETUP(void)
{
	
	static unsigned int volatile i,j,k;
	i = 0;
	j = 0;
	k = 0;
	
	RCC->APB2ENR |= 0x00000100;													/*ADC1 Clock Enable, automatically connected to APB2; xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx*/
	ADC1->CR1 |= 0x02000000;														/*ADC1 resolution changed to 8-bit; xxxx xx10 xxxx xxxx xxxx xxxx xxxx xxxx*/
	ADC1->CR2 |= 0x00000003;														/*Exits deep-power-down mode and sets ADC to continuous mode; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx11*/
	
	ADC1->SQR1 |= 0x00900000;														/*Regular channel sequence set to 10 (5 for FL.S. and 5 for FO.S.); xxxx xxxx 1001 - xxxx x-xxx xx-xx xxx-x xxxx*/
	ADC1->SQR2 |= 0x0008A0E6;														/*Sets the last four conversions to the last four channels, PA[7:6], PB[1:0]; xx-xx xxx-x xxxx - 0100 1-010 00-00 111-0 0110*/
	ADC1->SQR3 |= 0x0A418820;														/*Sets the first six conversions to the first six channels, PA[5:0]; xx-00 101-0 0100 - 0001 1-000 10-00 001-0 0000*/


	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			k++;
		}
	}
	
	
	ADC1->CR2 |= 0x40000000;														/*Starts conversion of regular channels; x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
	
		
//	RCC->AHB2ENR |= 0x00002000;													/*ADC1 Clock Enable; xxxx xxxx xxxx xxxx xx1x xxxx xxxx xxxx*/
//	RCC->CCIPR &= 0xCFFFFFFF;														/*Clears clock source bits for ADC1; xx00 xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
//	RCC->CCIPR |= 0x30000000;														/*Sets clock source bits for ADC1 (system clock); xx11 xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
//	ADC1->CR &= 0xDFFFFFFF;															/*Exits deep-power-down mode; xx0x xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
//	ADC1->CR |= 0x10000000;															/*Enables ADC1 voltage regulator; xxx1 xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
//	
//	for(i = 0; i < 5; ++i)															/*Delay time for voltage regulator startup (20us)*/
//	{
//		for(j = 0; j < 5; ++j)
//		{
//			++k;
//		}
//	}
//	
//	ADC1->CFGR |= 0x00003000;														/*Configures ADC1 to continuous mode, Overrun Mode turned on; xxxx xxxx xxxx xxxx xx11 xxxx xxxx xxxx*/
////	ADC1->SQR1 &= 0xFFFFF830;														/*Clear Regular Channel Sequence Length and SQ1 bits; xxxx xxxx xxxx xxxx xxxx x000 00xx 0000*/
////
//	ADC1->SQR1 &= 0xFFFE0830;														/*Clear Regular Channel Sequence Length and SQ1, SQ2 bits; xxxx xxxx xxxx xxx0 0000 x000 00xx 0000*/
//	ADC1->SQR1 |= 0x00010180;														/*SQ1 select channel 5 for PA[1]; xxxx xxxx xxxx xxx1 0000 x001 10xx xxxx*/
//	ADC1->CR |= 0x00000001;															/*Enables ADC1; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1*/	
//	while(!(ADC1->ISR & 0x00000001));
//	ADC1->CR |= 0x00000004;															/*Starts regular conversions in ADC1; xxxx xxxx xxxx xxxx xxxx xxxx xxxx x1xx*/
//	
}	
