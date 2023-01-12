#include "stm32f4xx.h"
void TIMERsetup(void){
	
	TIM2->CR1 |= (0x0001); 									/* CR1 sets the configuration for the counter. Currently at default, except for the enabling bit*/
	TIM2->CCMR1 &= (0xFFFFFF80); 					  /*Clears and sets necissary bits for capture/control mode reg. for PWM mode 1.*/
	TIM2->CCMR1 |= (0x00000060);  					 /*Sets hex LSB to zero to configure to output mode*/
	TIM2->CCER &= (0xFFF0);
	TIM2->CCER |= (0x0001); 								/*Enables capture/compare output to be active high, and to activate the output*/
	TIM2->ARR = (0x0236);										/*Sets the total pulse time to ~0.14ms (7000kHz)*/
	TIM2->CCR1 = (0x0238*0.5);							/*Sets the duty cycle to 50%*/
	NVIC_EnableIRQ(TIM2_IRQn); 
	NVIC_ClearPendingIRQ(TIM2_IRQn);



}