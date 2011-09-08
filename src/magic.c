#ifndef HAVE_MAGIC_H
#include "magic.h"

// if libmagic is not available here it is our personal implementation
magic_t magic_open(int flags) {
  return 0;
}
void magic_close(magic_t cookie) {
  return;
}
const char *magic_file(magic_t cookie, const char *filename) {
  return "magic not yet implemented";
}
#endif
