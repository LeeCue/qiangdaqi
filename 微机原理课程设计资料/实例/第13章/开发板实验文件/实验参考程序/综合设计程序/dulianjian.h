//单按键识别库函数
#ifndef _dulianjian_H__
#define _dulianjian_H__

#include<reg51.h>
#include<intrins.h>
sbit BY=P3^4;//定义按键的输入端LCDEN键
void key( );
void dulianjian();
extern unsigned char t;


#endif