
#include<reg51.h>
#include<absacc.h>
#define add XBYTE[0x0000]
//7CFFH 			;A��
//7DFFH 			;B��
//7FFFH 			;�����ֵ�ַ
main()
{
unsigned char PORT_DATA;
unsigned char xdata  *pt;
pt=&add;	
*(pt+0x7fff)=0x82;//д������
while(1)
{
PORT_DATA=*(pt+0x7dff);
*(pt+0x7cff)=PORT_DATA;
}
}
