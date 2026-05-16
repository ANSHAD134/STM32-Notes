/*
 * pwm.c
 *
 * Created: 16-05-2026 12.41.51 PM
 *  Author: HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "pwm.h"

void PWM_Init(void)
{
	DDRD |= (1 << DDD6);								// Set PD6 for Output Motor
	
	TCCR0A |= (1 << COM0A1);							// Non-inverting
	TCCR0A |= (1 << WGM00) | (1 << WGM01);				// Fast PWM
	
	TCCR0B |= (1 << CS01) | (1 << CS00);				// Prescalar 64
	OCR0A = 0;											// initial speed is 0
}

void Motor_Speed(uint8_t speed)
{
	OCR0A = speed;										// Update PWM duty cycle
}