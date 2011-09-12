#ifndef _ASH_H
#include "aurora.h"

#define _ASH_H

#define ASH_NOP     0
#define ASH_QUIT    1
#define ASH_VERSION 2
#define ASH_HELP    4    
#define ASH_STAT    8
#define ASH_ERROR -1

#define _QUIT     "quit"
#define _VERSION  "version"
#define _HELP     "help"
#define _STAT     "stat"

#define ASH_PROMPT  "(ash) $ "

int ash(aurora_opts *opts);
#endif
