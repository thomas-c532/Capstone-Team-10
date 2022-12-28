#include "stm32f4xx.h"
#include "stdio.h"

void ADCsetup(void){

/*1. Enable ADC and GPIO clock
2. Set the prescalar in the Common Control Register (CCR)
3. Set the Scan Mode and Resolution in the Control Register 1 (CR1)
4. Set the Continuous Conversion, EOC, and Data Alignment in Control Reg 2 (CR2)
5. Set the Sampling Time for the channels in ADC_SMPRx
6. Set the Regular channel sequence length in ADC_SQR1
)7. Set the Respective GPIO PINs in the Analog Mode*/

RCC-> APB2ENR |= (0x00000100); /*Sets the bit associated with the ADC1 clock (bit 8) to true*/
				/*GPIO clocks are enabled in the pin setup, redundant*/

// This is a test for the GITHUB repository 2

}
