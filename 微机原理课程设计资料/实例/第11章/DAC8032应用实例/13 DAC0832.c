#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit cs=P3^7;
sbit wr=P3^6;
void delay(uint m)
{
	while(m--);
}
void main()
{
 uchar k=0;
 cs=0;
 wr=0;
  while(1)
 { 
  while(1)
  {
   P0=k++;
   delay(100);
   if(k==0xff)
   break;
  }
  while(1)
  {
   P0=k--;
   delay(100);
   if(k==0)
   break;
  }
 }
}
