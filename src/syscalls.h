#ifndef SYSCALLS_H
#define SYSCALLS_H

typedef long ssize_t;
typedef unsigned long size_t;

long sys_call(long num, long a1, long a2, long a3, long a4, long a5);

// IO

static inline ssize_t sys_write(int fd, const void *buf, size_t count) {
  return sys_call(1, fd, (long)buf, count, 0, 0);
}

static inline ssize_t sys_read(int fd, void *buf, size_t c) {
  return sys_call(0, fd, (long)buf, c, 0, 0);
}

static inline ssize_t sys_copy_file_range(int fd_in, long *off_in, int fd_out,
                                          long *off_out, size_t len,
                                          unsigned int flags) {
  return sys_call(326, fd_in, (long)off_in, fd_out, (long)off_out, len);
}

static inline int sys_close(int fd) { return sys_call(3, fd, 0, 0, 0, 0); }

// FILES

static inline int sys_open(const char *f, int flags, int mode) {
  return sys_call(2, (long)f, flags, mode, 0, 0);
}

static inline int sys_openat(int dfd, const char *filename, int flags,
                             int mode) {
  return sys_call(257, dfd, (long)filename, flags, mode, 0);
}

static inline int sys_unlink(const char *pathname) {
  return sys_call(87, (long)pathname, 0, 0, 0, 0);
}

static inline int sys_rename(const char *oldname, const char *newname) {
  return sys_call(82, (long)oldname, (long)newname, 0, 0, 0);
}

// DIRECTORIES

static inline int sys_mkdir(const char *p, int mode) {
  return sys_call(83, (long)p, mode, 0, 0, 0);
}

static inline int sys_rmdir(const char *p) {
  return sys_call(84, (long)p, 0, 0, 0, 0);
}

#endif
