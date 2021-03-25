#include "config.h"
void configTMR1(void)
{
    T1CONbits.TMR1CS1 = 0;  //Timer1 clock source is instruction clock (FOSC/4) 250kHz
    T1CONbits.TMR1CS0 = 0;
    TMR1H = 0;              // clear TMR1 16 bit register pair
    TMR1L = 0;
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.T1CKPS1 = 0;
    PIR1bits.TMR1IF = 0;    // clear TMR1 interrupt flag
    PIE1bits.TMR1IE = 1;
    INTCONbits.PEIE = 1;
    T1CONbits.TMR1ON = 1;
    INTCONbits.GIE = 1;
}


/*T1CON: TIMER1 CONTROL REGISTER
bit 7-6 TMR1CS<1:0>: Timer1 Clock Source Select bits
    11 = Timer1 clock source is Capacitive Sensing Oscillator (CAPOSC)
    10 = Timer1 clock source is pin or oscillator:
    If T1OSCEN = 0:
    External clock from T1CKI pin (on the rising edge)
    If T1OSCEN = 1:
    Crystal oscillator on T1OSI/T1OSO pins
    01 = Timer1 clock source is system clock (FOSC)
    00 = Timer1 clock source is instruction clock (FOSC/4)
bit 5-4 T1CKPS<1:0>: Timer1 Input Clock Prescale Select bits
    11 = 1:8 Prescale value
    10 = 1:4 Prescale value
    01 = 1:2 Prescale value
    00 = 1:1 Prescale value
bit 3 T1OSCEN: LP Oscillator Enable Control bit
    1 = Dedicated Timer1 oscillator circuit enabled
    0 = Dedicated Timer1 oscillator circuit disabled
bit 2 T1SYNC: Timer1 Synchronization Control bit
    1 = Do not synchronize asynchronous clock input
    0 = Synchronize asynchronous clock input with system clock (FOSC)
bit 1 Unimplemented: Read as ?0?
bit 0 TMR1ON: Timer1 On bit
        1 = Enables Timer1
0 = Stops Timer1 and clears Timer1 gate flip-flop
 * 
 * 
 *  SUMMARY OF REGISTERS ASSOCIATED WITH TIMER1
Name            Bit 7 Bit 6 Bit 5 Bit 4 Bit 3 Bit 2 Bit 1 Bit 0 Register

         ANSELA ? ? ? ANSA4 ? ? ? ? 129
        APFCON CLKRSEL SDOSEL(2) SSSEL ? T1GSEL P2SEL(2) ? ? 126
        INTCON GIE PEIE TMR0IE INTE IOCIE TMR0IF INTF IOCIF 93
         PIE1 TMR1GIE ADIE(3) RCIE TXIE SSP1IE ? TMR2IE TMR1IE 94
        PIR1 TMR1GIF ADIF(3) RCIF TXIF SSP1IF ? TMR2IF TMR1IF 96
        TMR1H Holding Register for the Most Significant Byte of the 16-bit TMR1 Count 179*
        TMR1L Holding Register for the Least Significant Byte of the 16-bit TMR1 Count 179*
        TRISA ? ? TRISA5 TRISA4 ?(1) ? ?(1) ?(1) 128
        T1CON TMR1CS<1:0> T1CKPS<1:0> T1OSCEN T1SYNC ? TMR1ON 187
        T1GCON TMR1GE T1GPOL T1GTM T1GSPM T1GGO/DONE T1GVAL T1GSS<1:0>
 * 
The TMR1H:TMR1L register pair and the
TMR1IF bit should be cleared before
enabling interrupts.
The Timer1 register pair (TMR1H:TMR1L) increments
to FFFFh and rolls over to 0000h. When Timer1 rolls
over, the Timer1 interrupt flag bit of the PIR1 register is
set. To enable the interrupt on rollover, the user must
set these bits:
? TMR1ON bit of the T1CON register
? TMR1IE bit of the PIE1 register
? PEIE bit of the INTCON register
? GIE bit of the INTCON register
The interrupt is cleared by clearing the TMR1IF bit in
the Interrupt Service Routine*/
