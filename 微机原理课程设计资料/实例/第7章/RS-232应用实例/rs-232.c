#include<reg51.h>
main()
{
P1=13;
TMOD=0x20;
SM0=0;SM1=1;REN=1;
PCON=0;//波特率不加倍
TH1=0xFD;
TL1=0xFD;//波特率9600，
TR1=1;
P1=SBUF;while(!RI);RI=0;
SBUF=P1;while(!TI);TI=0;
}

