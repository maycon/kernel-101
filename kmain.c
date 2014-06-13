/**
 *  kmain.c
 */

#include <kconsole.h>
#include <gdt.h>
#include <idt.h>

void kmain(void)
{
	console_init();
	gdt_init();
	idt_init();

	console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#1) <<<\n");

	asm volatile ("int $0x03");
	asm volatile ("int $0x04");
	
	return;
}

