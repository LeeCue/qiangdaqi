#include <reg51.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
#define DATA P0 //LCD12864������       
sbit RS=P2^2; // ����\ָ�� ѡ��       
sbit RW=P2^1; // ��\д ѡ��          
sbit EN=P2^0; // ��\дʹ��       
sbit cs1=P2^4; // Ƭѡ1         
sbit cs2=P2^3; // Ƭѡ2         
/**********���������ֿ�************/
//����ȡģʱ��ѡ������Ϊ�������ʽΪ���룬ȡģ��ʽΪ����ʽ��ȡģ����Ϊ�������ִ�СΪ��x��=16x16 
uchar code Hzk[]={
0x00,0x04,0x04,0xC4,0xB4,0x8C,0x87,0x84,0xF4,0x84,0x84,0x84,0x84,0x04,0x00,0x00,
0x00,0x00,0x20,0x18,0x0E,0x04,0x20,0x40,0xFF,0x00,0x02,0x04,0x18,0x30,0x00,0x00,/*"��",0*/
0x20,0x20,0x2A,0x2A,0xAA,0x6A,0x3E,0x2B,0xAA,0xAA,0xEA,0xAA,0x2A,0x22,0x20,0x00,
0x82,0x82,0x45,0x45,0x25,0x15,0x0D,0xFF,0x04,0x0C,0x14,0x24,0x65,0xC2,0x42,0x00,/*"��",1*/
0x00,0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xF8,0x00,0x00,0x00,
0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x3F,0x44,0x44,0x44,0x44,0x4F,0x40,0x70,0x00,/*"��",0*/
0x00,0x00,0x02,0x02,0x02,0x02,0x02,0xE2,0x12,0x0A,0x06,0x02,0x00,0x80,0x00,0x00,
0x01,0x01,0x01,0x01,0x01,0x41,0x81,0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,/*"��",1*/
0x40,0x20,0xD0,0x4C,0x43,0x44,0x48,0xD8,0x30,0x10,0x00,0xFC,0x00,0x00,0xFF,0x00,
0x00,0x00,0x3F,0x40,0x40,0x42,0x44,0x43,0x78,0x00,0x00,0x07,0x20,0x40,0x3F,0x00,/*"��",2*/
0x20,0x24,0x2C,0x35,0xE6,0x34,0x2C,0x24,0x00,0xFC,0x24,0x24,0xE2,0x22,0x22,0x00,
0x21,0x11,0x4D,0x81,0x7F,0x05,0x59,0x21,0x18,0x07,0x00,0x00,0xFF,0x00,0x00,0x00,/*"��",3*/
0x00,0x04,0x04,0x04,0xFF,0x54,0x54,0x54,0x54,0x54,0xFF,0x04,0x04,0x04,0x00,0x00,
0x11,0x51,0x49,0x4D,0x4B,0x49,0x49,0x7D,0x49,0x49,0x4B,0x45,0x4D,0x59,0x09,0x00,/*"��",4*/
0x10,0x10,0x10,0xFE,0x10,0x50,0x40,0xFE,0x20,0x20,0xFF,0x10,0x10,0xF8,0x10,0x00,
0x20,0x20,0x10,0x1F,0x08,0x08,0x00,0x3F,0x40,0x40,0x4F,0x42,0x44,0x43,0x70,0x00,/*"��",5*/
};
/*״̬��飬LCD�Ƿ�æ*/
void CheckState()		
{
   uchar dat;//״̬��Ϣ���ж��Ƿ�æ��
   RS=0; // ����\ָ��ѡ��D/I��RS��="L" ����ʾ DB7��DB0 Ϊ��ʾָ������ 
   RW=1; //R/W="H" ��E="H"���ݱ�����DB7��DB0              
   do{
      DATA=0x00;
      EN=1;	//EN�½�Դ      
	_nop_(); //һ������ʱ     
	dat=DATA;
      EN=0;
      dat=0x80 & dat; //������7λΪ0ʱ�ſɲ���(�б�busy�ź�)          
      }while(!(dat==0x00));
}
 /*д���LCD��*/
SendCommandToLCD(uchar com)
{
   CheckState();//״̬��飬LCD�Ƿ�æ       
   RS=0;	 //��LCD�������RS=0дָ�RS=1д����         
   RW=0;//R/W="L" ��E="H��L"���ݱ�д�� IR �� DR 
   DATA=com;	 //com :����       
   EN=1;   
   _nop_();
   _nop_(); 
   EN=0;  //EN�½�Դ    
}
 /*����ҳ 0xb8��ҳ���׵�ַ*/
void SetLine(uchar page)	
{
  page=0xb8|page; //1011 1xxx 0<=page<=7 �趨ҳ��ַ--X 0-7,8��Ϊһҳ64/8=8����8ҳ              
  SendCommandToLCD(page);
}
 /*�趨��ʾ��ʼ�У�0xc0���е��׵�ַ*/          
void SetStartLine(uchar startline) 	   
{
  startline=0xc0|startline; //1100 0000     
  SendCommandToLCD(startline); //���ô����п�ʼ��0--63��һ���0 �п�ʼ��ʾ           
}
 /*�趨�е�ַ--Y 0-63 ��0x40���е��׵�ַ*/             
void SetColumn(uchar column)	
{
  column=column &0x3f; //column���ֵΪ64��Խ�� 0=<column<=63         
  column= 0x40|column; //01xx xxxx      
  SendCommandToLCD(column);
}
 /*������ʾ��0x3f�ǿ���ʾ��0x3e�ǹ���ʾ*/
void SetOnOff(uchar onoff)	   
{
	onoff=0x3e|onoff; //0011 111x,onoffֻ��Ϊ0����1        
	SendCommandToLCD(onoff);
}
/*д��ʾ���� */
void WriteByte(uchar dat)	
{
   CheckState();//״̬��飬LCD�Ƿ�æ       
   RS=1; //RS=0дָ�RS=1д����        
   RW=0;////R/W="L" ��E="H��L"���ݱ�д�� IR �� DR 
   DATA=dat;//dat:��ʾ����     
   EN=1; 
   _nop_();
   _nop_();
   EN=0;//EN�½�Դ
}
/*ѡ����Ļscreen: 0-ȫ��,1-����,2-����*/
void SelectScreen(uchar screen)	  
{ 						 
   switch(screen)
   { case 0: cs1=0;//ȫ����ʾ  
             _nop_(); _nop_(); _nop_(); 
             cs2=0; 
             _nop_(); _nop_(); _nop_(); 
             break; 
     case 1: cs1=0;//����ʾ��    
             _nop_(); _nop_(); _nop_(); 
             cs2=1;
             _nop_(); _nop_(); _nop_(); 
             break;
     case 2: cs1=1;//����ʾ��     
             _nop_(); _nop_(); _nop_(); 
             cs2=0;
             _nop_(); _nop_(); _nop_(); 
             break;
   }
}
 /*����screen: 0-ȫ��,1-����,2-��*/                    
void ClearScreen(uchar screen)	  
{ 	
     uchar i,j;
     SelectScreen(screen);
	 for(i=0;i<16;i++)	 //����ҳ��0-7����8ҳ      
	 {
	        SetLine(i);
			SetColumn(0);
              for(j=0;j<64;j++)	   //��������0-63����64��       
			  {
                  WriteByte(0x00); //д�����ݣ��е�ַ�Զ���1       
              }
     } 
}
/*��ʱ����*/
void	delay(uint z)		
{
	uint i,j;
	for(i=0; i<z; i++)
		for(j = 0; j < 110; j++);
}
/*��ʼ��LCD*/
void InitLCD() 	  
{ 
	CheckState();
	SelectScreen(0);
	SetOnOff(0); //����ʾ     
	SelectScreen(0);
	SetOnOff(1); //����ʾ   
	SelectScreen(0);         
	ClearScreen(0);//����   
	SetStartLine(0); //��ʼ��:0    
}
/*��ʾȫ�Ǻ���*/     
void Display(uchar ss,uchar page,uchar column,uchar number)
{
	int i;
	//ѡ��������pagrѡҳ������columnѡ�в�����numberѡ�ڼ��������             
	SelectScreen(ss);
	column=column&0x3f;
	SetLine(page);	//д�ϰ�ҳ    
	SetColumn(column); //������   
	for(i=0;i<16;i++)  //����16�е��������      
	{
	WriteByte(Hzk[i+32*number]); //i+32*number���ֵ�ǰ16���������          
	}
	SetLine(page+1);		 //д�°�ҳ    
	SetColumn(column);	   //������    
    for(i=0;i<16;i++)	  //����16�е��������      
	{
	WriteByte(Hzk[i+32*number+16]);	//i+32*number+16���ֵĺ�16���������
	}
} 
/*������*/
void main()
{  
	uint i;
   	InitLCD();//��ʼ12864      
   	ClearScreen(0);//����    
   	while(1)
   	{   
	      for(i=0;i<128;i++) //12864��128�У���ʾ��ʼ�д�0~128�л�����˿���ʵ��ѭ����ʾ
            {
            SetStartLine(i);//��ʾ��ʼ��     
	  	Display(2,0,0*16,0);//��ʾ��һ����
		Display(2,0,1*16,1);// ��ʾ�ڶ�����
		Display(2,0,2*16,2);// ��ʾ��������
      	Display(2,0,3*16,3);//  ��ʾ���ĸ���
		Display(1,0,4*16,4);//  ��ʾ�������
		Display(1,0,5*16,5);//  ��ʾ��������
      	Display(1,0,6*16,6);//  ��ʾ���߸���
            Display(1,0,7*16,7);//  ��ʾ�ڰ˸���
            SelectScreen(0);//ѡ��ȫ����ʾ
    	      delay(50); //��ʱ 
      }
}

}
