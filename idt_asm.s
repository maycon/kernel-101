; idt.asm

bits 32

section .text


global set_idt

set_idt:
	mov eax, [esp + 0x04]  ; idt_t passed as argument
	lidt [eax]             ; Load
	ret

