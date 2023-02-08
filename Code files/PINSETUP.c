#include "stm32f4xx.h"

void PinSetup(void)
{
	RCC->AHB1ENR |= 0x00000007; 			/*Enable the clock for I/O ports A,B, and C*/
	
	/*PINS ON CN10 BUS*/
	GPIOA->MODER &= 0xFFCFFF0F;     		/*Clearing bits for PA2, 3, and 10; xxxx xxxx xx00 xxxx xxxx xxxx 0000 xxxx*/
	GPIOA->MODER |= 0x00100050;			/*Setting PA2, 3, and 10 to outputs; xxxx xxxx xx01 xxxx xxxx xxxx 0101 xxxx*/
	GPIOB->MODER &= 0x00FFFFC3;			/*Clearing PB1, 2, 13, 14, and 15. Also clears PB12; 0000 0000 xxxx xxxx xxxx xxxx xx00 00xx*/
	GPIOB->MODER |= 0xFD00003C;			/*Sets PB12 to output, and PB1, 2, 13, 14, 15 to analog; 1111 1101 xxxx xxxx xxxx xxxx xx11 11xx*/
	GPIOC->MODER &= 0xFFFFFCFF;			/*Clears PC4; xxxx xxxx xxxx xxxx xxxx xx00 xxxx xxxx*/
	GPIOC->MODER |= 0x00000300;     		/*Setting PC4 to analog for wrist sensor; xxxx xxxx xxxx xxxx xxxx xx11 xxxx xxxx*/

	/*PINS ON CN6 BUS*/

	/*PINS ON CN7 BUS*/
	GPIOB->MODER &= 0xFFFF3FFF;			/*Clearing PB7; xxxx xxxx xxxx xxxx 00xx xxxx xxxx xxxx*/
	GPIOB->MODER |= 0x00004000;			/*Setting PB7 to output (for wrist joint motor driver); xxxx xxxx xxxx xxxx 01xx xxxx xxxx xxxx*/
	GPIOC->MODER &= 0x03FFFF0F;			/*Clear bits for PC2, 3, 13, 14, and 15; 0000 00xx xxxx xxxx xxxx xxxx 0000 xxxx*/
	GPIOC->MODER |= 0x54000050;			/*Setting PC2, 3, 13, 14, 15 to outputs (PWMs for motor drivers); 0101 01xx xxxx xxxx xxxx xxxx 0101 xxxx*/
}

		

		
