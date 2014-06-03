/**
 *  link.ld
 */

/* File type format */
OUTPUT_FORMAT(elf32-i386)

/* Entry-point */
ENTRY(start)

/* Sections */
SECTIONS
{
	. = 0x100000;
	.text : { *(.text) }
	.data : { *(.data) }
	.bss  : { *(.bss)  }
}
