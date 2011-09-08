%{ 
  int words=0;
  int chars=0;
  int lines=0;
%}

%%

[^ \t\n\r\f\v]+	{ words++; chars += strlen(yytext); }
\n	{ chars++; lines++; }
.	{ chars++; }

%%
#include "libwc.h"

int wc(char *filename, libwc_stats *s)
{ 

  YY_BUFFER_STATE bp; 
  FILE *f;
  if ((f = fopen(filename, "r")) == NULL) 
    return -1;
  bp = yy_create_buffer(f,YY_BUF_SIZE ); 
  yy_switch_to_buffer(bp);
  yylex(); 
  yy_flush_buffer(bp);
  yy_delete_buffer(bp);
  s->lines = lines;
  s->words = words;
  s->chars = chars;
  fclose(f);
  // printf("%8d%8d%8d\n", s.lines, s.words, s.chars);

  return 0;
}
