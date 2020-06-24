#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char//宏定义
uchar code table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//共阴数码管"0-9"编码表
uchar m=0;
void delay(uchar c)   //延时子程序 Cms,误差 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void INT_0() interrupt 0//外部中断0函数
{
 EX0=0;			//关闭外部中的，防止在执行再次中断
 delay(20);	//延时500ms，去抖动
 EX0=1;			//开中断
 if(m==10) m=0;	//当m=10时回到0
 else P1=table[m++];//循环输出"0-9"
}
void INT_1() interrupt 2//外部中断0函数
{
 EX1=0;			//关闭外部中的，防止在执行再次中断
 delay(20);	//延时500ms，去抖动
 EX1=1;			//开中断
 if(m==0) m=10;	//当m=0时回到10
 else P1=table[--m];//循环输出"0-9"
}
void main()              
 {
 	P1=0x00;
  	EA=1;		//打开总中断
  	EX0=1;	//打开外部中断0
  	IT0=1;	//设置中断触发方式为下降沿触发方式
	EX1=1;
	IT1=1;
  while(1);	//死循环
}

