#include<reg51.h>
#include<absacc.h>
#define ramaddress XBYTE[0x0000]
unsigned char sum;
main()
{
unsigned char xdata *pt;
unsigned char i,sumtemp;
pt=&ramaddress;

for(i=0;i<20;i++)//½á¹ûÎª20=14H
{*(pt+i)=1;
}
sum=0;
for(i=0;i<20;i++)
{
sumtemp=*(pt+i);
sum=sum+sumtemp;
}
P1=sum;

}
