#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
//��������ܱ����
uchar code address[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//�����ѡ������
void delay(uint);//ʲô��ʱ�ӳ���
void main()              
{
 uchar m=0;
 while(1)
 {
   if(m==8) m=0;//��mѭ����8��������0.
   P2=address[m];//P2����������ѡ���źţ�ѡ�ж�Ӧ�������
   P1=table[m++];//P1�����Ҫ���������
   delay(500);  //��ʱ��ʾ
 }
}
void delay(uint m)//��ʱ�ӳ���Լ500����������
{
	while(m--);
}
