#include <reg51.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
#define DATA P0 //LCD12864数据线       
sbit RS=P2^2; // 数据\指令 选择       
sbit RW=P2^1; // 读\写 选择          
sbit EN=P2^0; // 读\写使能       
sbit cs1=P2^4; // 片选1         
sbit cs2=P2^3; // 片选2         
/**********定义中文字库************/
//字体取模时的选项设置为：点阵格式为阴码，取模方式为列行式，取模走向为逆向，文字大小为宽x高=16x16 
uchar code Hzk[]={
0x00,0x04,0x04,0xC4,0xB4,0x8C,0x87,0x84,0xF4,0x84,0x84,0x84,0x84,0x04,0x00,0x00,
0x00,0x00,0x20,0x18,0x0E,0x04,0x20,0x40,0xFF,0x00,0x02,0x04,0x18,0x30,0x00,0x00,/*"东",0*/
0x20,0x20,0x2A,0x2A,0xAA,0x6A,0x3E,0x2B,0xAA,0xAA,0xEA,0xAA,0x2A,0x22,0x20,0x00,
0x82,0x82,0x45,0x45,0x25,0x15,0x0D,0xFF,0x04,0x0C,0x14,0x24,0x65,0xC2,0x42,0x00,/*"秦",1*/
0x00,0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xF8,0x00,0x00,0x00,
0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x3F,0x44,0x44,0x44,0x44,0x4F,0x40,0x70,0x00,/*"电",0*/
0x00,0x00,0x02,0x02,0x02,0x02,0x02,0xE2,0x12,0x0A,0x06,0x02,0x00,0x80,0x00,0x00,
0x01,0x01,0x01,0x01,0x01,0x41,0x81,0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,/*"子",1*/
0x40,0x20,0xD0,0x4C,0x43,0x44,0x48,0xD8,0x30,0x10,0x00,0xFC,0x00,0x00,0xFF,0x00,
0x00,0x00,0x3F,0x40,0x40,0x42,0x44,0x43,0x78,0x00,0x00,0x07,0x20,0x40,0x3F,0x00,/*"创",2*/
0x20,0x24,0x2C,0x35,0xE6,0x34,0x2C,0x24,0x00,0xFC,0x24,0x24,0xE2,0x22,0x22,0x00,
0x21,0x11,0x4D,0x81,0x7F,0x05,0x59,0x21,0x18,0x07,0x00,0x00,0xFF,0x00,0x00,0x00,/*"新",3*/
0x00,0x04,0x04,0x04,0xFF,0x54,0x54,0x54,0x54,0x54,0xFF,0x04,0x04,0x04,0x00,0x00,
0x11,0x51,0x49,0x4D,0x4B,0x49,0x49,0x7D,0x49,0x49,0x4B,0x45,0x4D,0x59,0x09,0x00,/*"基",4*/
0x10,0x10,0x10,0xFE,0x10,0x50,0x40,0xFE,0x20,0x20,0xFF,0x10,0x10,0xF8,0x10,0x00,
0x20,0x20,0x10,0x1F,0x08,0x08,0x00,0x3F,0x40,0x40,0x4F,0x42,0x44,0x43,0x70,0x00,/*"地",5*/
};
/*状态检查，LCD是否忙*/
void CheckState()		
{
   uchar dat;//状态信息（判断是否忙）
   RS=0; // 数据\指令选择，D/I（RS）="L" ，表示 DB7∽DB0 为显示指令数据 
   RW=1; //R/W="H" ，E="H"数据被读到DB7∽DB0              
   do{
      DATA=0x00;
      EN=1;	//EN下降源      
	_nop_(); //一个短延时     
	dat=DATA;
      EN=0;
      dat=0x80 & dat; //仅当第7位为0时才可操作(判别busy信号)          
      }while(!(dat==0x00));
}
 /*写命令到LCD中*/
SendCommandToLCD(uchar com)
{
   CheckState();//状态检查，LCD是否忙       
   RS=0;	 //向LCD发送命令。RS=0写指令，RS=1写数据         
   RW=0;//R/W="L" ，E="H→L"数据被写到 IR 或 DR 
   DATA=com;	 //com :命令       
   EN=1;   
   _nop_();
   _nop_(); 
   EN=0;  //EN下降源    
}
 /*设置页 0xb8是页的首地址*/
void SetLine(uchar page)	
{
  page=0xb8|page; //1011 1xxx 0<=page<=7 设定页地址--X 0-7,8行为一页64/8=8，共8页              
  SendCommandToLCD(page);
}
 /*设定显示开始行，0xc0是行的首地址*/          
void SetStartLine(uchar startline) 	   
{
  startline=0xc0|startline; //1100 0000     
  SendCommandToLCD(startline); //设置从哪行开始：0--63，一般从0 行开始显示           
}
 /*设定列地址--Y 0-63 ，0x40是列的首地址*/             
void SetColumn(uchar column)	
{
  column=column &0x3f; //column最大值为64，越出 0=<column<=63         
  column= 0x40|column; //01xx xxxx      
  SendCommandToLCD(column);
}
 /*开关显示，0x3f是开显示，0x3e是关显示*/
void SetOnOff(uchar onoff)	   
{
	onoff=0x3e|onoff; //0011 111x,onoff只能为0或者1        
	SendCommandToLCD(onoff);
}
/*写显示数据 */
void WriteByte(uchar dat)	
{
   CheckState();//状态检查，LCD是否忙       
   RS=1; //RS=0写指令，RS=1写数据        
   RW=0;////R/W="L" ，E="H→L"数据被写到 IR 或 DR 
   DATA=dat;//dat:显示数据     
   EN=1; 
   _nop_();
   _nop_();
   EN=0;//EN下降源
}
/*选择屏幕screen: 0-全屏,1-左屏,2-右屏*/
void SelectScreen(uchar screen)	  
{ 						 
   switch(screen)
   { case 0: cs1=0;//全屏显示  
             _nop_(); _nop_(); _nop_(); 
             cs2=0; 
             _nop_(); _nop_(); _nop_(); 
             break; 
     case 1: cs1=0;//左显示屏    
             _nop_(); _nop_(); _nop_(); 
             cs2=1;
             _nop_(); _nop_(); _nop_(); 
             break;
     case 2: cs1=1;//右显示屏     
             _nop_(); _nop_(); _nop_(); 
             cs2=0;
             _nop_(); _nop_(); _nop_(); 
             break;
   }
}
 /*清屏screen: 0-全屏,1-左屏,2-右*/                    
void ClearScreen(uchar screen)	  
{ 	
     uchar i,j;
     SelectScreen(screen);
	 for(i=0;i<16;i++)	 //控制页数0-7，共8页      
	 {
	        SetLine(i);
			SetColumn(0);
              for(j=0;j<64;j++)	   //控制列数0-63，共64列       
			  {
                  WriteByte(0x00); //写点内容，列地址自动加1       
              }
     } 
}
/*延时程序*/
void	delay(uint z)		
{
	uint i,j;
	for(i=0; i<z; i++)
		for(j = 0; j < 110; j++);
}
/*初始化LCD*/
void InitLCD() 	  
{ 
	CheckState();
	SelectScreen(0);
	SetOnOff(0); //关显示     
	SelectScreen(0);
	SetOnOff(1); //开显示   
	SelectScreen(0);         
	ClearScreen(0);//清屏   
	SetStartLine(0); //开始行:0    
}
/*显示全角汉字*/     
void Display(uchar ss,uchar page,uchar column,uchar number)
{
	int i;
	//选屏参数，pagr选页参数，column选列参数，number选第几汉字输出             
	SelectScreen(ss);
	column=column&0x3f;
	SetLine(page);	//写上半页    
	SetColumn(column); //控制列   
	for(i=0;i<16;i++)  //控制16列的数据输出      
	{
	WriteByte(Hzk[i+32*number]); //i+32*number汉字的前16个数据输出          
	}
	SetLine(page+1);		 //写下半页    
	SetColumn(column);	   //控制列    
    for(i=0;i<16;i++)	  //控制16列的数据输出      
	{
	WriteByte(Hzk[i+32*number+16]);	//i+32*number+16汉字的后16个数据输出
	}
} 
/*主函数*/
void main()
{  
	uint i;
   	InitLCD();//初始12864      
   	ClearScreen(0);//清屏    
   	while(1)
   	{   
	      for(i=0;i<128;i++) //12864有128列，显示开始行从0~128切换，因此可以实现循环显示
            {
            SetStartLine(i);//显示开始行     
	  	Display(2,0,0*16,0);//显示第一个字
		Display(2,0,1*16,1);// 显示第二个字
		Display(2,0,2*16,2);// 显示第三个字
      	Display(2,0,3*16,3);//  显示第四个字
		Display(1,0,4*16,4);//  显示第五个字
		Display(1,0,5*16,5);//  显示第六个字
      	Display(1,0,6*16,6);//  显示第七个字
            Display(1,0,7*16,7);//  显示第八个字
            SelectScreen(0);//选择全屏显示
    	      delay(50); //延时 
      }
}

}
