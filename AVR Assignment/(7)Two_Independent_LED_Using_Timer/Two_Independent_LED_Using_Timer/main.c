/*
 * Two_Independent_LED_Using_Timer.c
 *
 * Created: 05-05-2026 6.41.57 PM
 * Author : HP
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t t2_count = 0;

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PORTB1);								// Status LED is High
}

ISR(TIMER2_COMPA_vect)
{
	t2_count++;
	if(t2_count >= 63)
	{
		PORTB ^= (1 << PORTB2);							// Heartbeat LED is High
		t2_count = 0;
	}
}


int main(void)
{
	DDRB |= (1 << DDB1);								// Set output for Status LED
	DDRB |= (1 << DDB2);								// Set output for Heartbeat LED
	
	// Timer1 (16-bit)
	TCCR1B |= (1 << WGM12);								// CTC MODE
	TCCR1B |= (1 << CS12) | (1 << CS10);				// Prescalar 1024
	OCR1A = 31249;
	
	TIMSK1 |= (1 << OCIE1A);							// Enable Timer1 Compare Match A Interrupt
	
	// Timer 2 (8-bit)
	TCCR2A |= (1 << WGM21);								// CTC MODE
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);	// Prescalar 1024
	OCR2A = 124;
	
	TIMSK2 |= (1 << OCIE2A);							// Enable Timer2 Compare Match A Interrupt
	
	sei();												// Enable Interrupts
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

