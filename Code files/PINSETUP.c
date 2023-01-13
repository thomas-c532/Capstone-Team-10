#include "stm32f4xx.h"

void PinSetup(void){

		RCC->AHB2ENR |= 0x00000007; 			/*Enable the clock for I/O ports A,B, and C*/
	
		/*PINS ON CN10 BUS*/
		GPIOB->MODER &= 0x00FFFFC3;			/*Setting PB1,2,13,14, and 15 to input for Finger Sensors. Also clears PB12 for next instruction*/
		GPIOB->MODER |= 0x01000000;			/*Sets PB12 to output*/
		GPIOC->MODER &= 0xFFFFFCFF;     		/*Setting PC4 to input for wrist sensor*/
	
		/*PINS ON CN5 BUS*/
		GPIOA->MODER &= 0xFFCFFF0F;     		/*Clearing bits for PA2,3, and 10*/
		GPIOA->MODER |= 0x00100050;			/*Setting PA2,3, and 10 to outputs*/
		
		/*PINS ON CN6 BUS*/

		/*PINS ON CN7 BUS*/
		GPIOC->MODER &= 0x03FFFF0F;			/*Clear bits for PC 2,3,13,14, and 15*/
		GPIOC->MODER |= 0x54000050;			/*Setting PC 2,3,13,14,15 to outputs (PWMs for motor drivers)*/
		GPIOB->MODER &= 0xFFFFFFFF;			/*Clearing PB7*/
		GPIOB->MODER |= 0x00004000;			/*Setting PB7 to output (for wrist joint motor driver)*/
}

		
