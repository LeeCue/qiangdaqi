//main.c ---������--------

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
	P3=0xf0;							//����Ϊ0����Ϊ1������ֵ��
	if(P3!=0xf0)					//�ж��У��޼��̰���
	{
		delays();						//����
		if(P3!=0xf0)				//���if�Ļ�Ϊ�棬��ʱ����ȷ���м��̰���
		{
			temp=P3;					// �����ж����ֵ
			P3=0x0f;
			key=temp|P3;				//���У���ֵ�ۺϣ�����key��
			while(P3!=0x0f);					//����Ϊ0����Ϊ1������ֵ��
			en=1;

			for(i=0;i<16;i++)
			{
				if(key==KEY_TABLE[i])//����ֵ��ȷ������İ���ֵ
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
void t0(void) interrupt 1 using 0  //�жϴ����ӳ��� 
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

