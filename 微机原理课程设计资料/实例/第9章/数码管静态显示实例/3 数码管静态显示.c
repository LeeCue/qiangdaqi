#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
void delay(uint);
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
//��������ܱ����
void main()              
{
uchar m=0;				//��ʾ��"0"��ʼ
	 while(1)
	 {
	  if(m==16) m=0;//�統m==16ʱ���ص�0�����¿�ʼ��
	  P1=table[m++];//ѭ��һ�Σ�m+1.
	  delay(1000);	//��ʱ��ʾ�����
	 }
}


void delay(uint k)   //��ʱKms ��� 0us
{
    unsigned char a,b;
    for(;k>0;k--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
