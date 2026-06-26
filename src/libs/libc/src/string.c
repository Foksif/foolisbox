#include "../include/string.h"

size_t strlen(const char *s) {
  size_t i = 0;
  while (s[i])
    i++;
  return i;
}

void *memcpy(void *dst, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dst;
  const unsigned char *s = (const unsigned char *)src;

  for (size_t i = 0; i < n; i++)
    d[i] = s[i];

  return dst;
}
