; ============================================================================
; NovaTech Cobalt OS - v0.01 (April 1971 Spec)
; Module: boot.asm (Multiboot Handshake & Kernel Entry)
; ============================================================================

MBALIGN  equ  1 << 0            ; Align modules on page boundaries
MEMINFO  equ  1 << 1            ; Provide memory map
FLAGS    equ  MBALIGN | MEMINFO ; Multiboot flag field
MAGIC    equ  0x1BADB002        ; Magic number letting bootloader find header
CHECKSUM equ -(MAGIC + FLAGS)   ; Checksum to prove multiboot compatibility

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
    resb 16384                  ; Reserve 16 KiB for the kernel stack
stack_top:

section .text
global _start:function (_start.end - _start)
_start:
    mov esp, stack_top          ; Set up the stack pointer
    extern kernel_main
    call kernel_main            ; Jump into the C kernel code

    cli
.hang:  hlt                     ; Infinite loop if kernel returns
    jmp .hang
_start.end:
