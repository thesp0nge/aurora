#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ash.h"
#include "config.h"
#include "log.h"
#include "cli.h"

extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;

int aurora_parse_cli(int argc, char **argv, aurora_opts *opts){
  int c = 0;
  int ret = 0;

  while (1) {
    // getopt_long stores the option index here.
    int option_index = 0;
    c = getopt_long (argc, argv, short_version_string, long_options, &option_index);
    // no more options to process
    if (c == -1)
      break;
    switch (c) {
      case 0:
        /* If this option set a flag, do nothing else now. */
        if (long_options[option_index].flag != 0)
          break;
        printf ("option %s", long_options[option_index].name);
        if (optarg)
          printf (" with arg %s", optarg);
        printf ("\n");
        break;
      case 'v':
        ret = ASH_VERSION;
        break;
      case 'h':
        ret = ASH_HELP;
        break;
      case '?':
        /* getopt_long already printed an error message. */
        break;
        
      default:
        // it *really* should never reach this point
        abort();
        break;
    }
  }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
  {
    DEBUG("%s\n", "File and/or directories to be scanned: honoring the first one, ignoring others...");
    memcpy(opts->target, argv[optind++], FILENAME_SIZE-1);
    /*
    while (optind < argc)
      DEBUG("%s ", argv[optind++]);
     
     */
  }
  return ret;  

}
