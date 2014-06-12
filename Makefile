PROG = kernel

CC = gcc
NASM = nasm
LD = ld

INC_DIR = ./include

CFLAGS = -I$(INC_DIR) -m32 -c -fno-builtin -ggdb
LFLAGS = -m elf_i386 -T link.ld 
NASMFLAGS = -f elf32 

SRC_C = gdt.c idt.c io.c kconsole.c kmain.c string.c
SRC_ASM = gdt_asm.s idt_asm.s kcall.s

OBJS = $(SRC_C:.c=.o) $(SRC_ASM:.s=.o)

default: all

all: $(PROG)

$(PROG): $(OBJS)
	@echo [LD] $@
	@$(LD) $(LFLAGS) $(OBJS) -o $(PROG) 

clean:
	@$(RM) *.o kernel
	@echo Done.

qemu: all
	qemu-system-i386 -s -kernel kernel

%.o: %.c
	@echo [CC] $< \-\> $@
	@$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	@echo [ASM] $< \-\> $@
	@$(NASM) $(NASMFLAGS) -o $@ $<