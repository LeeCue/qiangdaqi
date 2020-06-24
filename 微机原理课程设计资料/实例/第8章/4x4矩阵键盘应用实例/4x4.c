#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
uchar code KEY_TABLE[]={ 0xee,0xde,0xbe,0x7e,
						 0xed,0xdd,0xbd,0x7d,
						 0xeb,0xdb,0xbb,0x7b,
						 0xe7,0xd7,0xb7,0x77};//键盘表
uchar code TABLE[]={0x3F,0x06,0x5B,0x4F,
			   		0x66,0x6D,0x7D,0x07,
			   		0x7F,0x6F,0x77,0x7c,
			   		0x39,0x5e,0x79,0x71};//共阴极数码管编码表
void delayl()//长延时，作点亮数码管用
{uint n=50000;while(n--);}
void delays()//短延时，作消振用
{uint n=10000;while(n--);}
main()
{
uchar temp,key,num,i;
	while(1)
	{
	P3=0xf0;//置行为0，列为1，读列值。
		if(P3!=0xf0)//判断有，无键盘按下
		{delays();//消振
			if(P3!=0xf0)//如果if的值为真，这时可以确定有键盘按下
			{
			temp=P3;//存储列读入的值
			P3=0x0f;//置列为0，行为1，读行值。
			key=temp|P3;//将行，列值综合，赋给key。
				for(i=0;i<16;i++)
				if(key==KEY_TABLE[i])//读键盘表，确定读入的按键值
				{num=i;break;}
			P2=TABLE[num];//点亮数码管，显示按键值。
			delayl();
			}

		}

	}

}
