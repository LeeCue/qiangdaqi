#include<reg52.h>
unsigned char code tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char code graph[]={0x30,0x48,0x44,0x22,0x44,0x48,0x30,0x00};
unsigned char cnta;
void main(void)
{
TMOD=0x01;
TH0=(65536-4000)/256;
TL0=(65536-4000)%256;
TR0=1;
ET0=1;
EA=1;
while(1);
}
void t0(void) interrupt 1 using 0
{
TH0=(65536-4000)/256;
TL0=(65536-4000)%256;
P1=tab[cnta];
P0=graph[cnta];
cnta++;
	if(cnta==8)
	{
	cnta=0;
	}
}
