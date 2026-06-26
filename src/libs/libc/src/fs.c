#include "../include/fs.h"
#include "../../sys/sys.h"

int open(const char *path, int flags, int mode) {
  return sys_call(SYS_OPEN, (long)path, flags, mode, 0, 0);
}

int openat(int dirfd, const char *path, int flags, int mode) {
  return sys_call(SYS_OPENAT, dirfd, (long)path, flags, mode, 0);
}

int close(int fd) { return sys_call(SYS_CLOSE, fd, 0, 0, 0, 0); }

int mkdir(const char *path, int mode) {
  return sys_call(SYS_MKDIR, (long)path, mode, 0, 0, 0);
}
