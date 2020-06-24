#include<reg51.h>
sbit BY=P3^4;//定义按键的输入端LCDEN键
unsigned char count,temp,a,b;//按键计数，每按一下，count加1
void key( )//按键判断程序
{
if(BY==0)//判断是否有按下按键
{
count++;//按键计数加1
	if(count==8)//计数8次重新计数
	{
	count=0;//将count清零
	}
}
while(BY==0);//等待按键释放，如果按键未释放则一直在此等待
}
void move()//发光二极管向下移动子程序
{
a=temp<<count;//这三句为一个循环移位，相当前面提到的_crol_()函数
b=temp>>(8-count);
P1=a|b;
}
main()
{
count=0;//初始化参数设置
temp=0xfe;
P1=0xff;
P1=temp;
	while(1)
	{
	key();//调用按键识别子程序
	move();//调用移位子程序
	}
}


