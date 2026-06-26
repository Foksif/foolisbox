#pragma once

/* open flags */
#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2

#define O_CREAT 0100
#define O_TRUNC 01000
#define O_APPEND 02000

/* permissions */
#define S_IRWXU 0700
#define S_IRWXG 0070
#define S_IRWXO 0007
