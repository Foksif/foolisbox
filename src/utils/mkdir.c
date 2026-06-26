#include "../core.h"
#include "../syscalls.h"

#define WRITE_LITERAL(fd, str_literal)                                         \
  sys_write(fd, "" str_literal, sizeof(str_literal) - 1)

int mkdir_main(int argc, char **argv) {
  if (argc < 2) {
    WRITE_LITERAL(2, "ERR: Missing args.\nUsage: mkdir <dir>\n");
    return 1;
  }

  int result = sys_mkdir(argv[1], 0755);

  if (result < 0) {
    WRITE_LITERAL(2, "ERR: Could not create directory.\n");
    return 1;
  }

  return 0;
}
