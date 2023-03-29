#include "stm32f4xx.h"

void TIMERSETUP(void);

void TIMERSETUP(void) 
{
  RCC->APB1ENR |= (0x00000006);												/*enables TIM 3, 4 from Reset clock control*/	
  	
	/* TIMER 3 */
	TIM3->CR1 &= (0xFC00);
	TIM3->CR1 |= (0x0081); 															/*Turns on the ARR preload feature, and enables the counter*/
	TIM3->CCER &= (0x4444);             			        	/*Clears the bits in the CCER so the output can be set active high*/
	TIM3->CCER |= (0x1111); 														/*Enables capture/compare output to be active high, and to activate the output (0X01 0X01 0X01 0X01) */
	TIM3->CCMR1 &= (0xFFFF); 					  								/*Clears and sets necissary bits for capture/control mode reg. for PWM mode 1.*/
	TIM3->CCMR1 |= (0x6868);   					 								/*Sets hex LSB to zero to configure to output mode*/
	TIM3->CCMR2 &= (0xFFFF);
	TIM3->CCMR2 |= (0x6868);
	TIM3->PSC = (0x0201);
	TIM3->ARR = (0x00CF); 
	NVIC_EnableIRQ(TIM3_IRQn);          					  		/*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM3_IRQn); 
	
	/* TIMER 4*/
	TIM4->CR1 |= (0x0081); 															/*Turns on the ARR preload feature, and enables the counter*/
	TIM4->CCER &= (0x4444);             			        	/*Clears the bits in the CCER so the output can be set active high*/
	TIM4->CCMR1 &= (0xFFFF); 					  								/*Clears and sets necessary bits for capture/control mode reg. for PWM mode 1.*/
	TIM4->CCMR1 |= (0x6868);   					 								/*Sets hex LSB to zero to configure to output mode*/
	TIM4->CCMR2 &= (0xFFFF);
	TIM4->CCMR2 |= (0x6868);
	TIM4->CCER |= (0x1111); 														/*Enables capture/compare output to be active high, and to activate the output (0X01 0X01 0X01 0X01) */
	TIM4->PSC = (0x0201);
	TIM4->ARR = (0x00CF);
	NVIC_EnableIRQ(TIM4_IRQn);          					  		/*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM4_IRQn); 
	
	/*CCRx values will be managed in the main loop based on the inputs of the flex sensors*/
	/*The above timers have ALL CC channels enabled. If needed, they can be adjusted to only include the used channels.

	Servos:	 
	PB4 -> TIM3 CH1
  PB5 -> TIM3 CH2
	PB6 -> TIM4 CH1
	PB8 -> TIM4 CH3
	PB9 -> TIM4 CH4

	Wrist.M: 
	PB7 -> TIM4 CH2 */
  
}


