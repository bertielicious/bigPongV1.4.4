#include "config.h"
#include <stdbool.h>
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "arrays.h"
// function displays a messsage on left and right LED matrix, using a pair of arrays in array.h
void splashScreen(uchar *ptr1, uchar *ptr2)
{
    uchar row;

    for (row = 1; row<9; row++)
    {
    CS = LO;
    sendNoSPIbyte();
    
    sendSPIbyte(row, *ptr1);
    CS = HI;
    
    CS = LO;
    sendSPIbyte(row, *ptr2);
   
    sendNoSPIbyte();
    CS = HI;
    
    ptr1++;
    ptr2++;
    }
}
   
