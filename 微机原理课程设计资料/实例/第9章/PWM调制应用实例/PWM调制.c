#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int
sbit PWM=P2^0;
uchar n=0;
void delay(uchar m)   //  ÑÓÊ±0.m Ãë
{
    unsigned char a,b,c;
while(m--)
    for(c=19;c>0;c--)
        for(b=20;b>0;b--)
            for(a=130;a>0;a--);
}
void PWMout(uchar q)
{
	PWM=0;
	delay(10-q);
	PWM=1;
	delay(q);
}
void main()
{
EA=1;
EX0=1;
IT0=1;
while(1)
PWMout(n);
}
void INT() interrupt 0
{
if(n==10)n=0;
else n=n+1;
}
