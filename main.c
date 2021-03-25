/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 02 March 2021, 21:21
 */


#include <xc.h>
#include "config.h"
#include "configOsc.h"
#include "configSPI.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configTMR0.h"
#include "configTMR1.h"
#include "configPorts.h"
#include "configUsart.h"
#include "putch.h"
#include "arrays.h"
#include "drawPaddle.h"
#include "movePaddle.h"
#include "writeMatrix.h"
#include "moveBall.h"
#include "pongSM.h"

void main(void) 
{
    bool paddleL[8] = {0,0,0,1,1,1,0,0};
    bool paddleR[8] = {0,0,1,1,1,0,0,0};
    uchar mainState = 0;
    
    configPorts();
    configOsc();
    configSPI();
    //configTMR0();
    //configTMR1();
    init1_max7219();
    init2Max7219();
    configUsart();
    printf("hello Phil\n");
    PORTAbits.RA5 = LO;
    PORTAbits.RA4 = LO;
    PORTBbits.RB5 = LO;
    
    
   
    
    writeMatrix(0,7,0,15);  // clear the LED matrix of garbage data
    drawPaddle(paddleL,0);   // draw the paddle possition to gameArray[row][col]
    writeMatrix(0,7,0,0);   // display the paddle on the LED matrix at col 0
    drawPaddle(paddleR,15);   // draw the paddle possition to gameArray[row][col]
    writeMatrix(0,7,15,15);   // display the paddle on the LED matrix at col 0*/
    
    
    while(1)
    {
        while(mainState <6)
        {
            mainState = pongSM(mainState);
            printf("mainState  %d\n", mainState);
        }
        
       
        // move left paddle code
        if(RPB1 == LO && gameArray[0][0] == LO)     //if RPB1 is pressed and top pixel in col 0 is not lit - test a
        {
            while(RPB1 == LO);  // wait while button pressed
            movePaddle(paddleL, L, UP);//move the left paddle array up 1 pixel
            if(gameArray[0][0] && boundary[0] == HI)// check whether the paddle has travelled to the highest position in col 0
            {
                continue;   // if it has, jump to test a
            }
        }
        if(LPB1 == LO && gameArray[7][0] == LO) 
        {
            while(LPB1 == LO);
            movePaddle(paddleL, L,DOWN);
            if(gameArray[7][0] && boundary[9] == HI)
            {
                continue;
            }
        }
        
        // move right paddle code
        if(RPB2 == LO && gameArray[0][15] == LO)
        {
            while(RPB2 == LO);
            movePaddle(paddleR, R, UP);
            if(gameArray[0][15] && boundary[0] == HI)
            {
                continue;
            }
        }
        if(LPB2 == LO && gameArray[7][15] == LO) 
        {
            while(LPB2 == LO);
            movePaddle(paddleR, R,DOWN);
            if(gameArray[7][15] && boundary[9] == HI)
            {
                continue;
            }
        }
        
        writeMatrix(0,7,0,0);   // display left paddle on LED matrix
        writeMatrix(0,7,15,15); // display right paddle on LED matrix 
    }
    return;
}
