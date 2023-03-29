#include "stm32f4xx.h"

void PINSETUP(void);

void PINSETUP(void)
{
	RCC->AHB1ENR |= 0x0000000F; 												/*Enable the clock for I/O ports A, B, C, and D*/
	
	/*SERVOS*/
	GPIOB->MODER &= 0xFFF000F0;													/*Sets PB0, 1, 4, 5, 6, 7, 8, and 9 to inputs; xxxx xxxx xxxx 0000 0000 0000 xxxx 0000*/
	GPIOB->MODER |= 0x000A2A00;													/*Sets PB4, 5, 6, 8, and 9 to alternate function; xxxx xxxx xxxx 1010 xx10 1010 xxxx xxxx*/
	GPIOB->AFR[0] |= 0x02220000;												/*Sets PB4, 5, and 6 to alternate function 2; xxxx 0010 0010 0100 xxxx xxxx xxxx xxxx*/
	GPIOB->AFR[1] |= 0x00000022;												/*Sets PB8 and 9 to alternate function 2; xxxx xxxx xxxx xxxx xxxx xxxx 0010 0010*/
	
	/*FLEX SENSORS AND FORCE SENSORS*/
	GPIOA->MODER &= 0xFFFF0000;													/*Sets PA0, 1, 2, 3, 4, 5, 6, and 7 to inputs; xxxx xxxx xxxx xxxx 0000 0000 0000 0000*/
	GPIOA->MODER |= 0x0000FFFF;													/*Sets PA0, 1, 2, 3, 4, 5, 6, and 7 to analog; xxxx xxxx xxxx xxxx 1111 1111 1111 1111*/
	GPIOB->MODER |= 0x000000FF;													/*Sets PB0 and 1 to analog; xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1111*/
	
	/*WRIST SENSOR AND MOTOR*/
	GPIOB->MODER |= 0x00008000;													/*Sets PB7 to alternate function; xxxx xxxx xxxx xxxx 10xx xxxx xxxx xxxx*/
	GPIOB->AFR[0] |= 0x20000000;												/*Sets PB7 to alternate function 2; 0010 xxxx xxxx xxxx xxxx xxxx xxxx xxxx*/
	GPIOC->MODER &= 0xFFFFFCFF;													/*Sets PC4 to input; xxxx xxxx xxxx xxxx xxxx xx00 xxxx xxxx*/
	GPIOC->MODER |= 0x00000300;     										/*Sets PC4 to analog; xxxx xxxx xxxx xxxx xx11 xxxx xxxx xxxx*/
	
	/*UART PINSETUP TO RELEASE PA2 and 3*/
	GPIOD->MODER &= 0xFFFFC3FF;													/*Sets PD5 and 6 to inputs; xxxx xxxx xxxx xxxx xx00 00xx xxxx xxxx*/
	GPIOD->MODER |= 0x00002800;													/*Sets PD5 and 6 to alternate function; xxxx xxxx xxxx xxxx xx10 10xx xxxx xxxx*/
	GPIOD->AFR[0] |= 0x07700000;												/*Sets PD5 and 6 to alternate function 7 (UART TX and RX); xxxx 0111 0111 xxxx xxxx xxxx xxxx xxxx*/
}



/*
SERVOS
PB4 -> TIM3 CH1
PB5 -> TIM3 CH2
PB6 -> TIM4 CH1
PB8 -> TIM4 CH3
PB9 -> TIM4 CH4

FL.S AND SERVO FEEDBACK
PA0 -> ADC1_IN0
PA1 -> ADC1_IN1
PA2 -> ADC1_IN2
PA3 -> ADC1_IN3
PA4 -> ADC1_IN4
PA5 -> ADC1_IN5
PA6 -> ADC1_IN6
PA7 -> ADC1_IN7
PB0 -> ADC1_IN8
PB1 -> ADC1_IN9

WR.S
PC4 -> ADC1_14

WR.MOTOR
PB7 -> TIM4 CH2
*/


