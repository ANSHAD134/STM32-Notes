/*
 * bmp280.c
 *
 *  Created on: 01-Jun-2026
 *      Author: HP
 */

#include "stm32f446xx.h"
#include "stm32f446xx_i2c_driver.h"
#include "bmp280.h"

// Calibration variables from BMP280

uint16_t dig_T1;
int16_t dig_T2, dig_T3;
int32_t t_fine;

void BMP280_Init(void)
{
	for(uint32_t i = 0; i < 500000; i++);						// Wait sensor to power up


}

