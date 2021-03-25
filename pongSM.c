#include "config.h"
#include "configTMR0.h"
#include "arrays.h"
#include "splashScreen.h"
#include "drawPaddle.h"
#include "writeMatrix.h"
#include "printDigit.h"
uchar pongSM(uchar state)
{
    switch(state)
    {
        case 0:
        splashScreen(splishR, splishL);
         __delay_ms(250);   
         state = 1;
        break;            // display 'PONG' splashscreen for 1 sec, then clear screen
        
        case 1:
         splashScreen(plyL, plyR);// display L 1 R 2 player
         while(LPB1&&RPB1==HI);     // wait for player selection button press
         if(LPB1==LO&&RPB1==HI)     // L = 1 plyr, R = 2 plyr
         {
             selectFlag = LO;                    // player 1 mode
             state = 2;
         }
         else if(LPB1==HI&&RPB1==LO)
         {
             selectFlag = HI;                    // player 2 mode
             state = 3;
         }
        break;
        
        case 2:
        
        writeMatrix(0,7,0,15);              // write gameArray[][] which contains all zeros
        drawPaddle(lPaddle, 0);             // draw paddle on left col 0 
        writeMatrix(0,7,0,0);
        drawPaddle(rBarrier,15);            // draw wall on right col 15
        writeMatrix(0,7,15,15);
        state = 4;
        break;
        
        
        case 3:
        
        writeMatrix(0,7,0,15);             // write gameArray[][] which contains all zeros
        drawPaddle(lPaddle, 0);             // draw paddle on left col 0 
        writeMatrix(0,7,0,0);
        drawPaddle(rPaddle,15);            // draw paddle on right col 15
        writeMatrix(0,7,15,15);
        state = 4;
        break;
        
        case 4:
           // gameArray[5][1] = HI;       // draw ball at row 5, col 1
           // writeMatrix(0,7,1,1);
            
            printDigit(6,8,tres, matrixL);       // count down from 3 to 0 before ball starts to move
            __delay_ms(100);
            printDigit(6,8,dos, matrixL);
            __delay_ms(100);
            printDigit(6,8,uno, matrixL);
            __delay_ms(100);
            printDigit(6,8,cero, matrixL);
            __delay_ms(100);
            printDigit(6,8,null, matrixL);
            state = 5;
        break;
            
        case 5:
              configTMR0();          //start ball moving
            
              icol = 1;
              irow = 5;
              state = 6;
        break;
        
        case 6:
        break;    
            
        
    }
    return state;
}
