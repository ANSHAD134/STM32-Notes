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
		temperature = BMP_readTemperature();
		pressure = BMP_readPressure() / 100.0f;				// Convert Pa to hPa

		sprintf(temp_buffer, "Temp: %.2f C", temperature);
		sprintf(press_buffer, "Pres: %.2f hPa", pressure);

		OLED_clear();

		OLED_setCursor(0,0);
		OLED_print(temp_buffer);

		OLED_setCursor(0,2);
		OLED_print(press_buffer);

		_delay_ms(2000);
    }
}

