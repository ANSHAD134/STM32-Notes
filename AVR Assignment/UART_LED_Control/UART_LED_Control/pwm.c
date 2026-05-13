/*
 * pwm.c
 *
 * Created: 13-05-2026 8.04.01 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include "pwm.h"

void PWM_init(void)
{
	DDRD |= (1 << DDD6);											// Set PD6 as output
	
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);			// Fast PWM, Non-inverting
	TCCR0B |= (1 << CS01) | (1 << CS00);							// Prescaler 64
	
	OCR0A = 0;
}

void LED_Brightness(uint8_t brightness)
{
	uint16_t pwm_value;
	
	OCR0A = (brightness * 255UL) / 100;								// Convert 0-255
	
	OCR0A = pwm_value;
}