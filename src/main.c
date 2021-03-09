#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


volatile int extratimer = 0;

ISR(TIMER0_COMPA_vect) {
    extratimer += 1;
    if (extratimer == 100) {
        PORTA ^= 0xFF;
        extratimer = 0;
    }
    
}

int main(void)
{
    // make the LED pin an output for PORTA
    DDRA |= 0xFF;
    PORTA |= 0x00;

    TCCR0A |= _BV(COM0A1);
    TCCR0A &= ~_BV(COM0A0);

    TCCR0B |= _BV(CS02)|_BV(CS00);
    TCCR0B &= ~_BV(CS01);

    OCR0A = 160;
    sei();
    TIMSK0 = _BV(OCIE0A);
    
    
    while (1)
    {
        
    }

    return 0;
}

