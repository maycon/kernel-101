/**
 * idt.c
 */

#include <idt.h>
#include <isr.h>
#include <string.h>

idt_entry_t idt_entries[IDT_ENTRIES];
idt_t idt;

void idt_init()
{
	idt.limit = sizeof(idt_entries) - 1;
	idt.base = (uint32)idt_entries;

	memset(idt_entries, '\0', sizeof(idt_entries));

	IDTR(idt_entries, 0, (uint32)isr0, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 1, (uint32)isr1, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 2, (uint32)isr2, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 3, (uint32)isr3, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 4, (uint32)isr4, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 5, (uint32)isr5, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 6, (uint32)isr6, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 7, (uint32)isr7, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 8, (uint32)isr8, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 9, (uint32)isr9, 0x08, IDT_FLAG_TYPE_INT32);
	
	IDTR(idt_entries, 10, (uint32)isr10, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 11, (uint32)isr11, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 12, (uint32)isr12, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 13, (uint32)isr13, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 14, (uint32)isr14, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 15, (uint32)isr15, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 16, (uint32)isr16, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 17, (uint32)isr17, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 18, (uint32)isr18, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 19, (uint32)isr19, 0x08, IDT_FLAG_TYPE_INT32);

	IDTR(idt_entries, 20, (uint32)isr20, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 21, (uint32)isr21, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 22, (uint32)isr22, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 23, (uint32)isr23, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 24, (uint32)isr24, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 25, (uint32)isr25, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 26, (uint32)isr26, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 27, (uint32)isr27, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 28, (uint32)isr28, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 29, (uint32)isr29, 0x08, IDT_FLAG_TYPE_INT32);

	IDTR(idt_entries, 30, (uint32)isr30, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 31, (uint32)isr31, 0x08, IDT_FLAG_TYPE_INT32);


	set_idt((uint32)&idt);
}