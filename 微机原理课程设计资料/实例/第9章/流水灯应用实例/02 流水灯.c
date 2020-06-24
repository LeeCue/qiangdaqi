#include<reg51.h>
#define uint unsigned int
void delay(uint k)
{
	uint i,j;
	for(i=7;i<k;i++)
		for(j=0;j<124;j++);
}
main()
{

	 while(1)//死循环
	 {
		P1=0xfe;delay(500);//点亮第一个发光二极管
		P1=0xfd;delay(500);//点亮第二个发光二极管
		P1=0xfb;delay(500);//点亮第三个发光二极管
		P1=0xf7;delay(500);//点亮第四个发光二极管
		P1=0xef;delay(500);//点亮第五个发光二极管
		P1=0xdf;delay(500);//点亮第六个发光二极管
		P1=0xbf;delay(500);//点亮第七个发光二极管
		P1=0x7f;delay(500);//点亮第八个发光二极管
	 }
}
