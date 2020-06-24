#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
sbit sda=P3^1;
sbit scl=P3^0;
bit flag=0;				//�û���Ԩ�嶨ʱ�����־λ
uchar sec,tcnt;			//�����sec����ʱ�жϼ�������tcnt
void delay()			//����ʱ��������������,�����ߵ���ʱ��
{;;}
void delay1ms(uint m)	//����ʱ�����������ʾ��ʱ��
{
	uint x,y;
	for(x=m;x>0;x--)
	for(y=110;y>0;y--);
}
void start()  			//��ʼ�ź�
{		
	sda=1;
	delay();
	scl=1;
	delay();
	sda=0;
	delay(); 
	} 

void stop()   			//ֹͣ
{	
	sda=0;
	delay();    
	scl=1;
	delay();
	sda=1;
	delay();
}

void respons()  		//Ӧ��
{
	uchar i;
	scl=1;
	delay();
	while((sda==1)&&(i<250))
	i++;
	scl=0;
	delay();
}
void write_byte(uchar date)    //д����
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
uchar read_byte()         //������
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

void write_add(uchar address,uchar date)   //д��ַ
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

uchar read_add(uchar address)          //����ַ
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
void Disp( )						//�������ʾ
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
void init()							//��ʼ��
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
	tcnt=0;		//tcntÿ����һ��20��tcnt���¿�ʼ��ʱ����ʱ�������1s
	sec++;
	flag=1;
	if(sec==60)//sec������59
	sec=0;
	}

}

