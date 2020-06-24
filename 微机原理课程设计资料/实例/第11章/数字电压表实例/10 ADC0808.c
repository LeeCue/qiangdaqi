#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
sbit START=P3^0;
sbit EOC=P3^1;
sbit OE=P3^2;
sbit dot=P1^0;
void delay(uint m)
{
	while(m--);
}
void main()              
 {
  uint temp; 
  START=0;
  OE=0;
  START=1;
  START=0;  
  while(1)
  {
     if(EOC==1)
    {
     OE=1;
     temp=P0;
     temp=temp*1.0/255*500;
     OE=0;

     P2=0xfe;
     P1=table[temp%10];
     delay(500);

     P2=0xfd;
     P1=table[temp/10%10];
     delay(500);	  

     P2=0xfb;
     P1=table[temp/100%10];
	 dot=1;
     delay(500);

     START=1;
     START=0;
	}
  }
 }

