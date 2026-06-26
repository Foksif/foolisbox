global sys_call
section .text

align 16

sys_call:
    mov rax, rdi

    mov r10, r8
    mov r8, r9

    mov rdi, rsi
    mov rsi, rdx
    mov rdx, rcx

    syscall
    ret
