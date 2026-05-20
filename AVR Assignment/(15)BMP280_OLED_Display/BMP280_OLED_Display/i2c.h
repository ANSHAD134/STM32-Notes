/*
 * i2c.h
 *
 * Created: 16-05-2026 7.38.17 PM
 *  Author: HP
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <stdint.h>

// for Serial Clock Line pin
#define I2C_SCL_PORT	PORTC
#define I2C_SCL_DDR		DDRC
#define I2C_SCL_PIN		PC5

// for Serial Data Line pin
#define I2C_SDA_PORT	PORTC
#define I2C_SDA_DDR		DDRC
#define	I2C_SDA_PIN		PC4

// I2C Functions
void I2C_init(void);				// for initialize I2C (TWI) hardware
void I2C_start(void);				// Send START condition on I2C bus
void I2C_stop(void);				// Send stop condition on I2C bus
void I2C_write(uint8_t data);		// Write 1 byte to I2C device
uint8_t I2C_readACK(void);			// Read 1 byte and send ACK (more data to read)
uint8_t I2C_readNACK(void);			// Read last byte and send NACK (stop reading)




#endif /* I2C_H_ */