global write
global read

section .text

; ssize_t write(int fd, void *buf, size_t n)
write:
    mov eax, 1       ; SYS_WRITE
    syscall
    ret

; ssize_t read(int fd, void *buf, size_t n)
read:
    mov eax, 0       ; SYS_READ
    syscall
    ret
