/**
 * gdt.c
 */

#include <gdt.h>

gdt_entry_t gdt_entries[] = {
	// Dummy segment
	GDTR(0, 0, 0, 0),

	// Kernel space (ring-0)
	GDTR(0, 0xFFFFFFFF, GDT_RING0 | GDT_EXEC | GDT_RW, GDT_GR_4KB | GDT_SZ_32B),
	GDTR(0, 0xFFFFFFFF, GDT_RING0 | GDT_RW, GDT_GR_4KB | GDT_SZ_32B),

	// User space (ring-3)
	GDTR(0, 0xFFFFFFFF,	GDT_RING3 | GDT_EXEC | GDT_RW, GDT_GR_4KB | GDT_SZ_32B),
	GDTR(0, 0xFFFFFFFF,	GDT_RING3 | GDT_RW, GDT_GR_4KB | GDT_SZ_32B),
};

gdt_t gdt;

void gdt_init()
{
	gdt.limit = sizeof(gdt_entries) - 1;
	gdt.base = (uint32)&gdt_entries;

	set_gdt((uint32)&gdt);
	reload_segments();
}