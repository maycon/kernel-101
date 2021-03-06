; isr_asm.s


bits 32

section .text

; ----------------------------- MACROS ----------------------------------

%macro ISR_NOERROR 1
	global isr%1

	isr%1:
		cli              ; Disable interrupts
		push 0           ; Dummy error code
		push %1          ; Interrupt number
		jmp isr_stub
%endmacro

%macro ISR_ERROR 1
	global isr%1

	isr%1:
		cli              ; Disable interrupts
		push %1          ; Interrupt number
		jmp isr_stub
%endmacro

; -------------------------------------------------------------------

extern isr_handler

isr_stub:
	pusha                  ; Save edi, esi, ebp, esp, ebx, edx, ecx, eax

	; Save current data segment
	mov ax, ds
	push eax

	; Load Kernel data segment
	mov ax, 0x10           ; Offset of data segment on gdt_t
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	call isr_handler       ; Call the handler implemented in high level

	; Reload the original data segment
	pop eax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	popa                   ; Restore edi, esi, ebp, esp, ebx, edx, ecx, eax
	add esp, 0x08          ; Remove the arguments from Stack

	sti                    ; enables interrupts
	iret                   ; returns from the ISR

ISR_NOERROR 0   ; Division by zero exception
ISR_NOERROR 1   ; Debug exception
ISR_NOERROR 2   ; Non maskable interrupt
ISR_NOERROR 3   ; Breakpoint exception
ISR_NOERROR 4   ; 'Into detected overflow'
ISR_NOERROR 5   ; Out of bounds exception
ISR_NOERROR 6   ; Invalid opcode exception
ISR_NOERROR 7   ; No coprocessor exception
ISR_ERROR 8     ; Double fault (pushes an error code)
ISR_NOERROR 9   ; Coprocessor segment overrun
ISR_ERROR 10    ; Bad TSS (pushes an error code)
ISR_ERROR 11    ; Segment not present (pushes an error code)
ISR_ERROR 12    ; Stack fault (pushes an error code)
ISR_ERROR 13    ; General protection fault (pushes an error code)
ISR_ERROR 14    ; Page fault (pushes an error code)
ISR_NOERROR 15  ; Unknown interrupt exception
ISR_NOERROR 16  ; Coprocessor fault
ISR_NOERROR 17  ; Alignment check exception
ISR_NOERROR 18  ; Machine check exception
ISR_NOERROR 19  ; Reserved
ISR_NOERROR 20  ; Reserved
ISR_NOERROR 21  ; Reserved
ISR_NOERROR 22  ; Reserved
ISR_NOERROR 23  ; Reserved
ISR_NOERROR 24  ; Reserved
ISR_NOERROR 25  ; Reserved
ISR_NOERROR 26  ; Reserved
ISR_NOERROR 27  ; Reserved
ISR_NOERROR 28  ; Reserved
ISR_NOERROR 29  ; Reserved
ISR_NOERROR 30  ; Reserved
ISR_NOERROR 31  ; Reserved

