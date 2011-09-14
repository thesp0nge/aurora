#ifndef _CLI_H
#define _CLI_H

#include <getopt.h>
#include "aurora.h"

static int verbose_flag;

static struct option long_options[] =
{
  /* These options set a flag. */
  {"verbose", no_argument,       &verbose_flag, 1},
  {"brief",   no_argument,       &verbose_flag, 0},
  /* These options don't set a flag.  We distinguish them by their indices. 
  {"add",     no_argument,       0, 'a'},
  {"append",  no_argument,       0, 'b'},
  {"delete",  required_argument, 0, 'd'},
  {"create",  required_argument, 0, 'c'},
  {"file",    required_argument, 0, 'f'},
  */
  {"version", no_argument,        0, 'v'},
  {"help",    no_argument,        0, 'h'},
  {0, 0, 0, 0}
};

static char *short_version_string = "vh";

int aurora_parse_cli(int argc, char **argv, aurora_opts *opts);

#endif
