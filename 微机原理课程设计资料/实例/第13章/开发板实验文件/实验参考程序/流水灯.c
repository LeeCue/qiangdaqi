#include<reg51.h>
#include<intrins.h>
/*����Ҫ�õ��������_crol_(k,1)�������ú�������˼�ǰ��ַ�����kѭ������1λ��
*/
unsigned char a,b,k,j;
void delay10ms( )//��ʱ�ӳ��򣬴�Լ10ms
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
