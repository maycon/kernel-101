/**
 *  kmain.c
 */

#include "kconsole.h"

void kmain(void)
{
	char *str = ">>> Hack N' Roll - Kernel v0.0.1 <<<";

	console_init();
	console_write_text(str);

	return;
}
