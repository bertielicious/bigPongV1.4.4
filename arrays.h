/* 
 * File:   arrays.h
 * Author: Phil Glazzard
 *
 * Created on 25 November 2020, 19:20
 */


#include "config.h"
/****PONG splash screen*******/
const uchar splishR[8] = {0x7c,0x90,0x90,0x60,0x0c,0x12,0x12,0x0c};// column data
const uchar splishL[8] = {0x70,0x80,0x80,0x70,0x00,0x0e,0x15,0x17};

/****number of players screen message*****/
const uchar plyR[8] = {0xff, 0x00, 0x78, 0xfb, 0xc0, 0xc3, 0x80, 0x00};
const uchar plyL[8] = {0x00, 0xf8, 0xf8, 0x1b, 0x18, 0x18, 0x00, 0xff};

/***designation of 1 plyr or 2 plyr */
const uchar ply1R[8] = {0x7c, 0x90, 0x90, 0x60, 0x00, 0xf8, 0x04, 0x84};
const uchar ply1L[8] = {0x44, 0x20, 0x1c, 0x20, 0x40, 0x91, 0x3f, 0x01};

const uchar ply2L[8] = {0x44, 0x20, 0x1c, 0x20, 0x57, 0xa9, 0x29, 0x3d};
const uchar null[3] = {0x00, 0x00, 0x00};
const uchar cero[3] = {0xf8, 0x88, 0xf8};
const uchar uno[3] = {0x48, 0xf8, 0x08};
const uchar dos[3] = {0xb8, 0xa8, 0xe8};
const uchar tres[3] = {0x88, 0xa8, 0xf8};
const uchar cuatro[3] = {0xe0, 0x20, 0xf8};
const uchar cinco[3] = {0xe8, 0xa8, 0xb8};
const uchar seis[3] = {0xf8, 0xa8, 0xb8};
const uchar siete[3] = {0x80, 0xb8, 0xc0};
const uchar ocho[3] = {0xf8, 0xa8, 0xf8};
const uchar nueve[3] = {0xe8, 0xa8, 0xf8};

/*bool gameArray[8][16]= {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},  // gameArray[row][col] 1 player start position
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};*/
bool gameArray[8][16]= {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // gameArray[row][col] 1 player start position
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

uchar binaryWeighting[8][1]=   {{0},
                                {0},
                                {0},
                                {0},
                                {0},
                                {0},
                                {0},
                                {0}};
uchar scratchPad[8];
bool lPaddle[8] = {0,0,1,1,1,0,0,0};
bool rPaddle[8] = {0,0,0,1,1,1,0,0};
bool rBarrier[8]={1,1,1,1,1,1,1,1};
bool boundary[10] = {1,0,0,0,0,0,0,0,0,1};  // defines boundary of paddles
//uchar leftPad[8]= {0,1,1,1,0,0,0,0};
//uchar rightPad[8]={0,0,0,0,1,1,1,0};