#ifndef VPORT_H_INCLUDED
#define VPORT_H_INCLUDED

#ifdef DDRA

#define InputTypeA(a);  DDRA &= ~(1 << a);
#define OutputTypeA(a); DDRA |= (1 << a);

#define PortA1(a); PORTA |= (1 << a);
#define PortA0(a); PORTA &= ~(1 << a);

#define ReadA(a) ((PINA & 1 << a)!=0)

void PortA(unsigned char numb, bool b){
	if(b != 0){
		PORTA |= (1 << numb);
		}else{
		PORTA &= ~(1 << numb);
	}
}

#endif

#ifdef DDRB

#define InputTypeB(a);  DDRB &= ~(1 << a);
#define OutputTypeB(a); DDRB |= (1 << a);

#define PortB1(a); PORTB |= (1 << a);
#define PortB0(a); PORTB &= ~(1 << a);

#define ReadB(a) ((PINB & 1 << a)!=0)

void PortB(unsigned char numb, bool b){
	if(b != 0){
		PORTB |= (1 << numb);
		}else{
		PORTB &= ~(1 << numb);
	}
}

#endif

#ifdef DDRC

#define InputTypeC(a);  DDRC &= ~(1 << a);
#define OutputTypeC(a); DDRC |= (1 << a);

#define PortC1(a); PORTC |= (1 << a);
#define PortC0(a); PORTC &= ~(1 << a);

#define ReadC(a) ((PINC & 1 << a)!=0)

void PortC(unsigned char numb, bool b){
	if(b != 0){
		PORTC |= (1 << numb);
		}else{
		PORTC &= ~(1 << numb);
	}
}

#endif

#ifdef DDRD

#define InputTypeD(a);  DDRD &= ~(1 << a);
#define OutputTypeD(a); DDRD |= (1 << a);

#define PortD1(a); PORTD |= (1 << a);
#define PortD0(a); PORTD &= ~(1 << a);

#define ReadD(a) ((PIND & 1 << a)!=0)

void PortD(unsigned char numb, bool b){
	if(b != 0){
		PORTD |= (1 << numb);
		}else{
		PORTD &= ~(1 << numb);
	}
}

#endif

#endif // VPORT_H_INCLUDED
