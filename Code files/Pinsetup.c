#include "stm32f4xx.h"

void PinSetup(void){

		RCC->AHB2ENR |= 0x01; 
		GPIOA->MODER  &= 0x00000001;
		RCC->APB1ENR |= (0x0000001);						 /*enables TIM2 from Reset and Clock Control Register*/



}
