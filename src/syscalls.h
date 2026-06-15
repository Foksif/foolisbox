#ifndef SYSCALLS_H
#define SYSCALLS_H

typedef long ssize_t;
typedef unsigned long size_t;

static inline ssize_t sys_write(int fd, const void *buf, size_t count) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(1), "D"(fd), "S"(buf), "d"(count)
                       : "rcx", "r11", "memory");
  return ret;
}

static inline int sys_open(const char *filename, int flags, int mode) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(2), "D"(filename), "S"(flags), "d"(mode)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline ssize_t sys_read(int fd, void *buf, size_t count) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(0), "D"(fd), "S"(buf), "d"(count)
                       : "rcx", "r11", "memory");
  return ret;
}

static inline int sys_close(int fd) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(3), "D"(fd)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline int sys_unlink(const char *pathname) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(87), "D"(pathname)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline int sys_rename(const char *oldname, const char *newname) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(82), "D"(oldname), "S"(newname)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline int sys_mkdir(const char *pathname, int mode) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(83), "D"(pathname), "S"(mode)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline int sys_rmdir(const char *pathname) {
  long ret;
  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(84), "D"(pathname)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

static inline ssize_t sys_copy_file_range(int fd_in, long *off_in, int fd_out,
                                          long *off_out, size_t len,
                                          unsigned int flags) {
  long ret;

  register long rdi __asm__("rdi") = (long)fd_in;
  register long rsi __asm__("rsi") = (long)off_in;
  register long rdx __asm__("rdx") = (long)fd_out;
  register long r10 __asm__("r10") = (long)off_out;
  register long r8 __asm__("r8") = (long)len;
  register long r9 __asm__("r9") = (long)flags;

  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(326), "r"(rdi), "r"(rsi), "r"(rdx), "r"(r10),
                         "r"(r8), "r"(r9)
                       : "rcx", "r11", "memory");
  return (ssize_t)ret;
}
static inline int sys_openat(int dfd, const char *filename, int flags,
                             int mode) {
  long ret;
  register long r10 __asm__("r10") = (long)mode;

  __asm__ __volatile__("syscall"
                       : "=a"(ret)
                       : "a"(257), "D"(dfd), "S"(filename), "d"(flags), "r"(r10)
                       : "rcx", "r11", "memory");
  return (int)ret;
}

#endif
