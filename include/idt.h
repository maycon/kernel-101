/**
 * idt.h
 */

#ifndef _IDT_H_
#define _IDT_H_

#include "types.h"

#define IDT_FLAG_P (1 << 7)
#define IDT_FLAG_DPL0 (0 << 5)
#define IDT_FLAG_DPL1 (1 << 5)
#define IDT_FLAG_DPL2 (2 << 5)
#define IDT_FLAG_DPL3 (3 << 5)
#define IDT_FLAG_STR_SEG (1 << 5)
#define IDT_FLAG_TYPE_TASK32 0x5
#define IDT_FLAG_TYPE_INT16 0x6
#define IDT_FLAG_TYPE_TRAP12 0x7
#define IDT_FLAG_TYPE_INT32 0xE
#define IDT_FLAG_TYPE_TRAP32 0xF


#define IDT_ENTRIES 256


#define IDTR(idt,idx,base,seg,flgs)                 \
	idt[idx].base_low = base & 0xFFFF;              \
	idt[idx].segment = seg;                         \
	idt[idx].zero = 0;                              \
	idt[idx].flags = IDT_FLAG_P | flgs;             \
	idt[idx].base_higt = (base >> 16) & 0xFFFF;     \

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

extern void set_idt(uint32);

void idt_init();


#endif