// ��ˮ��ʵ���ӳ���

#include "liushuideng.h"

unsigned char a,b,k=0xfe,j;
void delay10ms( )//��ʱ�ӳ��򣬴�Լ10ms
{
	for(a=255;a>0;a--)
	for(b=225;b>0;b--);
}
void liushuideng( )
{
	delay10ms();
	j=_crol_(k,1);
	P1=j;k=j;
}