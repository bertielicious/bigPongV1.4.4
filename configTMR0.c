
#include <pic16f1459.h>

#include "config.h"
void configTMR0(void)
{
    OPTION_REGbits.TMR0CS = LO; // 8 bit timer mode 0 - 255 then overflow
    OPTION_REGbits.PSA = LO;    // prescaler is assigned to TMR0
    OPTION_REGbits.PS2 = HI;    // 1 : 128 prescaler setting
    OPTION_REGbits.PS1 = HI;
    OPTION_REGbits.PS0 = LO;
    TMR0 = 0x00;                // clear TMR0 register - TMR0 starts counting from 0
    INTCONbits.TMR0IE = HI;     // enable TMR0 interrupt
    INTCONbits.GIE = HI;        // enable all active interrupts
    INTCONbits.TMR0IF = LO;     // clear TMRO interrupt flag to allow interrupt to occur
}
    
    /*configure TMR0 in timer mode to erase paddles and ball at 60Hz frame rate
     internal clock speed = 16MHz
     instruction cycle = fosc/4 = 4MHz
     instruction cycle is 0.25uS
     TMR0 register increments every 0.25uS (with no prescaler)
     TMR0 is 8bit register counting from 0 to 255 then overflows and sets TMR0IF
     We want TMR0 interrupt to fire at a frequency of 120Hz (every 8.3mS)
     TMR0 overflows after 255 * 0.25uS without prescaler = 63.75uS
     * 
     * 
     * OPTION_REG: OPTION REGISTER
    WPUEN INTEDG TMR0CS TMR0SE PSA PS<2:0>
    bit 7                           bit 0
     *  
     bit 7 WPUEN: Weak Pull-Up Enable bit
        1 = All weak pull-ups are disabled (except MCLR, if it is enabled)
        0 = Weak pull-ups are enabled by individual WPUx latch values
    bit 6 INTEDG: Interrupt Edge Select bit
        1 = Interrupt on rising edge of INT pin
        0 = Interrupt on falling edge of INT pin
    bit 5 TMR0CS: Timer0 Clock Source Select bit
        1 = Transition on T0CKI pin
        0 = Internal instruction cycle clock (FOSC/4)
    bit 4 TMR0SE: Timer0 Source Edge Select bit
        1 = Increment on high-to-low transition on T0CKI pin
        0 = Increment on low-to-high transition on T0CKI pin
    bit 3 PSA: Prescaler Assignment bit
        1 = Prescaler is not assigned to the Timer0 module
        0 = Prescaler is assigned to the Timer0 module
    bit 2-0 PS<2:0>: Prescaler Rate Select bits
     * 
       PS<2:0>       TMR0 rate
        000          1 : 2          127.5us
        001          1 : 4          255us
        010          1 : 8          510us
        011          1 : 16         1.02ms
        100          1 : 32         2.04ms
        101          1 : 64         4.08ms
        110          1 : 128        8.16ms
        111          1 : 256        16.32ms


    INTCON: INTERRUPT CONTROL REGISTER
     * 
     * GIE PEIE TMR0IE INTE IOCIE TMR0IF INTF IOCIF(1)
bit 7 
     *                                       bit 0
bit 7   GIE: Global Interrupt Enable bit
        1 = Enables all active interrupts
        0 = Disables all interrupts
bit 6   PEIE: Peripheral Interrupt Enable bit
        1 = Enables all active peripheral interrupts
        0 = Disables all peripheral interrupts
bit 5   TMR0IE: Timer0 Overflow Interrupt Enable bit
        1 = Enables the Timer0 interrupt
        0 = Disables the Timer0 interrupt
bit 4   INTE: INT External Interrupt Enable bit
        1 = Enables the INT external interrupt
        0 = Disables the INT external interrupt
bit 3   IOCIE: Interrupt-on-Change Enable bit
        1 = Enables the interrupt-on-change
        0 = Disables the interrupt-on-change
bit 2   TMR0IF: Timer0 Overflow Interrupt Flag bit
        1 = TMR0 register has overflowed
        0 = TMR0 register did not overflow
bit 1   INTF: INT External Interrupt Flag bit
    1 = The INT external interrupt occurred
    0 = The INT external interrupt did not occur
bit 0   IOCIF: Interrupt-on-Change Interrupt Flag bit(1)
    1 = When at least one of the interrupt-on-change pins changed state
    0 = None of the interrupt-on-change pins have changed state
     * 
Note 1: The IOCIF Flag bit is read-only and cleared when all the interrupt-on-change flags in the IOCBF register
have been cleared by software.





     */

