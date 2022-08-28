#ifndef VADC_H_INCLUDED
#define VADC_H_INCLUDED

#define InitAnalog InitADC

void InitADC(void){
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

#define ReadAnalog ReadADC

uint16_t ReadADC(uint8_t ADCchannel){
	//select ADC channel with safety mask
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	// wait until ADC conversion is complete
	while( ADCSRA & (1<<ADSC) );
	return ADC;
}

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5

#endif // VADC_H_INCLUDED
