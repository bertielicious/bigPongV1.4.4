#include "config.h"
#include "sendSPIbyte.h"
void init1_max7219(void)
{
 CS = 0;
 sendSPIbyte (decodeModeAddr,noDecodeDigits0to7);//leave shutdown mode and enter normal operation
 CS = 1;    // load last 16 bits on rising edge

 CS = 0;
 sendSPIbyte (displayIntensityAddr,displayIntensityData);// minimum display intensity 1/32
 CS = 1;

 CS = 0;
 sendSPIbyte (scanLimitAddr,scanLimitData); // decode mode off
 CS = 1;

 CS = 0;
sendSPIbyte (shutdownModeAddr,shutdownNormalOperationData); // scan limit = 8 digits multiplexed
 CS = 1; // LOAD is high
}
/***********************MAX7219 CONSTANTS***********************************************
#define noOpAddr 0x00 // No operation address
#define noOpData 0x00 // No operation data

#define row0 0x01     // row 0 address
#define row1 0x02     // row 1 address
#define row2 0x03     // row 2 address
#define row3 0x04     // row 3 address
#define row4 0x05     // row 4 address
#define row5 0x06     // row 5 address
#define row6 0x07     // row 6 address
#define row7 0x08     // row 7 address

#define decodeModeAddr 0x09     //decode mode address
#define noDecodeDigits0to7 0x00 // no 7 seg decode of data

#define displayIntensityAddr 0x0A   // display intensity address
#define displayIntensityData 0x00   // 0x00 to 0x0f for max brightness

#define scanLimitAddr 0x0B      // scan limit address
#define scanLimitData 0x07      // 0x00 = 0 digit only, 0x07 = 7 digits

#define shutdownModeAddr 0x0C   // low power mode
#define shutdownNormalOperationData 0x01    //normal operation ie not shutdown*/
