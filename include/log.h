#ifndef _LOG_H

#define DEBUG(fmt, ...) \
  do { if (IS_DEBUG) fprintf(stderr, "DEBUG @ %s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); } while (0)

#endif
