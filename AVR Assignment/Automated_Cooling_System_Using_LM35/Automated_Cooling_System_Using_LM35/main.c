/*
 * Automated_Cooling_System_Using_LM35.c
 *
 * Created: 09-05-2026 7.54.28 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t state = 0;

// ADC Initialisation
void ADC_init(void)
{
	ADMUX |= (1 << REFS0);													// Reference = AVCC (5V), input = ADC0
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);		// Enable ADC, Prescaler = 128
}

// ADC Reading
uint16_t ADC_Read(uint8_t channel)
{
	channel &= 0x07;														// Limit to 0-7
	ADMUX = (ADMUX & 0xF8) | channel;										// Select channel
	ADCSRA |= (1 << ADSC);													// Start conversion
	while(ADCSRA & (1 << ADSC));											// Wait for conversion complete
	return (ADCL | (ADCH << 8));											// Combine Result
}

void Motor_init(void)
{
	TCCR0A |= (1 << COM0A1);												// Non-inverting
	
	TCCR0B |= (1 << CS01) | (1 << CS00);									// Prescalar 64
	TCCR0A |= (1 << WGM00) | (1 << WGM01);									// Fast PWM
	OCR0A = 0;																// Motor OFF Initially
}

void System_Control(void)
{
	if(!(PIND & (1 << PIND2)))
	{
		_delay_ms(50);														// Debounce delay
		
		state ^= 1;															// Toggle system state
		
		while(!(PIND & (1 << PIND2)));										// Wait until button Release
	}
}

void Motor_Speed(uint16_t temperature)
{
	if (temperature < 30)
	{
		OCR0A = 64;															// 25% speed
	}
	else if(temperature >=30 && temperature < 40)
	{
		OCR0A = 128;														// 50% speed
	}
	else if(temperature >=40 && temperature < 50)
	{
		OCR0A = 192;														// 75% speed
	}
	else
	{
		OCR0A = 255;														// 100% speed
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
		System_Control();
		
		if(state)
		{
			float temperature;
			adc_value = ADC_Read(0);										// Read from analog channel 0 (A0 pin of arduino)
			temperature = adc_value*0.488;									// Converting adc value into Temperature
			
			Motor_Speed(temperature);										// Control Motor speed
		}
		else
		{
			OCR0A = 0;														// Motor OFF
		}
    }
}

