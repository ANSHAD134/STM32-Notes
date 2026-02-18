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
	for(i=0; i<50000; i++);
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

	// For Button Interrupt

}
