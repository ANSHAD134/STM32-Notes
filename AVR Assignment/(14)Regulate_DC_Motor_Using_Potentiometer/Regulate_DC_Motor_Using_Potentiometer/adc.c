/*
 * adc.c
 *
 * Created: 16-05-2026 1.15.04 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>
#include "adc.h"

void ADC_init(void)
{
	ADMUX |= (1 << REFS0);													// Reference = AVCC (5V), input = ADC0
	ADCSRA |= (1 << ADEN)| (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);		// Enable ADC, Prescaler = 128
}

uint16_t ADC_Read(uint8_t channel)
{
	channel &= 0x07;														// Limit to 0-7
	ADMUX = (ADMUX & 0xF8) | channel;										// Select channel
	ADCSRA |= (1 << ADSC);													// Start conversion
	while(ADCSRA & (1 << ADSC));											// Wait for conversion complete
	return (ADCL | (ADCH << 8));											// Combine Result
}