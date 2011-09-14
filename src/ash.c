#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "config.h"
#include "ash.h"
#include "log.h"

int ash(aurora_opts *opts) {

  char *command = malloc(8192 * sizeof(char));
  int code = ASH_ERROR;


  memset(command, 0, 8192);

  fprintf(stdout, "%s", ASH_PROMPT);

  fgets(command, 8192, stdin);
  command[strlen(command)-1] = '\0';


  if (strcmp(command, _QUIT) == 0)
    code = ASH_QUIT;

  if (strcmp(command, _VERSION) == 0)
    code = ASH_VERSION;

  if (strcmp(command, _STAT) == 0)
    code = ASH_STAT;

  if (strcmp(command, _CRAWL) == 0)
    code = ASH_CRAWL;

  free(command);

  return code;
}
