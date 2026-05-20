; ============================================================================
; NovaTech Cobalt OS - v0.01 (April 5, 1971 Spec)
; Lifecycle: End of Support April 12, 1971
; Module: boot.asm (Multiboot Handshake & Kernel Entry)
; ============================================================================

; --- Multiboot Constants ---
MBALIGN  equ  1 << 0            ; Align loaded modules on page boundaries
MEMINFO  equ  1 << 1            ; Request memory map from bootloader
FLAGS    equ  MBALIGN | MEMINFO ; Combine multiboot flags
MAGIC    equ  0x1BADB002        ; Magic number letting bootloader find header
CHECKSUM equ -(MAGIC + FLAGS)   ; Checksum to prove valid multiboot specification

; --- Multiboot Section ---
section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

; --- Stack Allocation Section ---
section .bss
align 16
stack_bottom:
    resb 16384                  ; Reserve 16 KiB for the kernel execution stack
stack_top:

; --- Code Execution Section ---
section .text
global _start:function (_start.end - _start)
_start:
    ; 1. Initialize Stack Pointer
    mov esp, stack_top          ; Set stack pointer to point to top of reserved memory

    ; 2. Call Monolithic Kernel Entry Point
    extern kernel_main
    call kernel_main            ; Jump execution straight into your C kernel

    ; 3. Fallback Safeguard (If kernel returns)
    cli                         ; Clear system interrupts
.hang:  
    hlt                         ; Halt the CPU CPU
    jmp .hang                   ; Infinite loop catch
_start.end:
