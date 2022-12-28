#include "stm32f4xx.h"

void PinSetup(void){
RCC->AHB2ENR |= 0x01; /*enable GPIOA clock*/
GPIOA->MODER &= ~(0x00FF0FFF);
GPIOA->MODER |= 0x00550002; 
GPIOA->MODER &= 0xFFF3;
GPIOA->MODER |= 0x000C;
GPIOA->PUPDR &= ~(0x00000FF0); 
GPIOA->PUPDR |= 0x00000550;
RCC->AHB2ENR |= 0x02; /*enable GPIOB clock*/
GPIOB->MODER &= 0xFFFF0000; 
GPIOB->MODER |= 0x00001540;
GPIOA->AFR[0] &= 0xFFFFFFF0;
GPIOA->AFR[0] |= 0x00000001;

}