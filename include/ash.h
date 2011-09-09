#ifndef _ASH_H
#define _ASH_H

#define ASH_NOP     0
#define ASH_QUIT    1
#define ASH_VERSION 2
#define ASH_HELP    4    
#define ASH_ERROR -1

#define _QUIT     "quit"
#define _VERSION  "version"
#define _HELP     "help"

#define ASH_PROMPT  "(ash) $ "
int ash(void);
#endif
