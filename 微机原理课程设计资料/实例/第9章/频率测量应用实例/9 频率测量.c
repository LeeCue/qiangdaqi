#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code number[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
//共阴数码管编码表
uchar code address[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//数码管选择编码表
uchar i,time;
uint count=0;
uint temp;
bit flag;
void delay(uint m)
{
	while(m--);
}

void main(void)
{
   EA=1;//开总中断
   ET0=1;//开定时器0中断
   ET1=1;//开定时器1中断
   TMOD=0x16;//设置T1为定时器工作方式为；T0为计数器，工作方式为2
   TH0=0xff;
   TL0=0xff;//给计数器0赋初值，计数值为1，即每来次中断信号，T0中断一次
   TR0=1;//启动计数器0
   TH1=(65536-50000)/256;
   TL1=(65536-50000)%256;//给定时器1赋初值，时间为50ms（12MHz）
   TR1=1;//启动定时器1.
while(1)//死循环
  {
   if(flag==1)//定时达满标志
    {
	 temp=count;//储存计数器0的计数值
	 for(i=0;i<5;i++)//将计数值各个位取出，并从P1口输出
	  {
	   P2=address[i];
	   P1=number[temp%10];
	   temp=temp/10;
	   delay(500);//数码管动态显示，注意延时时间
	  }	
	}
   }
}

void time0(void) interrupt 1//计数器中断子程序
{
 count++;//每中断一次count加1
}		  

void time1(void) interrupt 3//定时器中断子程序
{
  TH1=(65536-50000)/256;
  TL1=(65536-50000)%256;//重新给定时器赋初值
  time++;//总定时时长：20x50ms=1s
  if(time==20)
  {
   EA=0;//关闭总中断
   flag=1;//定时达满标志置1
  }
} 
