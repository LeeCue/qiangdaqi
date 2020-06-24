
#include<reg51.h>
#include<absacc.h>
#define add XBYTE[0x0000]
//7CFFH 			;A口
//7DFFH 			;B口
//7FFFH 			;控制字地址
main()
{
unsigned char PORT_DATA;
unsigned char xdata  *pt;
pt=&add;	
*(pt+0x7fff)=0x82;//写控制字
while(1)
{
PORT_DATA=*(pt+0x7dff);
*(pt+0x7cff)=PORT_DATA;
}
}
