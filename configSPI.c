
#include <pic16f1459.h>
#include "config.h"

void configSPI(void)
{
    ANSELA = 0x00;  // all Analogue inputs off
    ANSELB = 0x00;
    ANSELC = 0x00;
    CM1CON0 = 0x00; // all comparators off
    CM1CON0 = 0x00;
    CM1CON0 = 0x00;
    CM1CON0 = 0x00;
    
    SSPCON1bits.SSP1M3 = LO;    // 0001 = SPI Master mode, clock = FOSC/16 
    SSPCON1bits.SSP1M2 = LO;
    SSPCON1bits.SSP1M1 = LO;
    SSPCON1bits.SSP1M0 = LO;
    SSPCON1bits.CKP = LO;      // idle state for clock is low
    SSPCON1bits.SSPEN = HI;   // Enables serial port and configures SCK, SDO, SDI and SS as the source of the serial port pins
    SSPCON1bits.SSPOV = LO;
    SSPCON1bits.WCOL = LO;

    SSP1STATbits.CKE = HI;
    SSP1STATbits.SMP = HI;    // input data sampled at end of output data
    SSP1STATbits.BF = LO;
    CS = HI;    // disable MAX7219
}
