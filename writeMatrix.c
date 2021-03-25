/*
 * File:   writeMatrix.c
 * Author: Phil Glazzard
 *
 * Created on 04 December 2020, 14:48
 */


#include "config.h"
#include "arrays.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
void writeMatrix(uchar rowStart, uchar rowEnd, uchar colStart, uchar colEnd)
{
    uchar col, row, result = 0;
    for(col=colStart;col<colEnd+1;col++)
    {
      for(row=rowStart; row<rowEnd+1;row++)
            {
                if(gameArray[row][col]==1)
                {
                    binaryWeighting[row][col] = 1<<(7-row);
                    result = result + binaryWeighting[row][col];
                    
                }
                else
                {
                    continue;
                }  
                //printf("row = %d    col = %d    result = %d\n", row, col, result);//binaryWeighting[row][col]); 
            }       
 
    if(col<8)
    {
    CS = LO;
    sendNoSPIbyte();
    sendSPIbyte(col+1, result);
    CS = HI;
    }
    
    else
    {
    CS = LO;
    sendSPIbyte(col-7, result);
    sendNoSPIbyte();
    CS = HI;
    }
    result = 0; 
    } 
}