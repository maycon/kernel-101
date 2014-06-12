/**
 * idt.h
 */

#ifndef _IDT_H_
#define _IDT_H_

#include "types.h"

#define IDT_FLAG_P
#define IDT_FLAG_DPL0 0
#define IDT_FLAG_DPL1 1
#define IDT_FLAG_DPL2 2
#define IDT_FLAG_DPL3 3
#define IDT_FLAG_
#define IDT_FLAG_


#define IDT_ENTRIES 256

#define IDTR(base,segment,flags)            \
{                                           \
	.base_low = base & 0xFFFF,              \
	.segment = segment,                     \
	.zero = 0,                              \
	.flags = flags,                         \
	.base_higt = (base >> 16) & 0xFFFF      \
}

struct idt_entry_struct
{
	uint16 base_low;
	uint16 segment;
	uint8 zero;
	uint8 flags;
	uint16 base_higt;
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;


struct idt_struct
{
	uint16 limit;
	uint32 base;
} __attribute__((packed));

typedef struct idt_struct idt_t;


void idt_init();

#endif