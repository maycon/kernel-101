/**
 *  kernel.c
 */

#include "kconsole.h"

void kmain(void)
{
	char *str = ">>> Hack N' Roll - Kernel v0.0.1 <<<";
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	clear_all();

	j = 0;
	while(str[j] != '\0') {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}

	return;
}
