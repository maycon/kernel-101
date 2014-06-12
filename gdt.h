/**
 * gdt.h
 */

#ifndef _GDT_H_
#define _GDT_H_

#include "types.h"

// GDT entry flags
#define GDT_GR_4KB (1 << 6)
#define GDT_SZ_32B (1 << 7)

// GDT entry access
#define GDT_RW (1 << 1)
#define GDT_DC_DOWN (1 << 2)
#define GDT_EXEC (1 << 3)
#define GDT_RING0 (0 << 6)
#define GDT_RING1 (1 << 6)
#define GDT_RING2 (2 << 6)
#define GDT_RING3 (3 << 6)


#define GDTR(base,limit,access,flags)                                \
{                                                                    \
	.limit_low = limit & 0xFFFF,                                     \
	.base_low = base & 0xFFFF,                                       \
	.base_middle = (base >> 16) & 0xFF,                              \
	.access_byte = (access | 0x90),                                  \
	.base_high = (base >> 24) & 0xFF,                                \
	.granularity = flags | ((limit >> 16) & 0x0F)                    \
}


struct gdt_entry_struct
{
	uint16 limit_low;
	uint16 base_low;
	uint8 base_middle;
	uint8 access_byte;
	uint8 granularity;
	uint8 base_high;
} __attribute__((packed));

struct gdt_struct
{
	uint16 limit;
	uint32 base;
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;
typedef struct gdt_struct gdt_t;

extern void set_gdt(uint32);
extern void reload_segments();

void gdt_init();


#endif