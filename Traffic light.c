/*
 P1.0=G1 P1.1=G2 P1.2=G3 P1.3=G4
 P1.4=Y1 P1.5=Y2 P1.6=Y3 P1.7=Y4
 P2.0=R1 P2.1=R2 P2.2=R3 P2.4=R4
 */

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= 0xFF;
    P2DIR |= 0x17;

    while(1)
    {
        volatile unsigned long i;

        P1OUT |= BIT0;                // G1
        P1OUT &= ~0xFE;
        P2OUT &= ~BIT0;
        P2OUT |= 0x16;
        for(i=0;i<480000000;i++);

        P1OUT |= BIT4;                // Y1
        P1OUT &= ~0xEF;
        P2OUT &= ~BIT0;
        P2OUT |= 0x16;
        for(i=0;i<48000000;i++);

        P1OUT |= BIT1;                // G2
        P1OUT &= ~0xFD;
        P2OUT &= ~BIT1;
        P2OUT |= 0x15;
        for(i=0;i<400000000;i++);

        P1OUT |= BIT5;                // Y2
        P1OUT &= ~0xDF;
        P2OUT &= ~BIT1;
        P2OUT |= 0x15;
        for(i=0;i<48000000;i++);

        P1OUT |= BIT2;                // G3
        P1OUT &= ~0xFB;
        P2OUT &= ~BIT2;
        P2OUT |= 0x13;
        for(i=0;i<24000000;i++);

        P1OUT |= BIT6;                // Y3
        P1OUT &= ~0xBF;
        P2OUT &= ~BIT2;
        P2OUT |= 0x13;
        for(i=0;i<48000000;i++);

        P1OUT |= BIT3;                // G4
        P1OUT &= ~0xF7;
        P2OUT &= ~BIT4;
        P2OUT |= 0x07;
        for(i=0;i<32000000;++);

        P1OUT |= BIT7;                // Y4
        P1OUT &= ~0x7F;
        P2OUT &= ~BIT4;
        P2OUT |= 0x07;
        for(i=0;i<48000000;i++);

    }
    return 0;
}
