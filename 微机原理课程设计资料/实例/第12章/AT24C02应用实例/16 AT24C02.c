#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
sbit sda=P3^1;
sbit scl=P3^0;
bit flag=0;				//用户蹲渊义定时溢出标志位
uchar sec,tcnt;			//秒变量sec，定时中断计数变量tcnt
void delay()			//短延时，两个机器周期,做总线的延时用
{;;}
void delay1ms(uint m)	//长延时，做数码管显示延时用
{
	uint x,y;
	for(x=m;x>0;x--)
	for(y=110;y>0;y--);
}
void start()  			//开始信号
{		
	sda=1;
	delay();
	scl=1;
	delay();
	sda=0;
	delay(); 
	} 

void stop()   			//停止
{	
	sda=0;
	delay();    
	scl=1;
	delay();
	sda=1;
	delay();
}

void respons()  		//应答
{
	uchar i;
	scl=1;
	delay();
	while((sda==1)&&(i<250))
	i++;
	scl=0;
	delay();
}
void write_byte(uchar date)    //写数据
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
	temp=temp<<1;
	scl=0;
	delay();
	sda=CY;
	delay();
	scl=1;
	delay();
	}	
scl=0;delay();
sda=1;delay();
}
uchar read_byte()         //读数据
{

uchar i,k;
scl=0;
delay();
sda=1;
delay();
for(i=0;i<8;i++)
{
scl=1;
delay();
k=(k<<1)|sda;
scl=0;
delay();
}
return k;
}

void write_add(uchar address,uchar date)   //写地址
{
	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	write_byte(date);
	respons();
	stop();
}

uchar read_add(uchar address)          //读地址
{  uchar byte;
	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	start();
	write_byte(0xa1);
	respons();
	byte=read_byte();
	stop();
	return byte;
}
void Disp( )						//数码管显示
	{
     P2=0xfe;
	 P1=table[sec%10];
	 delay1ms(5);
     P2=0xfd;
     P1=table[sec/10%10];
     delay1ms(5);	  
     P2=0xfb;
     P1=table[sec/100];
     delay1ms(5);	
	}
void init()							//初始化
{
sda=1;
delay();
scl=1;
delay();
}
void main()
{    
	init();
	sec=0;
	TMOD=0x01;
	ET0=1;
	EA=1;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TR0=1;
	while(1)
	{
	Disp();
		if(flag==1)
		{
		flag=0;
		write_add(2,sec);
		}
	}
}

void time() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tcnt++;
	if(tcnt==20)
	{
	tcnt=0;		//tcnt每到达一次20，tcnt重新开始计时，将时间控制在1s
	sec++;
	flag=1;
	if(sec==60)//sec控制在59
	sec=0;
	}

}

