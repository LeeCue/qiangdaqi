#include<reg51.h>
#define uchar unsigned char
sbit  com=P3^0;   	//位定义P3.0为输入和输出的控制的公共位    
sbit  wr=P3^6;   	// 位定义P3.6为输出控制位     
sbit  rd=P3^7;   	//位定义P3.7为输入控制位  
/*********************************延时子程序**********************************/
void delay(void)		
{
  uchar i,j;
  for(i=30;i>0;i--)
  for(j=30;j>0;j--);
}
/**********************************主程序*************************************/
void main()  		 
{ 
    while(1)
  {
   uchar temp;  //中间变量
   P0=0xff;     //先拉高P0口即关闭LED灯 
   com=0;
   rd=0;       	//开启74LS244单片机输入数据 
   temp=P0;    	//把输入的数据暂时赋给中间变量
   rd=1;        //关闭74LS244
   wr=1;       	//开启74LS373
   P0=temp;    	//通过74LS373单片机输出数据
	wr=0;		//负跳变锁存74LS373的数据
   delay(); 
   }
}

		
