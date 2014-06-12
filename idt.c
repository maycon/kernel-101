/**
 * idt.c
 */

#include <idt.h>
#include <string.h>

idt_entry_t idt_entries[IDT_ENTRIES];
idt_t idt;

void idt_init()
{
	idt.limit = sizeof(idt_entries) - 1;
	idt.base = (uint32)&idt_entries;

	memset(idt_entries, '\0', sizeof(idt_entries));

	IDTR(idt_entries, 0, (uint32)isr0, 0x08, IDT_FLAG_TYPE_INT32);
}