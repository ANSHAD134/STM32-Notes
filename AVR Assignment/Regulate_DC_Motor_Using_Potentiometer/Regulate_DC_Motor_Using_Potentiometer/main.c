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

