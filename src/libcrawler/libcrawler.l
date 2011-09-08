%{ 
  #include "list.h"

  NODE *first = NULL; // 
  NODE *current; // = first;
  NODE *tmp;
  int i=0;

%}

%%

[^ \t\n\r\f\v]+	{ if (first == NULL) { first = list_create("first"); current = first; } tmp=list_insert_after(current, (void*)yytext); current = tmp; i++; first->counter=i; }

%%
#include "libcrawler.h"

NODE *crawl(char *filename)
{ 

  YY_BUFFER_STATE bp; 
  FILE *f;
  if ((f = fopen(filename, "r")) == NULL) 
    return NULL;
  bp = yy_create_buffer(f,YY_BUF_SIZE ); 
  yy_switch_to_buffer(bp);
  yylex(); 
  yy_flush_buffer(bp);
  yy_delete_buffer(bp);
  fclose(f);

  return first;
}
