/*
 * oled.h
 *
 * Created: 16-05-2026 7.38.53 PM
 *  Author: HP
 */ 

#include <avr/io.h>

#ifndef OLED_H_
#define OLED_H_

void OLED_init(void);
void OLED_clear(void);
void OLED_setCursor(uint8_t x, uint8_t y);
void OLED_char(char ch);
void OLED_print(char *str);

#endif /* OLED_H_ */