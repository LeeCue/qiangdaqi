#include<reg51.h>
unsigned char index=0;//步进索引
int n=0,n0=211;//设置周期、档次位
unsigned char flag=0,step=0;//设置方向、停止键
main()
{
P3=0xff;
EA=1;
EX0=1;EX1=1;
ET0=1;
IT0=1;IT1=1;
TMOD=0x01;
TR0=1;
TH0=-1000/256;
TL0=-1000%256;//每1ms中断一次
while(1)
{
if(P0==0xfe){n0=70;P2=1;}//1档
if(P0==0xfd){n0=90;P2=2;}//2档
if(P0==0xfb){n0=110;P2=3;}//3档
if(P0==0xf7){n0=150;P2=4;}//4档
}
}

void int0() interrupt 0//停止键
{
step=step+1;
if(step>=2)step=0;
}

void int1() interrupt 2//方向键
{
flag++;
if(flag==2)flag=0;
}

void time() interrupt 1
{
TH0=-1000/256;
TL0=-1000%256;

if(step==1)///停止控制键
{
if(n>=n0)//周期:n0x1ms
{		
		if(flag==0)//正转
		{switch(index)
		{
		case 0:P1=0x03;break;
		case 1:P1=0x06;break;
		case 2:P1=0x0c;break;
		case 3:P1=0x09;break;
		}
		index++;
		if(index==4)index=0;//转一圈index回到0，下一次重新开始
		n=0;
		}
			if(flag==1) //反转
			{
			switch(index)
			{
			case 0:P1=0x09;break;
			case 1:P1=0x0c;break;
			case 2:P1=0x06;break;
			case 3:P1=0x03;break;
			}index++;
			if(index==4)index=0;//转一圈index回到0，下一次重新开始
			n=0;
			}
		else n=0;
	}
n++;//每次中断 n+1	
	
}

else n=0;//停止


}
