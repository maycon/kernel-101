/**
 *  kmain.c
 */

#include "kconsole.h"

void kmain(void)
{
	unsigned int i;

	console_init();

	for (i = 0; i < 3; i++){
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#1) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#2) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#3) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#4) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#5) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#6) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#7) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#8) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#9) <<<\n");
		console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#10) <<<\n");
	}

	return;
}

