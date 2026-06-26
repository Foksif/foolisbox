#include "../include/io.h"
#include "../include/string.h"

static void print_str(const char *s) { write(1, s, strlen(s)); }

static void print_int(long x) {
  char buf[32];
  int i = 30;
  buf[31] = 0;

  if (x == 0) {
    write(1, "0", 1);
    return;
  }

  int neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }

  while (x && i) {
    buf[i--] = '0' + (x % 10);
    x /= 10;
  }

  if (neg)
    buf[i--] = '-';

  write(1, &buf[i + 1], 30 - i);
}

void printf(const char *fmt, ...) {
  unsigned long *args = (unsigned long *)&fmt;
  args++;

  for (int i = 0; fmt[i]; i++) {
    if (fmt[i] != '%') {
      write(1, &fmt[i], 1);
      continue;
    }

    i++;
    if (fmt[i] == 's') {
      print_str((char *)*args++);
    } else if (fmt[i] == 'd') {
      print_int((long)*args++);
    } else if (fmt[i] == '%') {
      write(1, "%", 1);
    }
  }
}
