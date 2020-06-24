#ifndef _jianpan_H__
#define _jianpan_H__

#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;

void delayl();
void delays();
void jianpan();
uchar code KEY_TABLE[];
uchar code TABLE[];
#endif