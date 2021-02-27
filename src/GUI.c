#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

void main(){
  char a;
  char ch[100];
  int i;
  i=0;
  printf("input  string\n");
  while((a=getchar())!='\n'){
    ch[i]=a;
    i=i+1;
    putchar(a);
 
     
  }
  ch[i]='\0';

  printf("\nyou entered %d words\n",count_words(ch));
  char **t;
  t=tokenize(ch);
  
  print_tokens(t);
}
