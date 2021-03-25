#include "config.h"
#include "sendNoSPIbyte.h"
#include "sendSPIbyte.h"
void printDigit(uchar rowL, uchar rowH, uchar *ptr, bool matrixLR)
{
    uchar row;
    
    for(row = rowL; row<=rowH; row++)
    {
        CS = LO;
        if(matrixLR == LO)
        {
            sendNoSPIbyte();        
            sendSPIbyte(row, *ptr);
        }
        else if(matrixLR == HI)
        {
        sendSPIbyte(row, *ptr);
        sendNoSPIbyte();
        }
        CS = HI;
    ptr++;
    }  
}
