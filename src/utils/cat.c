#include "../core.h"
#include "../syscalls.h"

#define BUFFER_SIZE 4096

static void stream_copy(int src_fd) {
  char buffer[BUFFER_SIZE];
  ssize_t bytes_read;

  while ((bytes_read = sys_read(src_fd, buffer, BUFFER_SIZE)) > 0) {
    sys_write(1, buffer, bytes_read);
  }
}

int cat_main(int argc, char **argv) {
  if (argc == 1) {
    stream_copy(0);
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    int fd = sys_open(argv[i], 0, 0);
    if (fd < 0) {
      sys_write(2, "cat: error opening file\n", 24);
      continue;
    }

    stream_copy(fd);
    if (i + 1 != argc) {
      sys_close(fd);
    }
  }
  return 0;
}
