#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
uchar code address[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
sbit DQ=P3^0;   
sbit dot=P1^0;
uchar i,temp1,temp2;
void delay(uint m)
{
	while(m--);
}

Init(void) 
{
	 uchar i=0;
	 DQ=1;         
	 delay(8);  
	 DQ=0;         
	 delay(80); 
	 DQ=1;          
	 delay(14);
	 i=DQ;      
	 delay(20);
}
 
uchar read_byte()
{
	uchar byte=0;
	for (i=0;i<8;i++)  //先传低位
	 {
	  DQ=0; 
	  byte>>=1;
	  DQ=1; 
	  if(DQ)
	  byte|=0x80;
	  delay(4);
	 }
 	return(byte);
}

write_byte(uchar byte)    
{
 for (i=0;i<8;i++)         //先传低位
 {
  
  DQ=0;
  byte>>=1;
  DQ=CY;  
  delay(5);
  DQ=1;  
 }
}

read_temp()
{	
	Init();
	write_byte(0xcc);       // Skip ROM
	write_byte(0x44);       // 启动温度转换
	delay(10);

	Init();
	write_byte(0xcc);       //Skip ROM
	write_byte(0xbe);       //读取温度寄存器

	temp1=read_byte();	    //低位
	temp2=read_byte();	    //高位
}

main()
{
	bit flag;
	uint temp;
	while(1)
	{
	 read_temp();
	 temp=temp1&0x0f; 
	 if(temp2>127)
	 {
	  flag=1;
	  temp1=~temp1;
	  temp2=~temp2;	
	  temp=temp1&0x0f; 
	  temp+=0x01;
	 } 	   
   	 temp=temp*625;	 	 

	 temp1=temp1&0xf0; //取整数部分

	 temp1=temp1/16;
	 temp2=temp2*16;
	 temp1+=temp2;
	 if(flag)
	 temp1+=0x01;
	             		   
     for(i=0;i<4;i++)	   //显示小数部分
	 {	  
	  P2=address[i];
	  P1=table[temp%10];
	  delay(750);	  
	  temp/=10;
	 }
	 				  								    
	 P2=0xef;	  	   	   //显示整数部分
	 P1=table[temp1%10];
	 dot=1;
	 delay(750);

     if(temp1/100||temp1/10)  //高位去0
	 {
	  P2=0xdf;
	  P1=table[temp1/10%10];
	  delay(750);
	 }

	 if(temp1/100)	   //高位去0
	 {
	  P2=0xbf;
	  P1=table[temp1/100%10];
   	  delay(800);
	 }

	 if(flag)		 //加负号
	 {
	  P2=0x7f;
	  P1=0x02;
	  delay(750);
	  flag=0;
	 }	 	
	}
}