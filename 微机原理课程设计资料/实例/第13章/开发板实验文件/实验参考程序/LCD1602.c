#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table1[]="   I LOVE NEUQ!";//显示字符
sbit lcden=P3^4;
sbit lcdrs=P3^5;
sbit dula=P2^6;
sbit wela=P2^7;
uchar num;
void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void write_com(uchar com)	//写命令
{
	lcdrs=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void write_data(uchar date)	//写数据
{
	lcdrs=1;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void init() //初始化
{
	dula=0;
	wela=0;
	lcden=0;
	write_com(0x38);
	write_com(0x0e);
	write_com(0x06);
	write_com(0x01);
	write_com(0x80+0x10);
}
void main()
{
	init();
	write_com(1);
	write_com(0x80+0x58);
	for(num=0;num<13;num++)
	{
		write_data(table1[num]);
		delay(20);
	}
	for(num=0;num<16;num++)
	{
		write_com(0x18);
		delay(20);
	}
	while(1);
}