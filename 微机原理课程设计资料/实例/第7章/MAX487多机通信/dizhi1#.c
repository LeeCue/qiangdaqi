#include<reg51.h>
#include<absacc.h>
#include<intrins.h>

unsigned char serial_receiver;

sbit P3_5=P3^5;

/****************************************

串行口中断子程序

****************************************/

void serial (void) interrupt 4 using 1
{
 		ES=0;
		RI=0;
		
		if(SBUF==0x01)
		{
	 			P3_5=1;
				SM2=0;
				P1=0x10;
				SBUF=0x10;
				while(TI!=1);TI=0;
		}
	else P1=0;
		SM2=1;
		ES=1;
		P3_5=0;
}

/*****************主程序******************/

void main(void)
{
	 
	  P1=0x00;
	  TMOD=0x20;
	  TL1=0xfd;
	  TH1=0xfd;
	  PCON=0x00;
	  TR1=1;
	  SCON=0xf0;
	  EA=1;
	  ES=1;
	  P3_5=0;
	  while(1)
	  {
	   		_nop_();
			
	  }

}













