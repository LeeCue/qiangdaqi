#include<reg51.h>


sbit csda=P3^2;
sbit dawr=P3^6;
unsigned char a,j,k;
void delay(unsigned char i)
{
for(j=i;j>0;j--)
for(k=125;k>0;k--);
}
void main()
{


csda=0;
a=0;
dawr=0;
while(1)
{
P0=a;
delay(5);
a++;
}
}