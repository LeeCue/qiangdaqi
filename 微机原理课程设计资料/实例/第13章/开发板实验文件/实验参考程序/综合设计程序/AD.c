#include "AD.h"
#include "jianpan.h"
#include "yejin.h"
uint adval;
uchar q,B1,B2,B2t,B3;
void dsp1(uchar bai_c,uchar sh_c,uchar g_c)//��ʾ�ӳ���
{
	wela=0;dula=0;P0=0x7e;wela=1;wela=0;P0=TABLE[bai_c];dula=1;dula=0;delay(5);//��ɰ�λ��ʾ
	wela=0;dula=0;P0=0x7e;wela=1;wela=0;P0=0x80;dula=1;dula=0;delay(5);//���С����λ��ʾ
	wela=0;dula=0;P0=0x7d;wela=1;wela=0;P0=TABLE[sh_c];dula=1;dula=0;delay(5);//���ʮλ��ʾ
	wela=0;dula=0;P0=0x7b;wela=1;wela=0;P0=TABLE[g_c];dula=1;dula=0;delay(5);//��ɸ�λ��ʾ
}
void AD()
{
	adwr=0;
	_nop_();
	adwr=1;
	adrd=0;
	adval=P1*2;//���ڲο���ѹΪ2.5V����������ĵ�ѹҪ����2
	adrd=0;
	delay(10);
	B1=adval/100;
	B2t=adval%100;
	B2=B2t/10;
	B3=B2t%10;
	for(q=10;q>0;q--)
	dsp1(B1,B2,B3);

}


