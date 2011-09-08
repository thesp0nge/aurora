#ifndef _MAGIC_H
#define _MAGIC_H

#ifdef HAVE_MAGIC_H
#include <magic.h>
#else
#define MAGIC_NONE 0

typedef int magic_t;

magic_t magic_open(int flags);
void magic_close(magic_t cookie);
const char *magic_file(magic_t cookie, const char *filename);
#endif

#endif
