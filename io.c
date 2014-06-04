/**
 * io.c
 */

#include "io.h"

void outb(int16 port, int8 value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}


int8 inb(int16 port)
{
   int8 ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));

   return ret;
}


int16 inw(int16 port)
{
	int16 ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));

	return ret;
}
