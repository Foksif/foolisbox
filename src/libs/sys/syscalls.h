#pragma once

// Process
#define SYS_EXIT 60
#define SYS_FORK 57
#define SYS_EXECVE 59
#define SYS_WAIT4 61

// File I/O
#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_CLOSE 3
#define SYS_LSEEK 8

// File system
#define SYS_UNLINK 87
#define SYS_RENAME 82
#define SYS_MKDIR 83
#define SYS_RMDIR 84
#define SYS_CHMOD 90

// File descriptors advanced
#define SYS_OPENAT 257
#define SYS_COPY_FILE_RANGE 326

// Memory (будущее)
#define SYS_MMAP 9
#define SYS_MUNMAP 11
#define SYS_BRK 12

// Time
#define SYS_NANOSLEEP 35
#define SYS_CLOCK_GETTIME 228
