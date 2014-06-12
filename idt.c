/**
 * idt.c
 */

#include "idt.h"
#include "string.h"

idt_entry_t idt_entries[IDT_ENTRIES];
idt_t idt;

void idt_init()
{
	memset(idt_entries, '\0', sizeof(idt_entries));
}