#ifndef _AURORA_H
#define _AURORA_H

#define FILENAME_SIZE 512

typedef struct {
  int argc; 
  char **argv;
  char target[FILENAME_SIZE];
  int verbose;
} aurora_opts;

#endif
