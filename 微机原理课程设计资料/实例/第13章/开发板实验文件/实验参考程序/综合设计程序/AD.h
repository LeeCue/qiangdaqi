#ifndef _AD_H__
#define _AD_H__
#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char

sbit adrd=P3^7;//������λ
sbit adwr=P3^6;//д����λ
void dsp1(uchar bai_c,uchar sh_c,uchar g_c);
void AD();


#endif