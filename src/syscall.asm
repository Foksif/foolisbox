bits 64
global sys_call

section .text

; long sys_call(num, a1, a2, a3, a4, a5)

sys_call:
    ; rdi = syscall number
    ; rsi = a1
    ; rdx = a2
    ; rcx = a3
    ; r8  = a4
    ; r9  = a5

    mov rax, rdi        ; syscall number

    mov rdi, rsi        ; arg1
    mov rsi, rdx        ; arg2
    mov rdx, rcx        ; arg3
    mov r10, r8         ; arg4
    mov r8, r9          ; arg5

    syscall
    ret
