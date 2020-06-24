#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar code table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//共阴数码管编码表
sbit adrd=P3^7;//读控制位
sbit adwr=P3^6;//写控制位
sbit dula=P2^6;//数码管段选位
sbit wela=P2^7;//数码管位选位
uint j,k,adval;
void delay(uchar i)
{
for(j=i;j>0;j--)
for(k=125;k>0;k--);
}
void display(uchar bai_c,uchar sh_c,uchar g_c)//显示子程序
{
wela=0;dula=0;P0=0x7e;wela=1;wela=0;P0=table[bai_c];dula=1;dula=0;delay(5);//完成百位显示
wela=0;dula=0;P0=0x7e;wela=1;wela=0;P0=0x80;dula=1;dula=0;delay(5);//完成小数点位显示
wela=0;dula=0;P0=0x7d;wela=1;wela=0;P0=table[sh_c];dula=1;dula=0;delay(5);//完成十位显示
wela=0;dula=0;P0=0x7b;wela=1;wela=0;P0=table[g_c];dula=1;dula=0;delay(5);//完成个位显示
}
main()
{
uchar a,A1,A2,A2t,A3;
while(1)
	{
	adwr=0;
	_nop_();
	adwr=1;
	adrd=0;
	adval=P1*2;//由于参考电压为2.5V，所以输入的电压要倍乘2
	adrd=0;
	delay(10);
	A1=adval/100;
	A2t=adval%100;
	A2=A2t/10;
	A3=A2t%10;
	for(a=10;a>0;a--)
	display(A1,A2,A3);
	}
}


