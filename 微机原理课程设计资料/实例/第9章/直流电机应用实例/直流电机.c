#include<reg51.h>
unsigned char speed=0;//�����ٶȵĵ�ѹ����
main()
{
EA=1;
EX0=1;
IT0=1;//���жϺ������ⲿ�жϴ�����ʽ
while(1)
{
P2=speed;
}
}
void int0() interrupt 0//�ⲿ�жϺ���
{
if(speed==255);
else speed=speed+5;
}
