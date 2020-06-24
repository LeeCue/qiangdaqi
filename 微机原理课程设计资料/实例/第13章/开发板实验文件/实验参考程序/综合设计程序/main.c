//main.c ---主程序--------

#include "liushuideng.h"
#include "yejin.h"
#include "dianzhen.h"
#include "jianpan.h"
#include "dulianjian.h"
#include "shumaguan.h"
#include "AD.h"
#include "DA.h"
unsigned char cnta;

uchar keynum,en;
unsigned char t=0xfe;
unsigned char code tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
unsigned char code graph[]={0x30,0x48,0x44,0x22,0x44,0x48,0x30,0x00};
uchar keydet()
{
	uchar temp,key,num,i;
	P3=0xf0;							//置行为0，列为1，读列值。
	if(P3!=0xf0)					//判断有，无键盘按下
	{
		delays();						//消振
		if(P3!=0xf0)				//如果if的还为真，这时可以确定有键盘按下
		{
			temp=P3;					// 储存列读入的值
			P3=0x0f;
			key=temp|P3;				//将行，列值综合，赋给key。
			while(P3!=0x0f);					//置列为0，行为1，读行值。
			en=1;

			for(i=0;i<16;i++)
			{
				if(key==KEY_TABLE[i])//读键值表，确定读入的按键值
				{num=i;break;}
			}
		}
	}
	P3=0xff;
	return num;
}
void initt0()
{
	TMOD=0x01;
	TH0=(65536-4000)/256;
	TL0=(65536-4000)%256;
	ET0=1;
	EA=1;
}
void main()
{
	uchar m;
	initt0();
	init();	
	while(1)
	{
		m=keydet();
		TR0=0;
		if(en==1)
		{
			en=0;
			keynum=m;
		}
		switch(keynum)
		{
			case 1:{liushuideng();break;}	
			case 2:{dulianjian();break;}
			case 3:{shumaguan();break;}
			case 4:{AD();break;}
			case 5:{DA();break;}
			case 8:{dianzhen();break;}		
			case 9:{display();break;}
			default	:		  break		;
		}	
	}
}
void t0(void) interrupt 1 using 0  //中断处理子程序 
{
	TH0=(65536-4000)/256;
	TL0=(65536-4000)%256;
	P1=tab[cnta];
	P0=graph[cnta];
	cnta++;
	if(cnta==8)
	{
		cnta=0;
	}
}

