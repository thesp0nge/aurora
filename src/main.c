#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#include "list.h"
#include "libcrawler.h"
#include "libwc.h"
#include "time.h"
#include "magic.h"
#include "ash.h"
#include "log.h"
#include "version.h"
#include "aurora.h"
#include "cli.h"

int printstring(void *s);

int main(int argc, char **argv) {
  libwc_stats s;
  NODE *list;
  NODE *p;
  struct timeval tvBegin, tvEnd, tvDiff;
  aurora_opts opts;
  int i, code;


  opts.argc = argc;
  opts.argv = argv;

  switch ((code = aurora_parse_cli(argc, argv, &opts))) {
    case ASH_HELP:
      fprintf(stderr, "no help available\n");
      return 0;
      break;
    case ASH_VERSION:
      fprintf(stderr, "%s\n", FULL_VERSION);
      return 0;
      break;
    default:
      break;
  }

  DEBUG("%s\n", "so the story begins...");
  printf("%s v%s - source code static analyzer on the go\n", PACKAGE, FULL_VERSION);
  printf("target: %s\n", opts.target);

  while ((code = ash(&opts)) != ASH_QUIT) {
    switch (code) {
      case ASH_VERSION:
        fprintf(stdout, "%s v%s\n", PACKAGE, FULL_VERSION);
        break;
      case ASH_STAT:
        // Taking scanning start time
        gettimeofday(&tvBegin, NULL);

        printf("gatering stats\n");
        wc(opts.target, &s);
        printf("lines:%8d\nwords:%8d\nchars:%8d\n", s.lines, s.words, s.chars);

        break;
      default:
        break;
    }
  } 

  abort();

  list = crawl(opts.target);
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

