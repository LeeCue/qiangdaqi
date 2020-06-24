#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar code table1[]="QIANG-DA-QI";
uchar code table2[]="1-Lee 2-Clearlove7 3-Iboy 4-Meiko 5-Ray 6-Sount 7-Langxi 8-MLXG 9-Karsa 10-Xiaohu 11-Uzi 12-Ming 13-Jacklove 14-Baolan 15-Rookie ";
uchar code table3[]="                                            ";
void delay(uint x);
uint key_scan();
void display_num(uint i);
void display_time(uint j);
void display_led(uint j);
void lcd_display(uchar i);
void lcd_yiwei();
void init();
void init_lcd();
void start_keyscan();
void reset_keyscan();
void pause_keyscan();
void setting_keyscan();
void write_com(uchar com);
void write_data(uchar dat);
void led_in();
void led_in1();
void led_in2();
void led_in3();
void led_in4();
void led_in5();
void led_in6();
void led_in7();
void led_in8();
void led_in9();
void led_in10();
void led_in11();
void led_in12();
void led_in13();
void led_in14();
void led_in15();
void led_in16();
void led_in17();
void led_in18();
void led_in19();
void led_in20();
void led_in21();
void led_in22();
void led_in23();
void led_in24();
uchar shi,ge;
uchar flag,i,j;
uint num=20,cnt;
sbit K1=P3^0;
sbit K2=P3^1;
sbit K3=P3^2;
sbit K4=P3^3;
sbit rs=P2^6;
sbit rw=P2^5;
sbit lcden=P2^7;
sbit A0=P2^2;
sbit A1=P2^3;
sbit A2=P2^4;
sbit ser=P3^4;
sbit rck=P3^5; //¥Ê¥¢ºƒ¥Ê∆˜ ±÷” ‰»Î
sbit srck=P3^6;//“∆Œªºƒ¥Ê∆˜ ±÷” ‰»Î

void main()
{	
	uchar k=0;
	init();
	init_lcd();
	for(i=0;i<11;i++)
	{		
		write_data(table1[i]);
		delay(10);
	}
	write_com(0x80+0x40);
	while(1)
	{			
		start_keyscan();
		pause_keyscan();
		reset_keyscan();
		setting_keyscan();
		display_time(num);	
		if(num<=9)
		{
			 P0=0xff;
			 display_led(num);
			 led_in24();
		}	
		if(flag==1)
		{
			i=0;
			display_num(i);
			i=key_scan();
			if(i!=0)
			{
				display_num(i);
				delay(300);
				lcd_display(i);
				k++;
				delay(10);
			}
		}
		if(k==3)
		{
			flag=0;
			TR0=0;
			lcd_yiwei();
			k=0;;
		}		
	}	
}

void init()
{					    
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=0;
	led_in24();
}

void init_lcd()
{
	A0=1;
	A1=1;
	A2=1;
	write_com(0x38);
	write_com(0x08);
	write_com(0x01);
	write_com(0x06);
	write_com(0x0c);	
}

void write_com(uchar com)
{
	A0=1;
	A1=1;
	A2=1;
	rs=0;
	rw=0;
	lcden=0;
	P0=com;
	lcden=1;
	delay(5);
	lcden=0;	
}

void write_data(uchar dat)
{
	rs=1;
	rw=0;
	lcden=0;
	P0=dat;
	lcden=1;
	delay(5);
	lcden=0;	
}

void lcd_display(uchar i)
{
	switch(i)
	{
		case(0):
		{
			write_com(0x80+0x40);
			for(j=0;j<40;j++)
			{
				write_data(table3[j]);
				delay(10);	
			}
			break;	
		}
		case(1):
		{
			for(j=0;j<6;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(2):
		{
			for(j=6;j<19;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(3):
		{
			for(j=19;j<26;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(4):
		{
			for(j=26;j<34;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(5):
		{
			for(j=34;j<40;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(6):
		{
			for(j=40;j<48;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(7):
		{
			for(j=48;j<57;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(8):
		{
			for(j=57;j<64;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(9):
		{
			for(j=64;j<72;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(10):
		{
			for(j=72;j<82;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(11):
		{
			for(j=82;j<89;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(12):
		{
			for(j=89;j<97;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(13):
		{
			for(j=97;j<109;j++)
			{
				write_data(table2[j]);
				delay(10);	
			}
			break;
		}
		case(14):
		{
			for(j=109;j<119;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
		case(15):
		{
			for(j=119;j<129;j++)
			{
				write_data(table2[j]);
				delay(10);
			}
			break;
		}
	}	
}

void lcd_yiwei()
{
	uchar a;
	i=key_scan();
	if(i>0&&i<16)
	{
		delay(2000); 
		for(a=0;a<=20;a++)
		{
			write_com(0x18);
			delay(300);
		}
		a=0;
		delay(300);
		for(a=0;a<=20;a++)
		{
			write_com(0x1c);
			delay(300);
		}
	}
}

void start_keyscan()
{
	if(K1==0)
	{
		delay(10);
		if(K1==0)
		{
			flag=1;
			TR0=1;
		}
	}
}

void pause_keyscan()
{
	if(K2==0)
	{
		delay(10);
		if(K2==0)
		{
			flag=0;
			TR0=0;	
		}
	}
}

void reset_keyscan()
{
	if(K3==0)
	{
		delay(10);
		if(K3==0)
		{
			TR0=0;
			flag=0;
			num=20;
			i=0;
			display_time(num);
			lcd_display(0);
			write_com(0x80+0x40);
			led_in24();
		}
	}
}

void setting_keyscan()
{
	uchar set_shi;
	uchar i;
	if(K4==0)
	{
		delay(10);
		if(K4==0)
		{
			while(!K4)
			{
				i=key_scan();
				if(i>=0&&i<10)
				{
					set_shi=i*10;
					num=set_shi;
					display_time(num);
				}
				if(i==14)
				{
					delay(200);
					if(i==14)	num--;
				}
				if(i==15)
				{
					delay(200);
					if(i==15)	num++;
				}
				if(num==100)	num=0;
				display_time(num);		
			}
		}
	}
}

void delay(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)
		for(j=120;j>0;j--);
}

void display_num(uint i)
{	
	if(i>=0 && i<10)
	{
		A0=0;
		A1=1;
		A2=0;
		P0=table[i];
		delay(5);
	}	
	if(i>=10)
	{
		shi=i/10;
		ge=i%10;
		A0=1;
		A1=1;
		A2=0;
		P0=table[shi];
		delay(300);
		A0=0;
		A1=1;
		A2=0;
		P0=table[ge];
		delay(5); 
	}
}

void display_time(uint j)
{	
	if(j>=0 && j<10)
	{
		A0=0;
		A1=0;
		A2=0;
		P0=table[j];
		delay(5);
		A0=1;
		A1=0;
		A2=0;
		P0=table[0];
		delay(5);
	}	
	if(j>=10)
	{
		shi=j/10;
		ge=j%10;
		A0=0;
		A1=0;
		A2=0;
		P0=table[ge];
		delay(5);
		A0=1;
		A1=0;
		A2=0;
		P0=table[shi];
		delay(5);
	}
}

uint key_scan()
{
	uchar n,keynum;
	P1=0x7f;
	n=P1;
	n&=0x0f;
	if(n!=0x0f)
	{
		delay(10);
		P1=0x7f;
		n=P1;
		n&=0x0f;
		if(n!=0x0f)
		{
			switch(n)
			{
				case(0x07):keynum=0;break;
				case(0x0b):keynum=1;break;
				case(0x0d):keynum=2;break;
				case(0x0e):keynum=3;break;	
			}
		}
	}
	P1=0xbf;
	n=P1;
	n&=0x0f;
	if(n!=0x0f)
	{
		delay(10);
		P1=0xbf;
		n=P1;
		n&=0x0f;
		if(n!=0x0f)
		{
			switch(n)
			{
				case(0x07):keynum=4;break;
				case(0x0b):keynum=5;break;
				case(0x0d):keynum=6;break;
				case(0x0e):keynum=7;break;	
			}
		}
	}
	P1=0xdf;
	n=P1;
	n&=0x0f;
	if(n!=0x0f)
	{
		delay(10);
		P1=0xdf;
		n=P1;
		n&=0x0f;
		if(n!=0x0f)
		{
			switch(n)
			{
				case(0x07):keynum=8;break;
				case(0x0b):keynum=9;break;
				case(0x0d):keynum=10;break;
				case(0x0e):keynum=11;break;	
			}
		}
	}
	P1=0xef;
	n=P1;
	n&=0x0f;
	if(n!=0x0f)
	{
		delay(10);
		P1=0xef;
		n=P1;
		n&=0x0f;
		if(n!=0x0f)
		{
			switch(n)
			{
				case(0x07):keynum=12;break;
				case(0x0b):keynum=13;break;
				case(0x0d):keynum=14;break;
				case(0x0e):keynum=15;break;	
			}
		}
	}
	return keynum;
}

void display_led(uint num)
{
	A0=1;
	A1=1;
	A2=1;
	P0=0xff;
	switch(num)
	{
		case(0):
		{
			led_in();
			delay(1);
			led_in1();
			delay(1);
			led_in2();
			delay(1);
			led_in3();
			delay(1);
			break;
		}
		case(1):
		{
			led_in4();
			delay(1);
			break;	
		}
		case(2):
		{
			led_in5();
			delay(1);
			led_in6();
			delay(1);
			led_in7();
			delay(1);
			led_in8();
			delay(1);
			break;
		}
		case(3):
		{
			led_in9();
			delay(1);
			led_in10();
			delay(1);
			led_in11();
			delay(1);
			led_in12();
			delay(1);
			break;	
		}
		case(4):
		{
			led_in13();
			delay(1);
			led_in14();
			delay(1);
			led_in15();
			delay(1);
			led_in16();
			delay(1);
			break;	
		}
		case(5):
		{
			led_in17();
			delay(1);
			led_in18();
			delay(1);
			led_in19();
			delay(1);
			led_in20();
			delay(1);
			break;	
		}
		case(6):
		{
			led_in();
			delay(1);
			led_in18();
			delay(1);
			led_in19();
			delay(1);
			led_in20();
			delay(1);
			break;	
		}
		case(7):
		{
			led_in21();
			delay(1);
			led_in22();
			delay(1);
			led_in23();
			delay(1);
			led_in3();
			delay(1);
			break;	
		}
		case(8):
		{
			led_in();
			delay(1);
			led_in18();
			delay(1);
			led_in19();
			delay(1);
			led_in3();
			delay(1);
			break;	
		}
		case(9):
		{
			led_in17();
			delay(1);
			led_in18();
			delay(1);
			led_in19();
			delay(1);
			led_in3();
			delay(1);
			break;	
		}
	}
}

void led_in23()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<7;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in22()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<7;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in21()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<7;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in20()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	for(i=0;i<5;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xfb;	
}

void led_in19()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in18()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in17()
{
	uchar i;
	for(i=0;i<4;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in16()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xfb;	
}

void led_in15()
{
	uchar i;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<4;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in14()
{
	uchar i;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<4;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in13()
{
	uchar i;
	for(i=0;i<4;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	for(i=0;i<4;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in12()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xfb;	
}

void led_in11()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in10()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in9()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in8()
{
	uchar i;
	for(i=0;i<4;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xfb;	
}

void led_in7()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in6()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<3;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in5()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<2;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	for(i=0;i<5;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in4()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xdf;	
}

void led_in1()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<6;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xef;	
}

void led_in2()
{
	uchar i;
	ser=1;
	srck=1;
	srck=0;
	for(i=0;i<6;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	ser=1;
	srck=1;
	srck=0;
	rck=1;
	rck=0;
	P0=0xf7;	
}

void led_in3()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=1;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
	P0=0xfb;	
}

void led_in24()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ser=0;
		srck=1;
		srck=0;
	}
	rck=1;
	rck=0;
}
void timer_smg() interrupt 1
{
	uchar cnt;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	cnt++;	
	if(flag==1 && cnt==20)
	{
	 	num--;
		cnt=0;
		if(num==0)
		{
			TR0=0;
			flag=0;
		}
	}
}