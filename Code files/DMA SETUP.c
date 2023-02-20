#include "stm32f4xx.h"

void DMASETUP(void);

void DMASETUP(void) 
{
  
  
 /*Setup for TIM3CH1*/
 DMA->S4CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
 DMA->S4CR |= 0x0A020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
 DMA->S4NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
 DMA->S4PAR &= 0x00000000;
 DMA->S4PAR |= 0x/*insert address for peripheral*/;
 DMA->S4M0AR|=0x/*insert address for memory location*/;
 DMA->S4FCR &= 0xFFFFFF7B;

 
  
  
}
