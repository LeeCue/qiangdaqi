#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit LED=P1^0;//ȡP1.0����Ϊ������������ܵ�����ź�
bit flag;//��־λ����־�Ƿ����ж�
uchar count=0;
void delay(uchar c)   //��ʱ���� Cms,��� 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void main(void)
{
	TMOD=0x01;//���ö�ʱ��0Ϊ��ʱģʽ1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;//����ʱ��0��ֵ��Ϊ50ms
	EA=1;   //�����ж�
	ET0=1;  //����ʱ/������0	 
    TR0=1;  //������ʱ/������0
	while(1)
     {
     if(flag==1)
     {LED=0;
	 delay(100);//��ʱ100ms
	 LED=1;
	 flag=0;
	 }
     }
}

void time0(void) interrupt 1  //ʹ����ܼ�һ
{
  TH0=(65536-50000)/256;
  TL0=(65536-50000)%256;
  count++;
  if(count>=20)
  {
    count=0;
    flag=1;
  }
}
