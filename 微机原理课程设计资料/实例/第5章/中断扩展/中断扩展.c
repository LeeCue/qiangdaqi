#include<reg51.h>
main()
{
EA=1;
EX0=1;
}
void INT_0() interrupt 0
{
switch(P2)
{
case 0xfe: P1=0xfe;break;	//����1
case 0xfd: P1=0xfd;break;	//����2
case 0xfb: P1=0xfb;			//����3
}
}
