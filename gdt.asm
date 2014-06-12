; gdt.asm

bits 32

section .text

global set_gdt
global reload_segments

set_gdt:
	mov eax, [esp + 0x04]  ; gdt_t passed as argument
	lgdt [eax]             ; Load
	ret

reload_segments:
	mov ax, 0x10           ; Offset of data segment on gdt_t
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	jmp 0x08:.return       ; Far jump. Set CS to 0x08

.return
	ret
