#pragma once

int open(const char *path, int flags, int mode);
int openat(int dirfd, const char *path, int flags, int mode);
int close(int fd);
int mkdir(const char *path, int mode);
