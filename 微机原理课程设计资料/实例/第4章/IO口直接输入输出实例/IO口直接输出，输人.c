#include<reg51.h>
#define uint unsigned int
void delay()    		// 延时子程序 
{  uint i,j;
   for(i=10;i>0;i--)
   for(j=1000;j>0;j--);
}
void main()  	 		//主函数 
{
  	while(1)
   	{
    P2=0xff;  			// P2口全部赋高电平
     	if(P2!=0x0f)  	//开关1被按下 
		{
 		P2=P2<<4;		//移位运算，向左移动4位
		delay();		//将读入的四个开关状态送给四个LED
		}
	}
}

