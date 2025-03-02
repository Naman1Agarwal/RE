global _start
section .text
_start:
    xor rax,rax
    xor rdi,rdi
    xor rsi,rsi
    xor rdx,rdx
    xor r14,r14
    xor r15,r15
    inc al
    inc dil
    mov r14,0x00000a21646c726f
    mov r15,0x57202c6f6c6c6548
    push r14
    push r15
    mov rsi,rsp
    mov dl,0xf
    syscall
    xor rax,rax
    xor rdi,rdi
    mov al,0x3c
    syscall
