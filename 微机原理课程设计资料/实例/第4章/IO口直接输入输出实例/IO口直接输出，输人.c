#include<reg51.h>
#define uint unsigned int
void delay()    		// ��ʱ�ӳ��� 
{  uint i,j;
   for(i=10;i>0;i--)
   for(j=1000;j>0;j--);
}
void main()  	 		//������ 
{
  	while(1)
   	{
    P2=0xff;  			// P2��ȫ�����ߵ�ƽ
     	if(P2!=0x0f)  	//����1������ 
		{
 		P2=P2<<4;		//��λ���㣬�����ƶ�4λ
		delay();		//��������ĸ�����״̬�͸��ĸ�LED
		}
	}
}

