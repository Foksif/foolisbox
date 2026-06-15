#include "../core.h"
#include "../syscalls.h"

#define WRITE_LITERAL(fd, str_literal)                                         \
  sys_write(fd, "" str_literal, sizeof(str_literal) - 1)

int cp_main(int argc, char **argv) {
  if (argc < 3) {
    WRITE_LITERAL(2, "ERR: Mising args. \nUsage: cp <sorce> <dist>");
    return 1;
  }

  int fd_in = sys_open(argv[1], 0, 0);
  if (fd_in < 0) {
    WRITE_LITERAL(2, "ERR: Cloud not open src file.\n");
    return 1;
  }
  int fd_out = sys_openat(-100, argv[2], 01101, 0644);
  if (fd_out < 0) {
    WRITE_LITERAL(2, "ERR: Cloud not crete dist file.\n");
    return 1;
  }

  long copied;
  int status = 0;

  while (1) {
    copied = sys_copy_file_range(fd_in, 0, fd_out, 0, 2147483647, 0);

    if (copied == 0) {
      break;
    }

    if (copied < 0) {
      char buffer[8192];

      while (1) {
        long bytes_read = sys_read(fd_in, buffer, 8192);

        if (bytes_read == 0) {
          break;
        }

        if (bytes_read < 0) {
          WRITE_LITERAL(2, "ERR: IDK 2");
          status = 1;
          break;
        }

        long bytes_write = sys_write(fd_out, buffer, bytes_read);

        if (bytes_write < 0) {
          WRITE_LITERAL(2, "ERR: IDK 3");
          status = 1;
          break;
        }
      }
      break;
    }
  }

  sys_close(fd_in);
  sys_close(fd_out);
  return status;
}
