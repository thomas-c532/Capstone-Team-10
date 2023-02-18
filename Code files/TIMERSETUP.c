
#include "stm32f4xx.h"

void TIMERSETUP(void);

void TIMERSETUP(void) 
{
  RCC->APB1ENR |= (0x0000000F);						/*enables TIM 2, 3, 4, and 5 from Reset clock control*/	
  	
	/* TIMER 3 */
	TIM3->CR1 |= (0x0081); 						/*Turns on the ARR preload feature, and enables the counter*/
	TIM3->DIER &= (0xA0AE);						/*Clearing bits 14,12,11,10,9,8,and 1*/
	TIM3->DIER |= (0x5F01);						/*Enables DMA request updates (X1X1 1111 X0X0 0001) */
	TIM3->EGR &= (0xFFE1);						/*Clearing bits 4,3,2, and 1*/
	TIM3->EGR |= (0x001E);						/*Setting bits so multiple channels can be used from single timer (XXXX XXXX XXX1 111X) */
	TIM3->CCER &= (0x4444);             			        /*Clears the bits in the CCER so the output can be set active high*/
	TIM3->CCER |= (0x1111); 					/*Enables capture/compare output to be active high, and to activate the output (0X01 0X01 0X01 0X01) */
	TIM3->PSC = (0x0201);
	TIM3->ARR = (0x00CF);               					
	NVIC_EnableIRQ(TIM3_IRQn);          					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM3_IRQn); 
	  
	/* TIMER 4*/
	TIM4->CR1 |= (0x0081); 						/*Turns on the ARR preload feature, and enables the counter*/
	TIM4->DIER &= (0xA0AE);						/*Clearing bits 14,12,11,10,9,8,and 1*/
	TIM4->DIER |= (0x5F01);						/*Enables DMA request updates (X1X1 1111 X0X0 0001) */
	TIM4->EGR &= (0xFFE1);						/*Clearing bits 4,3,2, and 1*/
	TIM4->EGR |= (0x001E);						/*Setting bits so multiple channels can be used from single timer (XXXX XXXX XXX1 111X) */
	TIM4->CCER &= (0x4444);             			        /*Clears the bits in the CCER so the output can be set active high*/
	TIM4->CCER |= (0x1111); 					/*Enables capture/compare output to be active high, and to activate the output (0X01 0X01 0X01 0X01) */
	TIM4->PSC = (0x0201);
	TIM4->ARR = (0x00CF);               					
	NVIC_EnableIRQ(TIM4_IRQn);          					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM4_IRQn); 
	
	/*CCRx values will be managed in the main loop based on the inputs of the flex sensors*/
	/*The above timers have ALL CC channels enabled. If needed, they can be adjusted to only include the used channels.
Servos:	 PB4 -> TIM3 CH1
	 PB5 -> TIM3 CH2
	 PB6 -> TIM4 CH1
	 PB8 -> TIM4 CH3
	 PB9 -> TIM4 CH4
Wrist.M: PB7 -> TIM4 CH2
  }

	


	



