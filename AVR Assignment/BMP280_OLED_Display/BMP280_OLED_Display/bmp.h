/*
 * bmp.h
 *
 * Created: 16-05-2026 7.34.31 PM
 *  Author: HP
 */ 


#ifndef BMP_H_
#define BMP_H_

#include <avr/io.h>
#include <stdint.h>

#define BMP280_ADDR	0x76									// BMP280 Address

// now lets declare functions

void BMP_init(void);										// Initialize BMP280
void BMP_readCalibration(void);								// Read calibration values
float BMP_readTemperature(void);							// Read temperature
float BMP_readPressure(void);								// Read pressure



#endif /* BMP_H_ */