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

/**
 * Interrupt Service Routines (ISR)
 */
extern void isr0();   // Division by zero exception
extern void isr1();   // Debug exception
extern void isr2();   // Non maskable interrupt
extern void isr3();   // Breakpoint exception
extern void isr4();   // 'Into detected overflow'
extern void isr5();   // Out of bounds exception
extern void isr6();   // Invalid opcode exception
extern void isr7();   // No coprocessor exception
extern void isr8();   // Double fault (pushes an error code)
extern void isr9();   // Coprocessor segment overrun
extern void isr10();  // Bad TSS (pushes an error code)
extern void isr11();  // Segment not present (pushes an error code)
extern void isr12();  // Stack fault (pushes an error code)
extern void isr13();  // General protection fault (pushes an error code)
extern void isr14();  // Page fault (pushes an error code)
extern void isr15();  // Unknown interrupt exception
extern void isr16();  // Coprocessor fault
extern void isr17();  // Alignment check exception
extern void isr18();  // Machine check exception
extern void isr19();  // Reserved
extern void isr20();  // Reserved
extern void isr21();  // Reserved
extern void isr22();  // Reserved
extern void isr23();  // Reserved
extern void isr24();  // Reserved
extern void isr25();  // Reserved
extern void isr26();  // Reserved
extern void isr27();  // Reserved
extern void isr28();  // Reserved
extern void isr29();  // Reserved
extern void isr30();  // Reserved
extern void isr31();  // Reserved

#endif