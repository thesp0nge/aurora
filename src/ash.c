#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "ash.h"


int ash(void) {

  char *command = malloc(8192 * sizeof(char));


  memset(command, 0, 8192);
  fprintf(stdout, "%s", ASH_PROMPT);
  scanf("%8192s", command);

  command[strlen(command)] = '\0';

  fprintf(stderr, "DEBUG @ %s:%d = %s\n", __FILE__, __LINE__, command);

  if (strcmp(command, _QUIT) == 0)
    return ASH_QUIT;

  if (strcmp(command, _VERSION) == 0)
    return ASH_VERSION;

  free(command);

  return ASH_ERROR;
}
