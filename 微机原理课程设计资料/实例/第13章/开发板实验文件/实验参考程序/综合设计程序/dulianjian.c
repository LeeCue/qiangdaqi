//������ʶ���ӳ���
#include "dulianjian.h"
#include "jianpan.h"

void key( )//�����жϳ���
{
	if(BY==0)//�ж��Ƿ��а��°���
	{
		 delays();
		 if(BY==0)
		 {
		 	  while(BY==0);//�ȴ������ͷţ��������δ�ͷ���һֱ�ڴ˵ȴ�
			  t=_crol_(t,1);
		 }
	}
}

void dulianjian()
{
	P1=t;
	key();//���ð���ʶ���ӳ���
}