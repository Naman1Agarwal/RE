; test.asm
bits 64
default rel
section .text
global _start

_start:
    mov dword [rbp-4], eax
