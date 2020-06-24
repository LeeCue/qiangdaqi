#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code number[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
//��������ܱ����
uchar code address[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//�����ѡ������
uchar i,time;
uint count=0;
uint temp;
bit flag;
void delay(uint m)
{
	while(m--);
}

void main(void)
{
   EA=1;//�����ж�
   ET0=1;//����ʱ��0�ж�
   ET1=1;//����ʱ��1�ж�
   TMOD=0x16;//����T1Ϊ��ʱ��������ʽΪ��T0Ϊ��������������ʽΪ2
   TH0=0xff;
   TL0=0xff;//��������0����ֵ������ֵΪ1����ÿ�����ж��źţ�T0�ж�һ��
   TR0=1;//����������0
   TH1=(65536-50000)/256;
   TL1=(65536-50000)%256;//����ʱ��1����ֵ��ʱ��Ϊ50ms��12MHz��
   TR1=1;//������ʱ��1.
while(1)//��ѭ��
  {
   if(flag==1)//��ʱ������־
    {
	 temp=count;//���������0�ļ���ֵ
	 for(i=0;i<5;i++)//������ֵ����λȡ��������P1�����
	  {
	   P2=address[i];
	   P1=number[temp%10];
	   temp=temp/10;
	   delay(500);//����ܶ�̬��ʾ��ע����ʱʱ��
	  }	
	}
   }
}

void time0(void) interrupt 1//�������ж��ӳ���
{
 count++;//ÿ�ж�һ��count��1
}		  

void time1(void) interrupt 3//��ʱ���ж��ӳ���
{
  TH1=(65536-50000)/256;
  TL1=(65536-50000)%256;//���¸���ʱ������ֵ
  time++;//�ܶ�ʱʱ����20x50ms=1s
  if(time==20)
  {
   EA=0;//�ر����ж�
   flag=1;//��ʱ������־��1
  }
} 
