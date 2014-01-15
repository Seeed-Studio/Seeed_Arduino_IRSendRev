// ir send demo
// ir connect to D3, must D3!

#include <IRSendRev.h>

#define BIT_LEN         0
#define BIT_START_H     1
#define BIT_START_L     2
#define BIT_DATA_H      3
#define BIT_DATA_L      4
#define BIT_DATA_LEN    5
#define BIT_DATA        6

const int ir_freq = 38;                 // 38k

unsigned char dtaSend[20];

void dtaInit()
{
    dtaSend[BIT_LEN]        = 9;
    dtaSend[BIT_START_H]    = 180;
    dtaSend[BIT_START_L]    = 90;
    dtaSend[BIT_DATA_H]     = 11;
    dtaSend[BIT_DATA_L]     = 31;
    
    dtaSend[BIT_DATA_LEN]   = 4;
    
    dtaSend[BIT_DATA+0]     = 1;
    dtaSend[BIT_DATA+1]     = 2;
    dtaSend[BIT_DATA+2]     = 3;
    dtaSend[BIT_DATA+3]     = 4;
}

void setup()
{
    dtaInit();
}


void loop()
{
    IR.Send(dtaSend, 38);
    
    dtaSend[BIT_DATA]++;
    delay(1000);
}