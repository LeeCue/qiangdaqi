#include<reg51.h>
#define uchar unsigned char
unsigned int j,k,i,a,A1,A2,second;
sbit dula=P2^6;//段选信号
sbit wela=P2^7;//位选信号
uchar code table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//共阴数码管编码表
void delay(int i)//延时子程序
{
for(j=i;j>0;j--)
for(k=125;k>0;k--);
}
void display(uchar sh_c,uchar g_c)//显示子程序
{
wela=0;dula=0;P0=0xfe;wela=1;wela=0;P0=table[sh_c];dula=1;dula=0;delay(5);//完成十位显示
wela=0;dula=0;P0=0xfd;wela=1;wela=0;P0=table[g_c];dula=1;dula=0;delay(5);//完成个位显示
}
void main()
{	second=0;
	while(1)
	{
	if(second==60)second=0;
	A1=second/10;
	A2=second%10;
for(a=50;a>0;a--)display(A1,A2);
	second++;
	}
}