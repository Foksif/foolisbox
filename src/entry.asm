bits 64
global _start

extern core_main 

section .text
_start:
    mov rdi, [rsp]
    lea rsi, [rsp + 8]

    call core_main

    mov rdi, rax
    mov rax, 60
    syscall
