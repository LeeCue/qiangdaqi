#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code write_address[]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c}; 
uchar code read_address[]={0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
uchar date[]={0x01,0x01,0x01,0x09,0x05,0x02,0x12};
uchar date1[]={0x01,0x01,0x01,0x09,0x05,0x02,0x12};
sbit RST=P3^0;     
sbit SCL=P3^1;		
sbit SDA=P3^2;		
sbit  ACC7 = ACC^7;
uchar temp,byte;

void delay(uint m)
{
	while(m--);
}

void write_byte(uchar byte)  
{
 uchar m;
 for(m=0;m<8;m++)     	//先传低位
  { 
	byte>>=1;
    SCL=0;
    SDA=CY;     	
    SCL=1;
  }
}   

uchar read_byte(void)	            //读一个字节
{
 	uchar m;
	for(m=0;m<8;m++)      //先传低位
	{
	 ACC=ACC>>1;	   
	 ACC7=SDA;
	 SCL=1;
	 SCL=0;	
	}
	return (ACC);			//返回
}

void write_1302(uchar address,uchar date)   //发送地址和数据  
{
 	RST=0;
 	SCL=0;
 	RST=1;	               //启动
 	write_byte(address);	
 	write_byte(date);	
 	RST=0;  	        	//恢复
}

read_data(uchar address)		    //读取日历
{
 uchar temp;
 RST=0;
 SCL=0;
 RST=1;       	        
 write_byte(address|0x01);
 temp=read_byte();
 SCL=1;
 RST=0;	   
 return(temp); 
}

void read_time()
{
 uchar m,temp3,temp1,temp2;
 temp3=0x80;
 for(m=0;m<7;m++) 
 {
  temp1=read_data(temp3);
  temp2=temp1; 
  date[m]=(temp1>>1)&0x0f;     //取1，2，3，4位
  date1[m]=(temp2>>5)&0x07;    //取5，6，7位
  temp3=temp3+0x02;
 }	 
}
   
void set_RTC(void)		    //设定日历
{
	uchar m;
 	write_1302(0x8E,0x00);	
 	for(m=0;m<7;m++)		//7次写入年月日时分秒星期
 	{
	 write_1302(write_address[m],date[m]);
	}
	write_1302(0x8E,0x80);
}

void main(void)             //入口函数
{
	RST=0;
	set_RTC();
	while(1)
	{
     read_time();	

	 P2=0xfe;
	 P1=table[date[0]%10];
	 delay(500);

	 P2=0xfd;
	 P1=table[date1[0]%10];
	 delay(500);

	 P2=0xfb;
	 P1=0x02;
	 delay(500);

	 P2=0xf7;
	 P1=table[date[1]%10];
	 delay(500);

	 P2=0xef;
	 P1=table[date1[1]%10];
	 delay(500);

	 P2=0xdf;
	 P1=0x02;
	 delay(500);

	 P2=0xbf;
	 P1=table[date[2]%10];
	 delay(500);

	 P2=0x7f;
	 P1=table[date1[2]%10];
	 delay(500);	
   }
}
