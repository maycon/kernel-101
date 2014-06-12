/**
 * io.h
 */

#ifndef _IO_H_
#define _IO_H_

#include "types.h"

static inline void outb(int16 port, int8 value);

static inline int8 inb(int16 port);

static inline int16 inw(int16 port);


#endif