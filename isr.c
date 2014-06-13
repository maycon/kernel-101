/**
 * isr.c
 */

#include <isr.h>
#include <kconsole.h>

void isr_handler(registers_t regs)
{
	console_write_text("G0t a interrupt request: ");
	console_write_dec(regs.int_no);
	console_put_char('\n');
}