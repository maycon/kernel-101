kmain:
	gcc -m32 -c kmain.c -o kmain.o  -ggdb

kcall:
	nasm -f elf32 kcall.asm -o kcall.o

kconsole:
	gcc -m32 -c kconsole.c -o kconsole.o -ggdb

io:
	gcc -m32 -c io.c -o io.o -ggdb

gdt:
	nasm -f elf32 gdt.asm -o gdt_flush.o
	gcc -m32 -c gdt.c -o gdt.o  -ggdb


all: kcall kmain kconsole io gdt
	ld -m elf_i386 -T link.ld -o kernel kcall.o kmain.o  kconsole.o gdt.o gdt_flush.o

clean:
	rm -rf *.o kernel

run: all
	qemu-system-i386 -kernel kernel