/**
 * isr.h
 */

#ifndef _ISR_H_
#define _ISR_H_

#include <types.h>

struct registers_struct
{
	// Data segment
	uint32 ds;

	// Pushed by pusha
	uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;

	// Arguments
	uint32 int_no, err_code;    

	// Pushed by CLI
	uint32 eip, cs, eflags, useresp, ss; 
};
typedef struct registers_struct registers_t;



void isr_handler(registers_t regs);



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