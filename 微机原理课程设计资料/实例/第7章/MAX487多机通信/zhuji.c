
#include<reg51.h>
#include<absacc.h>
#include<intrins.h>

unsigned char cort=0;

sbit P3_5=P3^5;

/*********************************

按键扫描子程序

*********************************/

key_serial() interrupt 0 using 1
{
	 
	 ++cort;
}

/*********************************

发送子程序

*********************************/

void master(void)
{
		if(cort==1)
		{	
			SBUF=0x01;
			while(TI!=1);TI=0;
			P3_5=0;
			SM2=0;

			while(RI!=1);RI=0;
			P2=SBUF;
			SM2=1;
			P3_5=1;
		}
		
		if(cort==2)
		{
		 	SBUF=0x02;
			while(TI!=1);TI=0;
			SM2=0;
			P3_5=0;

			while(RI!=1);RI=0;
			P2=SBUF;
			SM2=1;
			P3_5=1;
		}
							 
		if(cort==3)cort=1;
		SM2=1;
		
}

/***************主程序****************/

void main(void)
{
	
	P2=0xff;
	TMOD=0x20;
	TL1=0xfd;
	TH1=0xfd;
	PCON=0x00;
	TR1=1;
	SCON=0xf8;
	EA=1;
	EX0=1;
	IT0=1;
	P3_5=1;
	while(1)
	{
	 	master();			//发送
	}
}






