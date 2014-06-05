kmain:
	gcc -m32 -c kmain.c -o kmain.o

kcall:
	nasm -f elf32 kcall.asm -o kcall.o

kconsole:
	gcc -m32 -c kconsole.c -o kconsole.o

io:
	gcc -m32 -c io.c -o io.o

all: kcall kmain kconsole io
	ld -m elf_i386 -T link.ld -o kernel kcall.o kmain.o  kconsole.o

clean:
	rm -rf *.o kernel

run: all
	qemu-system-i386 -kernel kernel