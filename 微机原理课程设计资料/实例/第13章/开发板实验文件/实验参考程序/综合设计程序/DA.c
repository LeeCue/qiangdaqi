
#include "DA.h"
#include "jianpan.h"
#include "yejin.h" //为了用它的dela()函数
unsigned char w;

void DA()
{
	wela=0;
	dula=0;
	csda=0;	
	dawr=0;

	P0=w;
	delay(5);
	w++;

}