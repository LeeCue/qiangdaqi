#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int 
uchar code dis[]={0xc0,0xf9}; //�����������ʾ����0~1
void delay(void)
{
  uchar i,j;
  for(i=100;i>0;i--)
  for(j=500;j>0;j--);

}
void main()
{  uchar i;
  while(1)
  {
   P1=dis[0];//��ʾ0
   delay();
   P1=dis[1];//��ʾ1
   delay();
   
  }
}