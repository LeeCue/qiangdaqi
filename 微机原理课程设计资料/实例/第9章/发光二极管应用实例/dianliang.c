#include<reg51.h>
#define uint unsigned int
sbit LED=P1^0;
void main()              
{
  while(1)
  {
    LED=0;		 //P1.0引脚输出低电平
  }
 }
