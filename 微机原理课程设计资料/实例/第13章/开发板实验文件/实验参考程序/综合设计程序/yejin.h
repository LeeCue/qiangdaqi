#ifndef __yejin_H__
#define __yejin_H__

#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

sbit lcden=P3^4;
sbit lcdrs=P3^5;

void delay(uint z);
void write_com(uchar com);
void write_data(uchar date);
void init();
void display();

#endif