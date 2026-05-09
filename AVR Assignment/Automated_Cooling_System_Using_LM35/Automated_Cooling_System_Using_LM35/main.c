/*
 * Automated_Cooling_System_Using_LM35.c
 *
 * Created: 09-05-2026 7.54.28 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// ADC Initialisation
void ADC_init(void)
{
	ADMUX |= (1 << REFS0);													// Reference = AVCC (5V), input = ADC0
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);		// Enable ADC, Prescaler = 128
}

// ADC Reading
uint8_t ADC_Read(uint8_t channel)
{
	channel &= 0x07;														// Limit to 0-7
	ADMUX = (ADMUX & 0x07) | channel;										// Select channel
	ADCSRA |= (1 << ADSC);													// Start conversion
	while(ADCSRA & (1 << ADSC));											// Wait for conversion complete
	return (ADCL | (ADCH << 8));											// Combine Result
}

void Motor_init(void)
{
	TCCR0A |= (1 << COM0A1);												// Non-inverting
	
	TCCR0B |= (1 << CS01) | (1 << CS00);									// Prescalar 64
	TCCR0A |= (1 << WGM00) | (1 << WGM01);									// Fast PWM
	OCR0A = 64;																// Start with 25% Motor speed
}

void Motor_Speed(void)
{
	uint8_t speed = 64;
	static uint8_t state = 1;
	
	if(!(PIND&(1 << PIND2)))
	{
		_delay_ms(50);														// Debounce delay for Push-button
		
		state++;
		if (state > 5)
		state = 1;
		
		switch(state)
		{
			case 1:
			speed = 64;														// 25% Motor speed
			break;
			
			case 2:
			speed = 128;													// 50% Motor speed
			break;
			
			case 3:
			speed = 192;													// 75% Motor speed
			break;
			
			case 4:
			speed = 255;													// 100% Motor speed
			break;
			
			case 5:
			speed = 0;														// Motor stop
		}
		OCR0A = speed;
		while(!(PIND&(1 << PIND2)));										// Wait until button released
	}
}


int main(void)
{
	DDRD |= (1 << DDD6);													// Set PD6 for Output Motor
	
	DDRD &= ~(1 << DDD2);													// Output for Push-Button
	PORTD |= (1 << PORTD2);													// Enable Pull-up
	
	uint16_t adc_value;
	ADC_init();	
	Motor_init();
    /* Replace with your application code */
    while (1) 
    {
		adc_value = ADC_Read(0);											// Read from analog channel 0 (A0 pin of arduino)
    }
}

