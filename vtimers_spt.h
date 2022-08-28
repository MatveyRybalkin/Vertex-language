#ifndef TIMERBASESUPPORT_H_INCLUDED
#define TIMERBASESUPPORT_H_INCLUDED

//Timer 0 (1/2 channels)

#ifdef TCCR0
#define Timer0_Fast_PWM();      TIM0_OUTPUT();\
                                TCCR0 |= (1 << WGM01) | (1 << WGM00);\
                                TCCR0 |= (1 << COM00);\
                                TCCR0 |= (1 << CS00);

#define Timer0PhaseCorrect();   	TIM0_OUTPUT();\
                                    TCCR0 |= (1 << WGM00);\
                                    TCCR0 |= (1 << COM00);\
                                    TCCR0 |= (1 << CS00);
#endif

#ifdef TCCR0A
#define Timer0_Fast_PWM();  TIM0_OUTPUT();\
                            TCCR0A |= (1 << COM0A1);\
                            TCCR0A |= (1 << COM0B1);\
                            TCCR0A |= (1 << WGM00)|(1 << WGM01);\
                            TCCR0B |= (1 << CS00);

#define Timer0PhaseCorrect();   TIM0_OUTPUT();\
                                TCCR0A |= (1 << COM0A1);\
                                TCCR0A |= (1 << COM0B1);\
                                TCCR0A |= (1 << WGM00);\
                                TCCR0B |= (1 << CS01);
#endif


//Timer 1 (1/2 channels)

#ifdef TCCR1
#define Timer1_Fast_PWM();  	TIM1_OUTPUT();\
                                TCCR1 |= (1 << WGM11) | (1 << WGM10);\
                                TCCR1 |= (1 << COM11);\
                                TCCR1 |= (1 << CS10);

#define Timer1PhaseCorrect();   	TIM1_OUTPUT();\
                                    TCCR1 |= (1 << WGM10);\
                                    TCCR1 |= (1 << COM11);\
                                    TCCR1 |= (1 << CS10);
#endif

#ifdef TCCR1A
#define Timer1_Fast_PWM();  TIM1_OUTPUT();\
                            TCCR1A |= (1 << COM1A1);\
                            TCCR1A |= (1 << COM1B1);\
                            TCCR1A |= (1 << WGM10);\
                            TCCR1B |= (1 << CS10)|(1 << WGM12);

#define Timer1PhaseCorrect();   TIM1_OUTPUT();\
                                TCCR1A |= (1 << COM1A1);\
                                TCCR1A |= (1 << COM1B1);\
                                TCCR1A |= (1 << WGM10);\
                                TCCR1B |= (1 << CS11);

#endif

//Timer 2 (1/2 channels)

#ifdef TCCR2
#define Timer2_Fast_PWM();  	TIM2_OUTPUT();\
                                TCCR2 |= (1 << WGM21) | (1 << WGM20);\
                                TCCR2 |= (1 << COM21);\
                                TCCR2 |= (1 << CS20);

#define Timer2PhaseCorrect();   	TIM2_OUTPUT();\
                                    TCCR2 |= (1 << WGM20);\
                                    TCCR2 |= (1 << COM21);\
                                    TCCR2 |= (1 << CS20);
#endif

#ifdef TCCR2A
#define Timer2_Fast_PWM();  TIM2_OUTPUT()\
                            TCCR2A |= (1 << COM2A1);\
                            TCCR2A |= (1 << COM2B1);\
                            TCCR2A |= (1 << WGM20)|(1 << WGM21);\
                            TCCR2B |= (1 << CS20);

#define Timer2PhaseCorrect();   TIM2_OUTPUT();\
                                TCCR2A |= (1 << COM2A1);\
                                TCCR2A |= (1 << COM2B1);\
                                TCCR2A |= (1 << WGM20);\
                                TCCR2B |= (1 << CS21);
#endif

#endif // TIMERBASESUPPORT_H_INCLUDED
