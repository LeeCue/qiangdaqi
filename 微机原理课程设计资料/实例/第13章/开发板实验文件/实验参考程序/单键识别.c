#include<reg51.h>
sbit BY=P3^4;//���尴���������LCDEN��
unsigned char count,temp,a,b;//����������ÿ��һ�£�count��1
void key( )//�����жϳ���
{
if(BY==0)//�ж��Ƿ��а��°���
{
count++;//����������1
	if(count==8)//����8�����¼���
	{
	count=0;//��count����
	}
}
while(BY==0);//�ȴ������ͷţ��������δ�ͷ���һֱ�ڴ˵ȴ�
}
void move()//��������������ƶ��ӳ���
{
a=temp<<count;//������Ϊһ��ѭ����λ���൱ǰ���ᵽ��_crol_()����
b=temp>>(8-count);
P1=a|b;
}
main()
{
count=0;//��ʼ����������
temp=0xfe;
P1=0xff;
P1=temp;
	while(1)
	{
	key();//���ð���ʶ���ӳ���
	move();//������λ�ӳ���
	}
}


