/*
 * LCD_Button_Press_Program.c
 *
 * Created: 11-05-2026 7.54.38 PM
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

uint32_t counter = 0;

void LCD_Display(uint32_t count)
{
	lcd_clear();
	lcd_set_cursor(0,0);
	
	char buffer[10];
	sprintf(buffer,"%09lu", count);
	
	lcd_print(buffer);
}

void Button_check(void)
{
	uint16_t press_time = 0;
	
	if(!(PIND & (1 << PIND2)))
	{
		_delay_ms(20);								// Debounce delay
		
		if(!(PIND & (1 << PIND2)))
		{
			while(!(PIND & (1 << PIND2)))
			{
				_delay_ms(10);
				press_time += 10;
				
				if(press_time >= 2000)
				{
					counter = 0;
					
					LCD_Display(counter);
					
					while(!(PIND & (1 << PIND2)));
					
					return;
				}
			}
			counter++;
			
			if(counter > 999999999)
			{
				counter = 0;
			}
			LCD_Display(counter);
		}
	}
}

int main(void)
{
	DDRD &= ~(1 << DDD2);							// Input for Push-Button
	PORTD |= (1 << PORTD2);							// Enable Pull-up
	
	lcd_init();										// Initialize LCD Display

	LCD_Display(counter);	
    /* Replace with your application code */
    while (1) 
    {
		Button_check();
    }
}

