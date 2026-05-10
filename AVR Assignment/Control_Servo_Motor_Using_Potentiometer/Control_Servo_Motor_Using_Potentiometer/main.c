/*
 * Control_Servo_Motor_Using_Potentiometer.c
 *
 * Created: 10-05-2026 7.37.05 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void ADC_init(void)
{
	ADMUX |= (1 << REFS0);													// Reference = AVCC (5V), input = ADC0
	ADCSRA |= (1 << ADEN);													// Enable ADC
}

// Timer1 (16-bit)
void Timer1_Config(void)
{
	TIMSK1 |= (1 << OCIE1A);												// Enable Timer1 
	
	TCCR0B |= (1 << CS01) | (1 << CS00);									// Prescalar 64
	TCCR0A |= (1 << WGM00) | (1 << WGM01);									// Fast PWM
	OCR0A = 64;
}

int main(void)
{
	DDRB |=(1 << DDB1);														// Output for Servo motor
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

