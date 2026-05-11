/*
 * LCD_Button_Press_Program.c
 *
 * Created: 11-05-2026 7.54.38 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "LCD.h"

uint32_t counter = 0;

void LCD_Display(uint32_t count)
{
	lcd_clear();											// Clear LCD screen
	lcd_set_cursor(0,0);									// Set cursor at first row first column
	
	char buffer[11];										// Buffer to store 9-digit string
	sprintf(buffer,"%09lu", count);							// Convert integer into 9-digit string
	
	lcd_print(buffer);										// Print counter value on LCD
}

void Button_check(void)
{
	uint16_t press_time = 0;
	
	if(!(PIND & (1 << PIND2)))
	{
		_delay_ms(20);										// Debounce delay
		
		if(!(PIND & (1 << PIND2)))
		{
			while(!(PIND & (1 << PIND2)))
			{
				_delay_ms(10);								// Delay for timing
				press_time += 10;							// Increase press time
				
				if(press_time >= 2000)
				{
					counter = 0;							// Reset counter to zero
					
					LCD_Display(counter);					// Update LCD display
					
					while(!(PIND & (1 << PIND2)));			// Wait until button released
					
					return;
				}
			}
			counter++;										// Increment counter
			
			if(counter > 999999999)
			{
				counter = 0;								// Reset counter after reaching maximum 9-digit value
			}
			LCD_Display(counter);							// Update LCD display
		}
	}
}

int main(void)
{
	DDRD &= ~(1 << DDD2);									// Input for Push-Button
	PORTD |= (1 << PORTD2);									// Enable Pull-up
	
	lcd_init();												// Initialize LCD Display

	LCD_Display(counter);									// Display initial counter value
    /* Replace with your application code */
    while (1) 
    {
		Button_check();										// Continuously check button press
    }
}

