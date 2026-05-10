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
	ADCSRA |= (1 << ADEN)| (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);		// Enable ADC, Prescaler = 128
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

// Timer1 (16-bit)
void Timer1_Config(void)
{
	DDRB |=(1 << DDB1);														// Output for Servo motor
	
	TCCR1B |= (1 << CS11) | (1 << CS10);									// Prescalar 64
	TCCR1A |= (1 << WGM10) | (1 << WGM11);									// Fast PWM
	OCR1A = 20000;
}

int main(void)
{
	uint16_t adc_value;
	uint16_t servo_position;
	
	ADC_init();
	Timer1_Config();
	
    /* Replace with your application code */
    while (1) 
    {
		adc_value = ADC_Read(0);											// Read from analog channel 0
		
		servo_position = 1000 + ((adc_value * 1000UL) / 1023);				// ADC (0-1023) to Servo pulse (1000-2000)
		
		OCR1A = servo_position;
    }
}

