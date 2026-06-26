#ifndef CORE_H
#define CORE_H

typedef struct {
  const char *name;
  int (*func)(int argc, char **argv);
} UtilityModule;

int cat_main(int argc, char **argv);
int echo_main(int argc, char **argv);
int cp_main(int argc, char **argv);
int mkdir_main(int argc, char **argv);

#endif
