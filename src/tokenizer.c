#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  if(c=='\n'||c=='\t'||c==' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  return !space_char(c);
}
char *word_start(char *str){
  while(space_char(*str)&&*str!='\0'){
    str=(str+1);
  }
  if(*str=='\0'){
    return 0;
  }
  return str;
}
char *word_end(char *str){
  while(non_space_char(*str)&&*str!='\0'){
    str=(str+1);
  }
  if(*str=='\0')
    return 0;
  return str;
}
