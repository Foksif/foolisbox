#include "core.h"
#include "syscalls.h"

static int inline_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

static const char *get_basename(const char *path) {
  const char *base = path;
  while (*path) {
    if (*path == '/') {
      base = path + 1;
    }
    path++;
  }
  return base;
}

static const UtilityModule registry[] = {
    {"cat", cat_main}, {"echo", echo_main}, {"cp", cp_main}, {0, 0}};

int core_main(int argc, char **argv) {
  if (argc < 1)
    return 1;

  const char *prog_name = get_basename(argv[0]);

  for (int i = 0; registry[i].name != 0; i++) {
    if (inline_strcmp(prog_name, registry[i].name) == 0) {
      return registry[i].func(argc, argv);
    }
  }

  sys_write(2, "Coreutils master binary. Available modules:\n", 44);
  for (int i = 0; registry[i].name != 0; i++) {
    size_t len = 0;
    while (registry[i].name[len])
      len++;
    sys_write(2, " - ", 3);
    sys_write(2, registry[i].name, len);
    sys_write(2, "\n", 1);
  }
  return 1;
}
