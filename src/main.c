#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

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
#include "crawl.h"

int printstring(void *s);

int main(int argc, char **argv) {
  libwc_stats s;
  NODE *list;
  NODE *p;
  struct timeval tvBegin, tvEnd, tvDiff;
  aurora_opts opts;
  int i, code;
  sqlite3 *db;
  sqlite3_stmt *stmt;


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
  if (strlen(opts.target) != 0)
    printf("target: %s\n", opts.target);
  else {
    fprintf(stderr, "%s: missing target name\n", PACKAGE);
    return -1;
  }
  

  while ((code = ash(&opts)) != ASH_QUIT) {
    switch (code) {
      case ASH_VERSION:
        fprintf(stdout, "%s v%s\n", PACKAGE, FULL_VERSION);
        break;
      case ASH_STAT:
        // Taking scanning start time
        gettimeofday(&tvBegin, NULL);

        printf("gatering stats for %s\n", opts.target);
        wc(opts.target, &s);
        printf("lines:%8d\nwords:%8d\nchars:%8d\n", s.lines, s.words, s.chars);
        
        // Taking scanning end tyime
        gettimeofday(&tvEnd, NULL);

        timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
        printf("scan duration: %ld.%06lds\n", tvDiff.tv_sec, (long int)tvDiff.tv_usec);

        break;
      case ASH_CRAWL:
        // Taking scanning start time
        gettimeofday(&tvBegin, NULL);

        printf("crawling %s\n", opts.target);
        list = crawl(opts.target);
        printf("%d\n", list->counter);

        if (sqlite3_open("crawling.db", &db)) {
          fprintf(stderr, "%s: can't connect to crawling.db (%s)\n", PACKAGE, sqlite3_errmsg(db));
          sqlite3_close(db);
          return -1;
        }

        if (sqlite3_prepare_v2(db, "SELECT version FROM SCHEMA", -1, &stmt, 0)) {
          fprintf(stderr, "%s: can't get db schema version (%s)\n", PACKAGE, sqlite3_errmsg(db));
          sqlite3_close(db);
          return -1;
        } 
        

        if (sqlite3_step(stmt) == SQLITE_ROW){
          const char *val = (const char*)sqlite3_column_text(stmt,0);
          if (strcmp(val, DB_VERSION)==0)
            printf("DB OK!");
          else {
            fprintf(stderr, "%s: wrong database schema. %s version was found, %s expected\n", PACKAGE, val, DB_VERSION);
            sqlite3_close(db);
            return -1;
          }
        }

        sqlite3_close(db);
        // list_foreach(list, printstring);

        // Taking scanning end tyime
        gettimeofday(&tvEnd, NULL);

        timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
        printf("scan duration: %ld.%06lds\n", tvDiff.tv_sec, (long int)tvDiff.tv_usec);


        break;
      default:
        break;
    }
  } 

  printf("%s\n", magic_file(magic_open(MAGIC_NONE), "test.txt"));

 
  return 0;
}

int printstring(void *s)
{
	printf("%s\n", (char *)s);
	return 0;
}

