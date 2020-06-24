#include<reg51.h>
sbit FM=P2^3;
sbit F=P3^4;
unsigned char k,j;
void delay(unsigned int i)
{
for(j=i;j>0;j--)
for(k=125;k>0;k--);
}
main()
{
while(1)
{
FM=0;
delay(2);
FM=1;
delay(2);
}
}