/**
 * io.h
 */

#ifndef _IO_H_
#define _IO_H_

#include "common.h"

void outb(int16 port, int8 value);

int8 inb(int16 port);

int16 inw(int16 port);


#endif _IO_H_