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
	idt.base = (uint32)&idt_entries;

	memset(idt_entries, '\0', sizeof(idt_entries));

	IDTR(idt_entries, 0, (uint32)isr0, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 1, (uint32)isr1, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 2, (uint32)isr2, 0x08, IDT_FLAG_TYPE_INT32);
	IDTR(idt_entries, 3, (uint32)isr3, 0x08, IDT_FLAG_TYPE_INT32);

	set_idt((uint32)&idt);
}