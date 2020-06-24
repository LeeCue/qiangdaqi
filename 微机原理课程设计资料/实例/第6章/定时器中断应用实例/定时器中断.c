#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit LED=P1^0;//取P1.0口做为点亮发光二级管的输出信号
bit flag;//标志位，标志是否发生中断
uchar count=0;
void delay(uchar c)   //延时函数 Cms,误差 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void main(void)
{
	TMOD=0x01;//设置定时器0为定时模式1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;//给定时器0赋值初为50ms
	EA=1;   //开总中断
	ET0=1;  //开定时/计数器0	 
    TR0=1;  //启动定时/计数器0
	while(1)
     {
     if(flag==1)
     {LED=0;
	 delay(100);//延时100ms
	 LED=1;
	 flag=0;
	 }
     }
}

void time0(void) interrupt 1  //使数码管加一
{
  TH0=(65536-50000)/256;
  TL0=(65536-50000)%256;
  count++;
  if(count>=20)
  {
    count=0;
    flag=1;
  }
}
