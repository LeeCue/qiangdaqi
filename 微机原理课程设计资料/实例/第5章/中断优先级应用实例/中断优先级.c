#include<reg51.h>
#define uchar unsigned char		//�궨��
void delay(uchar c)   			//��ʱ�ӳ��� Cms,��� 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
void INT_0() interrupt 0			//�ⲿ�ж�0�ӳ���
{
 EX0=0;						//�ر��ⲿ�еģ���ֹ��ִ���ٴ��ж�
 delay(20);					//��ʱ20ms��ȥ����
 EX0=1;						//���ⲿ�ж�0
 while(1)					//led����ѭ���������������ⲿ�ж�0
 {
 	P1=0xFE;delay(200);
 	P1=0xFD;delay(200);
 	P1=0xFB;delay(200);
 	P1=0xF7;delay(200);
 	P1=0xEF;delay(200);
 	P1=0xDF;delay(200);
 	P1=0xBF;delay(200);
 	P1=0x7F;delay(200);
}
}
void INT_1() interrupt 2	//�ⲿ�ж�1�ӳ���
{
 EX1=0;						//�ر��ⲿ�еģ���ֹ��ִ���ٴ��ж�
 delay(20);					//��ʱ20ms��ȥ����
 EX1=1;						//���ⲿ�ж�1
 P1=0xFF;delay(200);		//ledȫ����������˸���Σ��������ⲿ��1
 P1=0x00;delay(200);
 P1=0xFF;delay(200);
 P1=0x00;delay(200);
 P1=0xFF;delay(200);
}
void main()              
 {
 	P1=0x00;
  	EX0=1;					//���ⲿ�ж�0
	IP=0x04;				//�ⲿ�ж�1Ϊ���ȼ�
  	IT0=1;					//�����жϴ�����ʽΪ�½��ش�����ʽ
	EX1=1;
	IT1=1;
  	EA=1;					//�����ж�
  while(1);					//��ѭ��
}
