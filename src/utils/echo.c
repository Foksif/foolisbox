#include "../core.h"
#include "../memcopy.h"
#include "../syscalls.h"

int strLen(char *str) {
  int i = 0;

  while (1) {
    if (str[i] == '\0')
      return i;
    i++;
  }
}

int echo_main(int argc, char **argv) {
  char buffer[50];
  int buferZ = 0;

  for (int i = 1; i < argc; i++) {
    mem_copy(buffer + buferZ, argv[i], strLen(argv[i]));
    buferZ += strLen(argv[i]);

    if (i + 1 < argc) {
      buffer[buferZ] = ' ';
      buferZ += 1;
    }
  }

  buffer[buferZ] = '\n';
  buferZ += 1;
  sys_write(1, buffer, buferZ);

  return 0;
}
