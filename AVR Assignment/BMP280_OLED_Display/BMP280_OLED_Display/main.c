/*
 * BMP280_OLED_Display.c
 *
 * Created: 16-05-2026 7.24.37 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "oled.h"
#include "i2c.h"
#include "bmp.h"


int main(void)
{
	float temperature;
	float pressure;
	
	char temp_value[10];
	char press_value[10];

	char temp_buffer[20];
	char press_buffer[20];

	I2C_init();												// Initialize I2C
	OLED_init();											// Initialize OLED
	BMP_init();												// Initialize BMP280
    /* Replace with your application code */
    while (1) 
    {
		temperature = BMP_readTemperature();				// Read temperature from BMP280
		pressure = BMP_readPressure() / 100.0f;				// Read pressure and convert Pa to hPa

		dtostrf(temperature, 5, 2, temp_value);				// Convert float temperature to string
		dtostrf(pressure, 6, 2, press_value);				// Convert float pressure to string

		sprintf(temp_buffer, "Temp:%s ~C", temp_value);		// Create formatted temperature string
		sprintf(press_buffer, "Pres:%s hPa", press_value);	// Create formatted pressure string

		OLED_clear();										// Clear OLED display

		OLED_setCursor(5,0);								// Set cursor to first line
		OLED_print(temp_buffer);							// Display temperature

		OLED_setCursor(5,2);								// Set cursor to second line
		OLED_print(press_buffer);							// Display pressure

		_delay_ms(2000);									// Update OLED display every 2 seconds
    }
}

