#include "config.h"
void configPorts(void)
{
    TRISAbits.TRISA5 = LO;  // diagnostic LED GREEN pin 2
    TRISAbits.TRISA4 = LO;  // diagnostic LED RED pin 3
    TRISBbits.TRISB5 = LO;  // diagnostic LED BLUE pin 12
    TRISBbits.TRISB6 = LO;  // SCK is an output pin 11
    TRISCbits.TRISC7 = LO;  // SDO is an output pin 9
    TRISCbits.TRISC6 = LO; // select slave pin 8
    
    //********CLEAR ALL OUTPUTS**********************
    SDO = LO;
    SCK = LO;
    CS = LO;
   /***********************Pushbutton Inputs***********************/ 
    TRISCbits.TRISC5 = HI;  // Left pushbutton PLYR1 input pin 5
    TRISCbits.TRISC4 = HI;  // Right pushbutton PLYR1 input pin 6    
    
    TRISCbits.TRISC2 = HI;  // Left pushbutton PLYR2 input pin 14   
    TRISCbits.TRISC3 = HI;  // Right pushbutton PLYR2 input pin 7
}
