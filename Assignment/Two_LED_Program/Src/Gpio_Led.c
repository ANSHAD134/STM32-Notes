/*
 * Gpio_Led.c
 *
 *  Created on: 09-Feb-2026
 *      Author: HP
 */

#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"

#define BUTTON_PRESSED 			0
volatile uint8_t BUTTON_PRESS = 1;

void delay1(void){
	for(uint32_t i = 0; i<500000; i++);
}

void delay2(void){
	for(uint32_t i = 0; i<500000; i++);
}

