
#include "stm32f4xx.h"

void TIMERSETUP(void);

void TIMERSETUP(void) 
{
  RCC->APB1ENR |= (0x0000000F);										/*enables TIM 2, 3, 4, and 5 from Reset and Clock Control Register*/
	RCC->APB2ENR |= (0x00010000);										/*enables TIM 9 from the Reset and Clock Control Register*/	
	
	/* TIMER 2 */
	TIM2->CR1 |= (0x0001); 													/*CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM2->CCMR1 &= (0xFFFFFF80); 		 								/*Clears and sets necessary bits for capture/control mode reg. for PWM mode 1.*/
	TIM2->CCMR1 |= (0x00000060);  									/*Sets hex LSB to zero to configure to output mode*/
	TIM2->CCER &= (0xFFF0);             					  /*Clears the bits in the CCER so the output can be set active high*/
	TIM2->CCER |= (0x0001); 												/*Enables capture/compare output to be active high, and to activate the output*/
	TIM2->ARR = (0x0236);               					  /*Sets a PWM to generated at 7kHz*/
	TIM2->CCR1 = (0x0238*0.5);          					  /*Sets the duty cycle for the PWM to be 50%*/
	NVIC_EnableIRQ(TIM2_IRQn);          					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM2_IRQn); 
  	
	/* TIMER 3 */
	TIM3->CR1 |= (0x0001); 													/*CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM3->CCMR1 &= (0xFFFFFF80); 		 								/*Clears and sets necessary bits for capture/control mode reg. for PWM mode 1.*/
	TIM3->CCMR1 |= (0x00000060);  									/*Sets hex LSB to zero to configure to output mode*/
	TIM3->CCER &= (0xFFF0);             					  /*Clears the bits in the CCER so the output can be set active high*/
	TIM3->CCER |= (0x0001); 												/*Enables capture/compare output to be active high, and to activate the output*/
	TIM3->ARR = (0x0236);               					  /*Sets a PWM to generated at 7kHz*/
	TIM3->CCR1 = (0x0238*0.5);          					  /*Sets the duty cycle for the PWM to be 50%*/
	NVIC_EnableIRQ(TIM3_IRQn);          					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM3_IRQn); 
	  
	/* TIMER 4 */
	TIM4->CR1 |= (0x0001); 													/*CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM4->CCMR1 &= (0xFFFFFF80); 		 								/*Clears and sets necissary bits for capture/control mode reg. for PWM mode 1.*/
	TIM4->CCMR1 |= (0x00000060);  									/*Sets hex LSB to zero to configure to output mode*/
	TIM4->CCER &= (0xFFF0);             					  /*Clears the bits in the CCER so the output can be set active high*/
	TIM4->CCER |= (0x0001); 												/*Enables capture/compare output to be active high, and to activate the output*/
	TIM4->ARR = (0x0236);               					  /*Sets a PWM to generated at 7kHz*/
	TIM4->CCR1 = (0x0238*0.5);          					  /*Sets the duty cycle for the PWM to be 50%*/
	NVIC_EnableIRQ(TIM4_IRQn);          					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM4_IRQn); 
	
	/* TIMER 5 */
	TIM5->CR1 |= (0x0001); 													/*CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM5->CCMR1 &= (0xFFFFFF80); 		 								/*Clears and sets necissary bits for capture/control mode reg. for PWM mode 1.*/
	TIM5->CCMR1 |= (0x00000060);  									/*Sets hex LSB to zero to configure to output mode*/
	TIM5->CCER &= (0xFFF0);             					  /*Clears the bits in the CCER so the output can be set active high*/
	TIM5->CCER |= (0x0001); 												/*Enables capture/compare output to be active high, and to activate the output*/
	TIM5->ARR = (0x0236);               					  /*Sets a PWM to generated at 7kHz*/
	TIM5->CCR1 = (0x0238*0.5);          					  /*Sets the duty cycle for the PWM to be 50%*/
	NVIC_EnableIRQ(TIM5_IRQn);           					  /*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM5_IRQn); 
	
	/* TIMER 9 */
	TIM9->CR1 |= (0x0001); 													/*CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM9->CCMR1 &= (0xFFFFFF80); 		 								/*Clears and sets necissary bits for capture/control mode reg. for PWM mode 1.*/
	TIM9->CCMR1 |= (0x00000060);  									/*Sets hex LSB to zero to configure to output mode*/
	TIM9->CCER &= (0xFFF0);               					/*Clears the bits in the CCER so the output can be set active high*/
	TIM9->CCER |= (0x0001); 												/*Enables capture/compare output to be active high, and to activate the output*/
	TIM9->ARR = (0x0236);                 					/*Sets a PWM to generated at 7kHz*/
	TIM9->CCR1 = (0x0238*0.5);            					/*Sets the duty cycle for the PWM to be 50%*/
	NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);            	/*Enables to interrupt to trigger for every clock pulse of the TIMER*/
	NVIC_ClearPendingIRQ(TIM1_BRK_TIM9_IRQn); 
  }

	
	/* Current Changes, February 2nd:

			Moved comments around for readability; removed the TIMER 6 section and replaced it with TIMER 9, as the STM32F401RE does not have
			a TIM6. Changed the library above from stm32l432xx.h to stm32f4xx.h. Added a function prototype for function TIMERSETUP. Fixed issues
			concerning enabling TIM9 from RCC and enabling interrupts from TIM9.*/



