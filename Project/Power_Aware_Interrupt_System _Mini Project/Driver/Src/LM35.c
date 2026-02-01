/*
 * LM35.c
 *
 *  Created on: 01-Feb-2026
 *      Author: HP
 */

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "LM35.h"

void delay_Temp(void)
{
    for (uint32_t i = 0; i < 50000; i++);
}

void LM35_ADC_Init(void)
{
	GPIO_PeriClockControl(GPIOA, ENABLE);
	ADC1_CLK_EN();

	// Set PA0 as Analog Mode
	GPIO_Handle_t GpioTemp;

	GpioTemp.pGPIOx = GPIOA;
	GpioTemp.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioTemp.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ANALOG;
	GpioTemp.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioTemp);

	//ADC REGISTERS
	ADC1->ADC_CR2 &= ~(1 << 0);								// Disable ADC conversion and go to power down mode
	ADC1->ADC_CR1 &= ~(3 << 24);							// Set 12-bit (minimum 15 ADCCLK cycles)
	ADC1->ADC_CR2 &= ~(1 << 11);							// Set Right alignment
	ADC1->ADC_CR2 |= (1 << 1);								// Set Continuous conversion mode
	ADC1->ADC_SQR1 = 0;										// Channel 0 is first conversion
	ADC1->ADC_SQR3 = 0;										// Only 1 conversion
	ADC1->ADC_SMPR2 |= (3 << 0);							// Channel 0 sampling time = 56 cycles
	ADC1->ADC_CR2 |= (1 << 0);								// Enable ADC
	delay_Temp();               							// ADC stabilization delay
}

float LM35_ReadTemp(void)
{
	ADC1->ADC_CR2 |= (1 << 30);								// Start conversion

	while(!(ADC1->ADC_SR & (1 << 1)));  					// Wait for End of conversion becomes 1
	uint16_t adc_value = ADC1->ADC_DR;						// Read ADC Value
	float voltage = (adc_value * 3.3f) / 4095.0f;
	return voltage * 100.0f;   								// 10mV per °C
}

