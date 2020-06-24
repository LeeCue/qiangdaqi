#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
//共阴数码管编码表
uchar code address[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//数码管选择编码表
void delay(uint);//什么延时子程序
void main()              
{
 uchar m=0;
 while(1)
 {
   if(m==8) m=0;//当m循环到8，则跳回0.
   P2=address[m];//P2口输出数码管选中信号，选中对应的数码管
   P1=table[m++];//P1口输出要输出是数字
   delay(500);  //延时显示
 }
}
void delay(uint m)//延时子程序，约500个机器周期
{
	while(m--);
}
