#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char//�궨��
uchar code table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//���������"0-9"�����
uchar m=0;
void delay(uchar c)   //��ʱ�ӳ��� Cms,��� 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void INT_0() interrupt 0//�ⲿ�ж�0����
{
 EX0=0;			//�ر��ⲿ�еģ���ֹ��ִ���ٴ��ж�
 delay(20);	//��ʱ500ms��ȥ����
 EX0=1;			//���ж�
 if(m==10) m=0;	//��m=10ʱ�ص�0
 else P1=table[m++];//ѭ�����"0-9"
}
void INT_1() interrupt 2//�ⲿ�ж�0����
{
 EX1=0;			//�ر��ⲿ�еģ���ֹ��ִ���ٴ��ж�
 delay(20);	//��ʱ500ms��ȥ����
 EX1=1;			//���ж�
 if(m==0) m=10;	//��m=0ʱ�ص�10
 else P1=table[--m];//ѭ�����"0-9"
}
void main()              
 {
 	P1=0x00;
  	EA=1;		//�����ж�
  	EX0=1;	//���ⲿ�ж�0
  	IT0=1;	//�����жϴ�����ʽΪ�½��ش�����ʽ
	EX1=1;
	IT1=1;
  while(1);	//��ѭ��
}

