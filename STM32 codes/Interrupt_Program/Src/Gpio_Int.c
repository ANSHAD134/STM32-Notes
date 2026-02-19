/*
 * Gpio_Int.c
 *
 *  Created on: 18-Feb-2026
 *      Author: HP
 */

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i=0; i<50000; i++);
}

int main()
{
	GPIO_Handle_t Gpioled, Gpioint;

	// For LED
	Gpioled.pGPIOx = GPIOA;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&Gpioled);

	// For Button Interrupt
	Gpioint.pGPIOx = GPIOC;
	Gpioint.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Gpioint.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	Gpioint.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpioint.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&Gpioint);

	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

	while(1)
	{

	}

}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOA ,GPIO_PIN_NO_5);
	delay();
}
