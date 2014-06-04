/**
 *  kmain.c
 */

#include "kconsole.h"

void kmain(void)
{
	unsigned int i;

	console_init();

	console_write_text(">>> Hack N' Roll - Kernel v0.0.1 (#1) <<<\n");
	console_write_hex(0x12); console_put_char('\n');
	console_write_hex(0x1234); console_put_char('\n');
	console_write_hex(0x123456); console_put_char('\n');
	console_write_hex(0x12345678); console_put_char('\n');
	console_write_hex(0x3456789A); console_put_char('\n');
	console_write_hex(0x56789ABC); console_put_char('\n');
	console_write_hex(0x789ABCDE); console_put_char('\n');
	console_write_hex(0x89ABCDEF); console_put_char('\n');
	console_write_hex(0xDEADBEEF); console_put_char('\n');
	console_write_hex(0xC0DEC0F3); console_put_char('\n');

	return;
}

