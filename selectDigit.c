#include "config.h"
#include "printDigit.h"
#include "arrays.h"
void selectDigit (uchar num, uchar rowL, uchar rowH, bool matrixLR)
{
    switch(num)
    {
            case 0:
            printDigit(rowL, rowH, cero, matrixLR);    
            break;
            
            case 1:
            printDigit(rowL, rowH, uno, matrixLR);    
            break;
            
            case 2:
            printDigit(rowL, rowH, dos, matrixLR);    
            break;
            
            case 3:
            printDigit(rowL, rowH, tres, matrixLR);    
            break;
            
            case 4:
            printDigit(rowL, rowH, cuatro, matrixLR);    
            break;
            
            case 5:
            printDigit(rowL, rowH, cinco, matrixLR);    
            break;
            
            case 6:
            printDigit(rowL, rowH, seis, matrixLR);    
            break;
            
            case 7:
            printDigit(rowL, rowH, siete, matrixLR);    
            break;
            
            case 8:
            printDigit(rowL, rowH, ocho, matrixLR);    
            break;
            
            case 9:
            printDigit(rowL, rowH, nueve, matrixLR);    
            break;
    }              
}