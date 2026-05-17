/*
 * i2c.c
 *
 * Created: 16-05-2026 7.36.35 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL
#include "i2c.h"
#include "oled.h"
#include "bmp.h"

void I2C_init(void)
{
	TWSR = 0x00;												// Set Prescalar to 1
	TWBR = 72;													// set Bit Rate (SCL = 100 kHz)
	TWCR |= (1 << TWEN);										// Enable TWI (Two-Wire Interface)
}

void I2C_start(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);			// Send start
	while(!(TWCR & (1 << TWINT)));								// Wait end of operation becomes 1
}

void I2C_stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);			// Send Stop
}

void I2C_write(uint8_t data)
{
	TWDR = data;												// For Data
	TWCR = (1 << TWINT) | (1 << TWEN);							// Start transmission
	while(!(TWCR & (1 << TWINT)));								// Wait until transmission complete
}

uint8_t I2C_readACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);			// Sends ACK after receiving data
	while(!(TWCR & (1 << TWINT)));								// Wait until data is received
	return TWDR;												// Return received byte
}

uint8_t I2C_readNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);							// Clear flag, enable TWI and send NACK
	while(!(TWCR & (1 << TWINT)));								// Wait until byte is received and NACK is sent
	return TWDR;												// Return the received byte
}