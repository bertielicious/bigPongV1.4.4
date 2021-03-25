#include "config.h"
#include "arrays.h"
void drawPaddle(bool paddle[], uchar col)
{
    uchar row;
    for(row = 0; row < 8; row++)
    {
        gameArray[row][col] = gameArray[row][col] | paddle[row];
    }
}
