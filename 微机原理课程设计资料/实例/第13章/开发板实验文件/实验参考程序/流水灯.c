#include<reg51.h>
#include<intrins.h>
/*后面要用到它里面的_crol_(k,1)函数，该函数的意思是把字符变量k循环左移1位。
*/
unsigned char a,b,k,j;
void delay10ms( )//延时子程序，大约10ms
{
for(a=255;a>0;a--)
for(b=225;b>0;b--);
}
void main( )
{
k=0xfe;
while(1)
{
delay10ms();
j=_crol_(k,1);
P1=j;k=j;
}
}
