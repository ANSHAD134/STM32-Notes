/*
 * adc.h
 *
 * Created: 16-05-2026 12.41.35 PM
 *  Author: HP
 */ 

#include <avr/io.h>

#ifndef ADC_H_
#define ADC_H_

void ADC_init(void);
uint16_t ADC_Read(uint8_t channel);



#endif /* ADC_H_ */