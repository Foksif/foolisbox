#include "../include/io.h"
#include "../../sys/sys.h"

ssize_t write(int fd, const void *buf, size_t n) {
  return sys_call(SYS_WRITE, fd, (long)buf, n, 0, 0);
}

ssize_t read(int fd, void *buf, size_t n) {
  return sys_call(SYS_READ, fd, (long)buf, n, 0, 0);
}
