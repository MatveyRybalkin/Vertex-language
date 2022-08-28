#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

//Standart AVR library;
#include <avr/io.h>

//The basis of the Vertex language, and syntax;
#include "vbase.h"
//Basic operation with input/output ports;
#include "vport.h"
//Basic operation with ADC;
#include "vadc.h"

/******************************************************************/

//ATmega328P microcontroller;
#if defined(__AVR_ATmega328P__)

#include "boards/Atmega328P.h"

#endif


/******************************************************************/

#ifdef SUPPORT_MICROCONTROLLER_INDEX

void delay_loop_2(unsigned short __count){
	__asm__ volatile (
	"1: sbiw %0,1" "\n\t"
	"brne 1b"
	: "=w" (__count)
	: "0" (__count)
	);
}

void Delay(double __ms) {
	unsigned short __ticks;
	double __tmp = ((F_CPU) / 4e3) * __ms;
	if (__tmp < 1.0)
	__ticks = 1;
	else if (__tmp > 65535){
		__ticks = (unsigned short) (__ms * 10.0);
		while (__ticks){
			delay_loop_2(((F_CPU) / 4e3) / 10);
			__ticks --;
		}
		return;
		}else{
		__ticks = (unsigned short)__tmp;
	}
	delay_loop_2(__ticks);
}

void DelayMicroseconds(double __ms) {
	__ms /= 1000;
	unsigned short __ticks;
	double __tmp = ((F_CPU) / 4e3) * __ms;
	if (__tmp < 1.0)
	__ticks = 1;
	else if (__tmp > 65535){
		__ticks = (unsigned short) (__ms * 10.0);
		while (__ticks){
			delay_loop_2(((F_CPU) / 4e3) / 10);
			__ticks --;
		}
		return;
		}else{
		__ticks = (unsigned short)__tmp;
	}
	delay_loop_2(__ticks);
}
#include "vtimers_spt.h"

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

void DigitalWrite(unsigned char port, unsigned char port_type, bool b){
    if(b != 0){
        _SFR_IO8(port_type) |= (1 << port);
    }else{
        _SFR_IO8(port_type) &= ~(1 << port);
    }
}

bool DigitalRead(unsigned char port, unsigned char port_type){
    return ((_SFR_IO8(port_type - 2) & 1 << port)!= 0);
}

void PinMode(unsigned char port, unsigned char port_type, unsigned char type){
    if(type != 0){
        _SFR_IO8(port_type - 1) |= (1 << port);
    }else{
        _SFR_IO8(port_type - 1) &= ~(1 << port);
    }
}

/****************************************************/


#else

#include "vtimers.h"

#ifndef F_CPU

#warning  "The frequency is not specified. By default, the frequency= 10000000UL."

#endif

#warning  "The current microcontroller is not supported, some functions may not be available."

#endif

#endif // VERTEX_H_INCLUDED
