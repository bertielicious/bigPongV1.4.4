#include "config.h"
void sendSPIbyte(uchar row, uchar col)
{
 SSP1BUFbits.SSPBUF = row; // send 8 bit address MSB first
 
 while (SSPSTATbits.BF == 0) // wait for 8 bits address data to transmit/ complete
    {
        ; // wait
    }
 SSP1BUFbits.SSPBUF = col; // send 8 bit data MSB second
 
 while (SSPSTATbits.BF == 0) // wait for 8 bits data / transmit complete
    {
        ; // wait
    }
 }

