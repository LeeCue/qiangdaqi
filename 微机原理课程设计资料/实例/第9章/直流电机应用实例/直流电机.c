#include<reg51.h>
unsigned char speed=0;//定义速度的电压变量
main()
{
EA=1;
EX0=1;
IT0=1;//开中断和设置外部中断触发方式
while(1)
{
P2=speed;
}
}
void int0() interrupt 0//外部中断函数
{
if(speed==255);
else speed=speed+5;
}
