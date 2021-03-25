#include "config.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
void init2Max7219(void)
{
    CS = 0;
 sendSPIbyte (shutdownModeAddr,shutdownNormalOperationData);//leave shutdown mode and enter normal                                                          //operation
 sendNoSPIbyte();
 CS = 1;

 CS = 0;
 sendSPIbyte (displayIntensityAddr,displayIntensityData);// minimum display intensity 1/32
 sendNoSPIbyte();
 CS = 1;

 CS = 0;
 sendSPIbyte (decodeModeAddr,noDecodeDigits0to7); // decode mode off
 sendNoSPIbyte();
 CS = 1;

 CS = 0;
 sendSPIbyte (scanLimitAddr,scanLimitData); // scan limit = 8 digits multiplexed
 sendNoSPIbyte();
 CS = 1; // LOAD is high
}
