/*
 * bmp.c
 *
 * Created: 16-05-2026 7.26.25 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "bmp.h"
#include "i2c.h"
#include "oled.h"
#include <util/delay.h>

// Calibration variables (from BMP280 registers)

uint16_t dig_T1;
int16_t  dig_T2, dig_T3;
uint16_t dig_P1;
int16_t  dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
int32_t t_fine;

// ============= I2C Read/Write==================//

static void BMP_Write (uint8_t reg, uint8_t data)
{
	I2C_start();							// Start  I2C communication
	I2C_write((BMP280_ADDR << 1) | 0);		// Send BMP280 address (write)
	I2C_write(reg);							// Send which register we want to write
	I2C_write(data);						// Send data to that register
	I2C_stop();								// Stop communication
}

static uint8_t BMP_read (uint8_t reg)
{
	uint8_t v;
	I2C_start();							// Start I2C communication
	I2C_write((BMP280_ADDR << 1) | 0);		// Send BMP280 address (write)
	I2C_write(reg);							// Send register address
	
	I2C_start();							// Repeated start
	I2C_write((BMP280_ADDR << 1) | 1);		// Send BMP280 address (read)
	v = I2C_readNACK();						// Read last byte (stop reading)
	I2C_stop();								// Stop communication
	return v;								// Return byte
}

static uint16_t BMP_read_LE(uint8_t reg)
{
	uint8_t Low, High;
	I2C_start();							// Start I2C communication
	I2C_write((BMP280_ADDR << 1) | 0);		// Send BMP280 address (write)
	I2C_write(reg);							// Send register address
	
	I2C_start();							// Repeated start
	I2C_write((BMP280_ADDR << 1) | 1);		// Send BMP280 address (read)
	Low = I2C_readACK();					// Read LSB (more data to read)
	High = I2C_readNACK();					// Read MSB (stop reading)
	I2C_stop();								// Stop communication
	return ((uint16_t) (High << 8) | Low);	// Combine MSB + LSB
}

//====================  Read Calibration ====================//

void BMP_readCalibration(void)
{
	// Read Temperature
	dig_T1 = BMP_read_LE(0x88);				// Temperature 1
	dig_T2 = BMP_read_LE(0x8A);				// Temperature 2
	dig_T3 = BMP_read_LE(0x8C);				// Temperature 3
	
	// Read Pressure
	dig_P1 = BMP_read_LE(0x8E);				// Pressure 1
	dig_P2 = BMP_read_LE(0x90);				// Pressure 2
	dig_P3 = BMP_read_LE(0x92);				// Pressure 3
	dig_P4 = BMP_read_LE(0x94);				// Pressure 4
	dig_P5 = BMP_read_LE(0x96);				// Pressure 5
	dig_P6 = BMP_read_LE(0x98);				// Pressure 6
	dig_P7 = BMP_read_LE(0x9A);				// Pressure 7
	dig_P8 = BMP_read_LE(0x9C);				// Pressure 8
	dig_P9 = BMP_read_LE(0x9E);				// Pressure 9
}

void BMP_init(void)
{
	_delay_ms(100);							// Wait sensor to power up
	
	BMP_readCalibration();					// Read all calibration values
	BMP_Write(0xF4, 0x27);					// Set measurement control (ctrl_meas(0xF4), Temp/Press oversampling + Normal mode(0x27))
	BMP_Write(0xF5, 0xA0);					// Set configuration (config register(0xF5), standby=1000ms, filter=OFF, SPI=OFF(0xA0))
	
	_delay_ms(10);							// Allow sensor to apply
}

float BMP_readTemperature(void)
{
	uint8_t msb, lsb, xlsb;
	int32_t adc_T;
	float adc_Tf;
	float var1, var2;
	float T;
	
	// Read raw temperature registers (20-bit)
	msb = BMP_read(0xFA);					// MSB
	lsb = BMP_read(0xFB);					// LSB
	xlsb= BMP_read(0xFC);					// XLSB
	
	adc_T = ((uint32_t) msb << 12) | ((uint32_t) lsb << 4) | ((uint32_t) xlsb >> 4);
	adc_Tf = (float)adc_T;
	
	// Compensation formula from BMP280 Data sheet
	var1 = (((adc_Tf / 16384.0f) - ((float)dig_T1 / 1024.0f)) * (float)dig_T2);
	var2 = ((((adc_Tf / 131072.0f) - ((float)dig_T1 / 8192.0f)) *
	((adc_Tf / 131072.0f) - ((float)dig_T1 / 8192.0f))) * (float)dig_T3);

	t_fine = var1 + var2;
	T = t_fine / 5120.0f;     // final temperature in degree Celsius
	return T;
}

float BMP_readPressure(void)
{
	uint8_t msb, lsb, xlsb;
	int32_t adc_P;
	float adc_Pf;
	float var1, var2, p;
	
	msb = BMP_read(0xF7);					// MSB
	lsb = BMP_read(0xF8);					// LSB
	xlsb= BMP_read(0xF9);					// XLSB
	
	adc_P = ((int32_t) msb << 12) | ((int32_t) lsb << 4) | ((int32_t) xlsb >> 4);
	adc_Pf = (float)adc_P;
	
	// Formula from BMP280 Data sheet
	var1 = ((float)t_fine / 2.0f) - 64000.0f;
	var2 = var1 * var1 * ((float)dig_P6) / 32768.0f;
	var2 = var2 + var1 * ((float)dig_P5) * 2.0f;
	var2 = (var2 / 4.0f) + (((float)dig_P4) * 65536.0f);

	var1 = (((float)dig_P3 * var1 * var1 / 524288.0f) +
	((float)dig_P2 * var1)) / 524288.0f;

	var1 = (1.0f + var1 / 32768.0f) * ((float)dig_P1);
	
	if(var1 == 0.0f){
		return 0;								// avoid divide by zero
	}
	
	p = 1048576.0f - adc_Pf;
	p = (p - (var2 / 4096.0f)) * 6250.0f / var1;

	var1 = ((float)dig_P9) * p * p / 2147483648.0f;
	var2 = p * ((float)dig_P8) / 32768.0f;

	p = p + ((var1 + var2 + (float)dig_P7) / 16.0f);

	return p;								// pressure in Pascals (Pa)
}