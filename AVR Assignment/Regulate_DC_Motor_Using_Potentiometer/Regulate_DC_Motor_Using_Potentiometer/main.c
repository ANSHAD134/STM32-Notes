/*
 * Regulate_DC_Motor_Using_Potentiometer.c
 *
 * Created: 16-05-2026 1.14.48 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "adc.h"
#include "pwm.h"


int main(void)
{
	DDRD |= (1 << DDD6);								// Set PD6 for Output Motor
	
	DDRB |= (1 << DDB0) | (1 << DDB1);

	PORTB |= (1 << PORTB0);								// IN1 HIGH
	PORTB &= ~(1 << PORTB1);							// IN2 LOW
	
	uint16_t adc_value;
	uint8_t pwm_value;
	
	ADC_init();											// Initialize ADC
	PWM_Init();											// Initialize PWM
    /* Replace with your application code */
    while (1) 
    {
		adc_value = ADC_Read(0);						// Read potentiometer from ADC0
		
		pwm_value = adc_value / 4;						// Convert 10-bit ADC to 8-bit PWM
		
		Motor_Speed(pwm_value);							// Control motor speed
    }
}

