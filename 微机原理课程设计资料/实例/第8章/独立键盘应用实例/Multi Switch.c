#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
uchar code table[]={0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
uchar num=0;
sbit led0=P1^0;
sbit led1=P1^1;
sbit led2=P1^2;
sbit led3=P1^3;
sbit key0=P1^4;
sbit key1=P1^5;
sbit key2=P1^6;
sbit key3=P1^7;
void delay(uint k)//ÑÓÊ±×Ó³ÌÐò
{
	uint i,j;
	for(i=7;i<k;i++)
		for(j=0;j<124;j++);
}
void main()              
 {
  while(1)
  {
    led0=key0;led1=key1;led2=key2;led3=key3;
  }
 }
