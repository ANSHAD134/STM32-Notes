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


int main(void)
{
	DDRD |= (1 << DDD6);													// Set PD6 for Output Motor
	
	DDRD &= ~(1 << DDD2);													// Output for Push-Button
	PORTD |= (1 << PORTD2);													// Enable Pull-up
	
	uint16_t adc_value;
	ADC_init();	
    /* Replace with your application code */
    while (1) 
    {
		adc_value = ADC_Read(0);											// Read from analog channel 0 (A0 pin of arduino)
    }
}

