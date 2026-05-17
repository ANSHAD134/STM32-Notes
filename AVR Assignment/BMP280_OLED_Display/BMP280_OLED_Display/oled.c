/*
 * oled.c
 *
 * Created: 16-05-2026 7.39.06 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "oled.h"
#include "i2c.h"

#define OLED_ADDR 0x3C

static const uint8_t font5x7[][5] =
{
	{0x3E,0x51,0x49,0x45,0x3E},					// 0
	{0x00,0x42,0x7F,0x40,0x00},					// 1
	{0x42,0x61,0x51,0x49,0x46},					// 2
	{0x21,0x41,0x45,0x4B,0x31},					// 3
	{0x18,0x14,0x12,0x7F,0x10},					// 4
	{0x27,0x45,0x45,0x45,0x39},					// 5
	{0x3C,0x4A,0x49,0x49,0x30},					// 6
	{0x01,0x71,0x09,0x05,0x03},					// 7
	{0x36,0x49,0x49,0x49,0x36},					// 8
	{0x06,0x49,0x49,0x29,0x1E},					// 9
};

static void OLED_command(uint8_t cmd)
{
	I2C_start();

	I2C_write((OLED_ADDR << 1) | 0);

	I2C_write(0x00);

	I2C_write(cmd);

	I2C_stop();
}

static void OLED_data(uint8_t data)
{
	I2C_start();

	I2C_write((OLED_ADDR << 1) | 0);

	I2C_write(0x40);

	I2C_write(data);

	I2C_stop();
}

void OLED_init(void)
{
	_delay_ms(100);

	OLED_command(0xAE);							// Display OFF
	OLED_command(0xD5);							// Set display clock
	OLED_command(0x80);

	OLED_command(0xA8);							// Set multiplex
	OLED_command(0x3F);

	OLED_command(0xD3);							// Display offset
	OLED_command(0x00);

	OLED_command(0x40);							// Start line

	OLED_command(0x8D);							// Charge pump
	OLED_command(0x14);

	OLED_command(0x20);							// Memory mode
	OLED_command(0x00);

	OLED_command(0xA1);							// Segment remap
	OLED_command(0xC8);							// COM scan direction

	OLED_command(0xDA);							// COM pins
	OLED_command(0x12);

	OLED_command(0x81);							// Contrast
	OLED_command(0xCF);

	OLED_command(0xD9);							// Pre-charge
	OLED_command(0xF1);

	OLED_command(0xDB);							// VCOM detect
	OLED_command(0x40);

	OLED_command(0xA4);							// Resume RAM display
	OLED_command(0xA6);							// Normal display

	OLED_command(0xAF);							// Display ON
}

void OLED_clear(void)
{
	uint16_t i;

	OLED_setCursor(0,0);

	for(i = 0; i < 1024; i++)
	{
		OLED_data(0x00);
	}
}

void OLED_setCursor(uint8_t x, uint8_t page)
{
	OLED_command(0xB0 + page);					// Page address
	OLED_command(0x00 + (x & 0x0F));			// Lower column
	OLED_command(0x10 + ((x >> 4) & 0x0F));		// Higher column
}

void OLED_char(char ch)
{
	uint8_t i;

	// Space
	if(ch == ' ')
	{
		for(i = 0; i < 6; i++)
		{
			OLED_data(0x00);
		}
	}

	// Numbers 0-9
	else if(ch >= '0' && ch <= '9')
	{
		const uint8_t numbers[10][5] =
		{
			{0x3E,0x51,0x49,0x45,0x3E},		// 0
			{0x00,0x42,0x7F,0x40,0x00},		// 1
			{0x42,0x61,0x51,0x49,0x46},		// 2
			{0x21,0x41,0x45,0x4B,0x31},		// 3
			{0x18,0x14,0x12,0x7F,0x10},		// 4
			{0x27,0x45,0x45,0x45,0x39},		// 5
			{0x3C,0x4A,0x49,0x49,0x30},		// 6
			{0x01,0x71,0x09,0x05,0x03},		// 7
			{0x36,0x49,0x49,0x49,0x36},		// 8
			{0x06,0x49,0x49,0x29,0x1E}		// 9
		};

		for(i = 0; i < 5; i++)
		{
			OLED_data(numbers[ch - '0'][i]);
		}

		OLED_data(0x00);
	}

	// Capital T
	else if(ch == 'T')
	{
		uint8_t T[5] = {0x01,0x01,0x7F,0x01,0x01};

		for(i = 0; i < 5; i++)
		{
			OLED_data(T[i]);
		}

		OLED_data(0x00);
	}

	// Lowercase e
	else if(ch == 'e')
	{
		uint8_t e[5] = {0x38,0x54,0x54,0x54,0x18};

		for(i = 0; i < 5; i++)
		{
			OLED_data(e[i]);
		}

		OLED_data(0x00);
	}

	// Lowercase m
	else if(ch == 'm')
	{
		uint8_t m[5] = {0x7C,0x04,0x18,0x04,0x78};

		for(i = 0; i < 5; i++)
		{
			OLED_data(m[i]);
		}

		OLED_data(0x00);
	}

	// Lowercase p
	else if(ch == 'p')
	{
		uint8_t p[5] = {0x7C,0x14,0x14,0x14,0x08};

		for(i = 0; i < 5; i++)
		{
			OLED_data(p[i]);
		}

		OLED_data(0x00);
	}

	// Colon :
	else if(ch == ':')
	{
		uint8_t colon[5] = {0x00,0x36,0x36,0x00,0x00};

		for(i = 0; i < 5; i++)
		{
			OLED_data(colon[i]);
		}

		OLED_data(0x00);
	}

	// Decimal point .
	else if(ch == '.')
	{
		uint8_t dot[5] = {0x00,0x60,0x60,0x00,0x00};

		for(i = 0; i < 5; i++)
		{
			OLED_data(dot[i]);
		}

		OLED_data(0x00);
	}

	// Capital C
	else if(ch == 'C')
	{
		uint8_t C[5] = {0x3E,0x41,0x41,0x41,0x22};

		for(i = 0; i < 5; i++)
		{
			OLED_data(C[i]);
		}

		OLED_data(0x00);
	}
}

void OLED_print(char *str)
{
	while(*str)
	{
		OLED_char(*str++);
	}
}