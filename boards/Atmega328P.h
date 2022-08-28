#ifndef ATMEGA328P_H_INCLUDED
#define ATMEGA328P_H_INCLUDED

#define F_CPU 16000000UL
#define SUPPORT_MICROCONTROLLER_INDEX 328
#define TypeB 0x05
#define TypeC 0x08
#define TypeD 0x0B

#define TIM0_OUTPUT();      DDRD |= (1 << 6) | (1 << 5);
#define TIM1_OUTPUT();      DDRB |= (1 << PB1) | (1 << PB2);
#define TIM2_OUTPUT();      DDRB |= (1 << PB3);\
                            DDRD |= (1 << PD3);

void PD6_Normal(void){
    TCCR0A &= ~(1 << COM0A1);
}

void PD5_Normal(void){
    TCCR0A &= ~(1 << COM1A1);
}

void PB2_Normal(void){
    TCCR1A &= ~(1 << COM1B1);
}

void PB1_Normal(void){
    TCCR1A &= ~(1 << COM1A1);
}

void PB3_Normal(void){
    TCCR2A &= ~(1 << COM2A1);
}

void PD3_Normal(void){
    TCCR2A &= ~(1 << COM2B1);
}

/** Timer 0 Fast PWM  **/

void PD6_Fast_PWM(void){
    DDRD |= (1 << 6);
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << WGM00)|(1 << WGM01);
    TCCR0B |= (1 << CS00);
}


void PD5_Fast_PWM(void){
    DDRD |= (1 << 5);
    TCCR0A |= (1 << COM0B1);
    TCCR0A |= (1 << WGM00)|(1 << WGM01);
    TCCR0B |= (1 << CS00);
}

#define PD6_PWM();   PD6_Fast_PWM();
#define PD5_PWM();   PD5_Fast_PWM();


/** Timer 1 Fast PWM  **/

void PB1_Fast_PWM(void){
    DDRB |= (1 << 1);
    TCCR1A |= (1 << COM1A1);
    TCCR1A |= (1 << WGM10);
    TCCR1B |= (1 << CS10)|(1 << WGM12);
}


void PB2_Fast_PWM(void){
    DDRB |= (1 << 2);
    TCCR1A |= (1 << COM1B1);
    TCCR1A |= (1 << WGM10);
    TCCR1B |= (1 << CS10)|(1 << WGM12);
}


#define PB1_PWM();   PB1_Fast_PWM();
#define PB2_PWM();   PB2_Fast_PWM();

/** Timer 2 Fast PWM  **/

void PB3_Fast_PWM(void){
    DDRB |= (1 << 3);
    TCCR2A |= (1 << COM2A1);
    TCCR2A |= (1 << WGM20)|(1 << WGM21);
    TCCR2B |= (1 << CS20);
}

void PD3_Fast_PWM(void){
    DDRD |= (1 << 3);
    TCCR2A |= (1 << COM2B1);
    TCCR2A |= (1 << WGM20)|(1 << WGM21);
    TCCR2B |= (1 << CS20);
}

#define PB3_PWM();   PB3_Fast_PWM();
#define PD3_PWM();   PD3_Fast_PWM();


/** Timer 0 Phase Correct **/

void PD6_PhaseCorrtect(void){
    DDRD |= (1 << 6);
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << WGM00);
    TCCR0B |= (1 << CS01);
}

void PD5_PhaseCorrtect(void){
    DDRD |= (1 << 5);
    TCCR0A |= (1 << COM0B1);
    TCCR0A |= (1 << WGM00);
    TCCR0B |= (1 << CS01);
}

#define PD6_PCPWM();   PD6_PhaseCorrtect();
#define PD5_PCPWM();   PD5_PhaseCorrtect();

/** Timer 1 Phase Correct **/


void PB1_PhaseCorrect(void){
    DDRB |= (1 << 1);
    TCCR1A |= (1 << COM1A1);
    TCCR1A |= (1 << WGM10);
    TCCR1B |= (1 << CS11);
}

void PB2_PhaseCorrect(void){
    DDRB |= (1 << 2);
    TCCR1A |= (1 << COM1B1);
    TCCR1A |= (1 << WGM10);
    TCCR1B |= (1 << CS11);
}

#define PB1_PCPWM();   PB1_PhaseCorrect();
#define PB2_PCPWM();   PB2_PhaseCorrect();

/** Timer 2 Phase Correct **/

void PB3_PhaseCorrect(void){
    DDRB |= (1 << 3);
    TCCR2A |= (1 << COM2A1);
    TCCR2A |= (1 << WGM20);
    TCCR2B |= (1 << CS21);
}

void PD3_PhaseCorrect(void){
    DDRD |= (1 << 3);
    TCCR2A |= (1 << COM2B1);
    TCCR2A |= (1 << WGM20);
    TCCR2B |= (1 << CS21);
}

#define PB3_PCPWM();   PB3_PhaseCorrect();
#define PD3_PCPWM();   PD3_PhaseCorrect();

#endif // ATMEGA328P_H_INCLUDED
