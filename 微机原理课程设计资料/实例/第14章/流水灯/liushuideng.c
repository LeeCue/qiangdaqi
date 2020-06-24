#include <REGX52.H>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int

void Delay1ms(uint count)
{
      uint  i,j;
	for(i=0;i<count;i++)
	for(j=0;j<120;j++);
}

main()
{     uchar i;
      uchar temp=0xfe;
	while(1)
	{     
            P1=temp;
            for(i=0;i<8;i++)
            {
               temp=_crol_(temp,1);
			   	Delay1ms(1000);
               P1=temp;
            }
		Delay1ms(1000);
	}
}
