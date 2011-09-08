#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#include "list.h"
#include "libcrawler.h"
#include "libwc.h"
#include "time.h"
#include "magic.h"


int printstring(void *s);

int main(int argc, char **argv) {
  libwc_stats s;
  NODE *list;
  NODE *p;
  struct timeval tvBegin, tvEnd, tvDiff;

  int i;
  printf("so the story begins...\n");
  printf("%s v%s - source code static analyzer on the go\n", PACKAGE, VERSION);

  printf("scanning test.txt file... no you cannot change this by now... sorry\n");

  // Taking scanning start time
  gettimeofday(&tvBegin, NULL);

  printf("gatering stats\n");
  wc("test.txt", &s);
  printf("lines:%8d\nwords:%8d\nchars:%8d\n", s.lines, s.words, s.chars);

  list = crawl("test.txt");
  printf("%d\n", list->counter);
  list_foreach(list, printstring);

  // Taking scanning end tyime
  gettimeofday(&tvEnd, NULL);

  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("scan duration: %ld.%06lds\n", tvDiff.tv_sec, tvDiff.tv_usec);

  printf("%s\n", magic_file(magic_open(MAGIC_NONE), "test.txt"));
  
  return 0;
}

int printstring(void *s)
{
	printf("%s\n", (char *)s);
	return 0;
}

