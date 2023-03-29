#include "stm32f4xx.h"

void DMASETUP(uint32_t Storage);

void DMASETUP(uint32_t Storage) 
{
  
	RCC->AHB1ENR |= 0x00400000; 												/*DMA2 Clock Enabled; xxxx xxxx xx1x xxxx xxxx xxxx xxxx xxxx*/
  
/*Setup for ADC1 (STREAM 0, CHANNEL 0)*/
	DMA2_Stream0->CR |= 0x00020500;   									/* xxxx 000x xxxx xx10 x000 01x1 00xx xxxx*/
																											/*(WITH ABOVE) Channel 0 selected [27:25], Priority Level High [17:16]*/
																											/*(WITH ABOVE) Memory and Peripheral Sizes set to Byte [14:11]*/
																											/*(WITH ABOVE) Memory Address Incrementation Enabled [10] and Circular Mode Enabled [8]*/
																											/*(WITH ABOVE) Direction of data movement set to Peripheral-to-Memory [7:6]*/
	DMA2_Stream0->NDTR |= 0x0000000A; 									/*Total number of converted channels in ADC: 10; xxxx xxxx xxxx xxxx 0000 0000 0000 1010*/
	DMA2_Stream0->PAR = (uint32_t) &ADC1->DR; 					/*Pointer to ADC1 Peripheral Data Register Address*/
	DMA2_Stream0->M0AR = Storage; 											/*Address of memory element (variable)*/
	
	DMA2_Stream0->CR |= 0x00000001;   									/*Enables stream 0*/

}


