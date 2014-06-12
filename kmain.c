/**
 *  kmain.c
 */

#include <kconsole.h>
#include <gdt.h>
#include <idt.h>

void kmain(void)
{
	gdt_init();
	//idt_init();
	console_init();

	console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#1) <<<\n");
	asm volatile ("int $0x03");
	
	return;
}

