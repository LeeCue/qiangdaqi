#include "yejin.h"

uchar code table1[]={" I LOVE NEUQ!"};//��ʾ�ַ�
uchar num;
void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void write_com(uchar com)	//д����
{
	lcdrs=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void write_data(uchar date)	//д����
{
	lcdrs=1;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}
void init() //��ʼ��
{
	lcden=0;
	write_com(0x38);
	write_com(0x0e);
	write_com(0x06);
	write_com(0x01);
	write_com(0x80+0x10);
}
void display()
{	
	num++;
	if(num<13)
	{
		write_data(table1[num]);
		delay(20);
	}
	if(num>=13)
	{		
		write_com(0x18);
		delay(20);
	}
	if(num == 26){write_com(0x80); num = 0;}
	
	
}

