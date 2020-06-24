#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char		
void delay(uint);
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
//共阳数码管编码表
void main()              
{
uchar m=0;				//显示从"0"开始
	 while(1)
	 {
	  if(m==16) m=0;//如当m==16时，回到0，重新开始。
	  P1=table[m++];//循环一次，m+1.
	  delay(1000);	//延时显示数码管
	 }
}


void delay(uint k)   //延时Kms 误差 0us
{
    unsigned char a,b;
    for(;k>0;k--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}
