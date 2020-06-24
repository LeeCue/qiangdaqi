#ifndef _AD_H__
#define _AD_H__
#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char

sbit adrd=P3^7;//读控制位
sbit adwr=P3^6;//写控制位
void dsp1(uchar bai_c,uchar sh_c,uchar g_c);
void AD();


#endif