#include "stm32f4xx.h"

void DMASETUP(void);

void DMASETUP(void) 
{
  
  
 /*Setup for TIM3CH1 (STREAM 4, CHANNEL 5)*/
	DMA1_Stream4->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream4->CR |= 0x0A020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream4->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream4->PAR &= 0x00000000;
	DMA1_Stream4->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream4->M0AR &= 0x00000000;
	DMA1_Stream4->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream4->FCR &= 0xFFFFFF7B;
	DMA1_Stream4->CR |= 0x00000001;   /*Enables stream 4*/
	
/*Setup for TIM3CH2 (STREAM 5, CHANNEL 5)*/
	DMA1_Stream5->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream5->CR |= 0x0A020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream5->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream5->PAR &= 0x00000000;
	DMA1_Stream5->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream5->M0AR &= 0x00000000;
	DMA1_Stream5->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream5->FCR &= 0xFFFFFF7B;  
	DMA1_Stream5->CR |= 0x00000001;   /*Enables stream 5*/
 
/*Setup for TIM4CH1 (STREAM 0, CHANNEL 2)*/
	DMA1_Stream0->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream0->CR |= 0x04020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream0->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream0->PAR &= 0x00000000;
	DMA1_Stream0->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream0->M0AR &= 0x00000000;
	DMA1_Stream0->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream0->FCR &= 0xFFFFFF7B;
	DMA1_Stream0->CR |= 0x00000001;   /*Enables stream 0*/
  
/*Setup for TIM4CH3 (STREAM 7, CHANNEL 2)*/
	DMA1_Stream7->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream7->CR |= 0x04020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream7->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream7->PAR &= 0x00000000;
	DMA1_Stream7->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream7->M0AR &= 0x00000000;
	DMA1_Stream7->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream7->FCR &= 0xFFFFFF7B;
	DMA1_Stream7->CR |= 0x00000001;   /*Enables stream 7*/
 
/*Setup for TIM4CH4 (STREAM 6, CHANNEL 2)*/
	DMA1_Stream6->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream6->CR |= 0x04020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream6->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream6->PAR &= 0x00000000;
	DMA1_Stream6->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream6->M0AR &= 0x00000000;
	DMA1_Stream6->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream6->FCR &= 0xFFFFFF7B;
	DMA1_Stream6->CR |= 0x00000001;   /*Enables stream 6*/
 
/*Setup for TIM4CH2 (STREAM 3, CHANNEL 2)*/
	DMA1_Stream3->CR &= 0xF0100000;   /*Clearing bits 27:0, excluding bit 20*/
	DMA1_Stream3->CR |= 0x04020144;   /*Setting config bits for the DMA. Bit 0 (Enable bit) needs to be set later*/
	DMA1_Stream3->NDTR |= 0x00000000; /*Insert random number here. Sets the number of data items to transfer, but shouldn't matter in circular mode*/
	DMA1_Stream3->PAR &= 0x00000000;
	DMA1_Stream3->PAR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream3->M0AR &= 0x00000000;
	DMA1_Stream3->M0AR |= 0x00000000; /*THIS IS A FILLER ADDRESS*/
	DMA1_Stream3->FCR &= 0xFFFFFF7B;
	DMA1_Stream3->CR |= 0x00000001;   /*Enables stream 3*/
}
