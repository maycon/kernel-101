/**
 *  kmain.c
 */

#include "kconsole.h"
#include "gdt.h"

void kmain(void)
{
	gdt_init();
	console_init();

	console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#1) <<<\n");
	
	return;
}

