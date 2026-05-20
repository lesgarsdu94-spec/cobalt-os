; ============================================================================
; Module: boot.asm (Multiboot Handshake & Kernel Entry)
; ============================================================================

MBALIGN  equ  1 << 0
MEMINFO  equ  1 << 1
FLAGS    equ  MBALIGN | MEMINFO
MAGIC    equ  0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
global _start:function (_start.end - _start)
_start:
    ; 1. Initialize Stack Pointer
    mov esp, stack_top

    ; 2. Call Monolithic Kernel Entry Point
    extern kernel_main
    call kernel_main

    ; 3. Fallback Safeguard
    cli
.hang:
    hlt
    jmp .hang
_start.end:
