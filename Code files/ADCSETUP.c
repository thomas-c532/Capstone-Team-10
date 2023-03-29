#include "stm32f4xx.h"

void ADCSETUP(void);

void ADCSETUP(void)
{
	
	static unsigned int volatile i,j,k;
	i = 0;
	j = 0;
	k = 0;
	
	RCC->APB2ENR |= 0x00000100;													/*ADC1 Clock Enable, automatically connected to APB2; xxxx xxxx xxxx xxxx xxxx xxx1 xxxx xxxx*/
	ADC->CCR |= 0x00010000;															/*ADC1 Clock prescaled by a factor of four to prevent data overrun; xxxx xxxx xxxx xx01 xxxx xxxx xxxx xxxx*/
	ADC1->CR1 |= 0x02000100;														/*ADC1 resolution changed to 8-bit and Scan Mode is enabled; xxxx xx10 xxxx xxxx xxxx xxx1 xxxx xxxx*/
	ADC1->CR2 |= 0x00000302;														/*Sets ADC to continuous mode; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xx1x*/
																											/*(WITH ABOVE) Enables the DMA as well as DMA requests at the end of every conversion; xxxx xxxx xxxx xxxx xxxx xx11 xxxx xxxx*/
																											/*(WITH ABOVE) Note that data will be right aligned, EOC will be set after all conversions*/
	ADC1->SMPR1 |= 0x001FFFFF;													/*ADC1 Channels 10-16 sampling time set to 480 clock cycles; xxxx x-xxx - xxx-1 11-11 1-111 - 111-1 11-11 1-111*/
	ADC1->SMPR2	|= 0x3FFFFFFF;													/*ADC1 Channels 0-9 sampling time set to 480 clock cycles; xx-11 1-111 - 111-1 11-11 1-111 - 111-1 11-11 1-111*/
	
	ADC1->SQR1 |= 0x00900000;														/*Regular channel sequence set to 10 (5 for FL.S. and 5 for FO.S.); xxxx xxxx 1001 - xxxx x-xxx xx-xx xxx-x xxxx*/
	ADC1->SQR2 |= 0x0004A0E6;														/*Sets the last four conversions to the last four channels, PA[7:6], PB[1:0]; xx-xx xxx-x xxxx - 0100 1-010 00-00 111-0 0110*/
	ADC1->SQR3 |= 0x0A418820;														/*Sets the first six conversions to the first six channels, PA[5:0]; xx-00 101-0 0100 - 0001 1-000 10-00 001-0 0000*/

	ADC1->CR2 |= 0x00000001;														/*Exits deep-power-down mode; xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxx1*/
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			k++;
		}
	}
	
	
	ADC1->CR2 |= 0x40000000;														/*Starts conversion of regular channels; x1xx xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
}	


