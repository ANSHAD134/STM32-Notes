/*
 * BMP280_OLED_Display.c
 *
 * Created: 16-05-2026 7.24.37 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "oled.h"
#include "i2c.h"
#include "bmp.h"


int main(void)
{
	float temperature;
	float pressure;

	char temp_buffer[20];
	char press_buffer[20];

	I2C_init();												// Initialize I2C
	OLED_init();											// Initialize OLED
	BMP_init();												// Initialize BMP280
    /* Replace with your application code */
    while (1) 
    {
		char temp_value[10];
		char press_value[10];

		temperature = BMP_readTemperature();
		pressure = BMP_readPressure() / 100.0f;

		dtostrf(temperature, 5, 2, temp_value);
		dtostrf(pressure, 6, 2, press_value);

		sprintf(temp_buffer, "Temp:%s ~C", temp_value);
		sprintf(press_buffer, "Pres:%s hPa", press_value);

		OLED_clear();

		OLED_setCursor(5,0);
		OLED_print(temp_buffer);

		OLED_setCursor(5,2);
		OLED_print(press_buffer);

		_delay_ms(2000);
    }
}

