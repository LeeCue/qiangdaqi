#include "shumaguan.h"
#include "jianpan.h"
#include "yejin.h"
unsigned int time,A1,A2,second;

void dsp(uchar sh_c,uchar g_c)//��ʾ�ӳ���
{
wela=0;dula=0;P0=0xfe;wela=1;wela=0;P0=TABLE[sh_c];dula=1;dula=0;delay(5);//���ʮλ��ʾ
wela=0;dula=0;P0=0xfd;wela=1;wela=0;P0=TABLE[g_c];dula=1;dula=0;delay(5);//��ɸ�λ��ʾ
}
void shumaguan()
{	
	if(second==60)second=0;
	A1=second/10;
	A2=second%10;
	for(time=50;time>0;time--)dsp(A1,A2);
	second++;
	
}