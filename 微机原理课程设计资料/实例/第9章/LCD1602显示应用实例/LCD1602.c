#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]=" I  LOVE MCS  ";
uchar code table1[]="      NEUQ     ";
sbit lcden=P3^4;
sbit lcdrs=P3^5;
uchar num;


void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void write_com(uchar com)
{
	lcdrs=0;//写命令
	P2=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}

void write_data(uchar date)
{
	lcdrs=1;//写数据
	P2=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void init()
{
	lcden=0;
	write_com(0x38);//初始化
	write_com(0x0e);//光标打开
	write_com(0x06);
	write_com(0x01);
	write_com(0x80+0x1);
}
void main()
{
	init();
delay(100);
EA=1;EX0=1;EX1=1;
	while(1);
}

void int0() interrupt 0

{

for(num=0;num<14;num++)//显示"Ying Ming Fei"
	{
		write_data(table[num]);
		delay(20);
	}
	write_com(2);//回车换行
	write_com(0x80+0x40);
	for(num=0;num<16;num++)//显示"5071418"
	{
		write_data(table1[num]);
		delay(20);
	}

}


void int1() interrupt 2

{


	write_com(1);//清屏

}
