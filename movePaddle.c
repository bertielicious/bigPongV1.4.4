#include "config.h"
#include "arrays.h"
void movePaddle(bool array[], bool LR, bool direction)
{
    uchar col, row;
    bool temp;
    if(LR == R)
    {
        col = 15;
    }
    else if(LR == L)
    {
        col = 0;
    }
    
    for(row = 0; row<8; row++)
    {
        gameArray[row][col] = 0;  // clear paddle so that unwanted bits are erased from LED matrix
    }
    if(direction == HI)
    {
        // move up code
        temp = array[0];
        for(row = 0; row < 7; row++)
        {
            array[row] = array[row + 1];
            gameArray[row][col] = gameArray[row][col] | array[row];
        }
        array[7] = temp;
        gameArray[7][col] = gameArray[7][col] | array[7];
    }
    if(direction == LO)
    {
        //move down code
        temp = array[7];
        for(row = 7; row >0; row--)
        {
            array[row] = array[row - 1];
            gameArray[row][col] = gameArray[row][col] | array[row];
        }
        array[0] = temp;  
        gameArray[0][col] = gameArray[0][col] | array[0];
    }  
}
 