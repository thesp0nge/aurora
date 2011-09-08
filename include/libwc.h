#ifndef _LIB_WC_H
#define _LIB_WC_H
typedef struct {
  int chars; 
  int words;
  int lines; 
} libwc_stats;

int wc(char *filename, libwc_stats *s);
#endif
