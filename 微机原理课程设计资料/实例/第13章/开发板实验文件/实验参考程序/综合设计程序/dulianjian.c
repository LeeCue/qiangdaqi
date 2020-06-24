//单按键识别子程序
#include "dulianjian.h"
#include "jianpan.h"

void key( )//按键判断程序
{
	if(BY==0)//判断是否有按下按键
	{
		 delays();
		 if(BY==0)
		 {
		 	  while(BY==0);//等待按键释放，如果按键未释放则一直在此等待
			  t=_crol_(t,1);
		 }
	}
}

void dulianjian()
{
	P1=t;
	key();//调用按键识别子程序
}