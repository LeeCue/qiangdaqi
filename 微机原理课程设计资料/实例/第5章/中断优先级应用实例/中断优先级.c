#include<reg51.h>
#define uchar unsigned char		//宏定义
void delay(uchar c)   			//延时子程序 Cms,误差 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void INT_0() interrupt 0			//外部中断0子程序
{
 EX0=0;						//关闭外部中的，防止在执行再次中断
 delay(20);					//延时20ms，去抖动
 EX0=1;						//开外部中断0
 while(1)					//led向下循环点亮，代表发生外部中断0
 {
 	P1=0xFE;delay(200);
 	P1=0xFD;delay(200);
 	P1=0xFB;delay(200);
 	P1=0xF7;delay(200);
 	P1=0xEF;delay(200);
 	P1=0xDF;delay(200);
 	P1=0xBF;delay(200);
 	P1=0x7F;delay(200);
}
}
void INT_1() interrupt 2	//外部中断1子程序
{
 EX1=0;						//关闭外部中的，防止在执行再次中断
 delay(20);					//延时20ms，去抖动
 EX1=1;						//开外部中断1
 P1=0xFF;delay(200);		//led全部点亮，闪烁三次，代表发生外部中1
 P1=0x00;delay(200);
 P1=0xFF;delay(200);
 P1=0x00;delay(200);
 P1=0xFF;delay(200);
}
void main()              
 {
 	P1=0x00;
  	EX0=1;					//打开外部中断0
	IP=0x04;				//外部中断1为优先级
  	IT0=1;					//设置中断触发方式为下降沿触发方式
	EX1=1;
	IT1=1;
  	EA=1;					//打开总中断
  while(1);					//死循环
}
