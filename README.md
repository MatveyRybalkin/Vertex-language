# Vertex-language
Optimized C/C ++, as an alternative to arduino, supports most avr microcontrollers of the RISC architecture. Demo.

Foreword:
  You can use the Arduino style completely: DigitalWrite(port, b), for this you need to change the STYLE value to ARDUINO_STYLE.
  #define STYLE ARDUINO_STYLE
  or you can:
  #define STYLE AVR_STYLE
  to use AVR C++ style in functions.

Digital output functions:

  PortB(), PortC(), PortD() - functions that set a logical value on the MС port, accepting 2 values as input, a port number, and a logical value.

  DigitalWrite(port, port_type, b) - analogue digitalWrite functions . The function sets a logical value on the MС port.
  Example: DigitalWrite(5, TypeB, 1) - supply value 1 on port PB5.
  or DigitalWrite(13, 1)

Digital input functions:

  Functions: ReadB(), ReadC(), ReadD(). Returns a value from a port.
  Function DigitalRead(port, port_type). Analogue in Arduino style.
  or DigitalRead(port)
  
Setting the port type:

  InputTypeB(), OutputTypeB(), InputTypeC(), OutputTypeC(), InputTypeD(), OutputTypeD() - functions that set the input/output port mode. As an argument, take the port number.
  Function PinMode(port, port_type, type). Analogue in Arduino style.
  or PinMode(port, type)

Digital input functions:
  Timer-Counter Setting Functions:
  TimerX_Fast_PWM() - turns timer X into Fast-PWM mode.
  TimerX_PhaseCorrect() - Turns timer X into accurate phase mode.
  TimerXNormal - disable the X timer-counter.
  PXx_Fast_PWM - Sets a specific port to Fast PWM mode.
  PXx_PhaseCorrect - Sets the specified port to precise phase mode.
  PXx_Normal - disable the timer on a specific port.
  
  or in ARDUINO_STYLE:
    AnalogWrite(port, val); - This is currently being developed.
    
Functions for working with UART:
  UartInit() function. Complete analogue of the Serial.begin() function.
  UartOutByte() function. Sends a byte of information over the UART interface.
  UartInByte() function. Receives a byte of information via the UART interface.
  Function UartOutStr() (UartOutStrLn()). Sends a string of information over the UART interface.
    
Functions for working with EEPROM:
  EEPROM_WriteByte() function. Writes a byte of information to the non-volatile memory of the MK in the corresponding cell.
  EEPROM_ReadByte() function. Reads a byte of information from the corresponding non-volatile memory cell.


Math:
  complex(a, b) - struct for complex numbers
  sum_complex(complex a, complex b) - sum of two complex numbers
  sub_complex(complex a, complex b) - subtraction of two complex numbers
  mul_complex(complex a, complex b) - multiplication of two complex numbers
  div_complex(complex a, complex b) - division of two complex numbers

  You can use Catalan numbers with array: catalan[num]
  
  integral(double first, double last, double h, double(*F)(double x)) - Finds the area under the integral given the parameters. The last argument is a pointer to a function with one argument, of type double.
