#include <stdio.h>
#include <stdlib.h>
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
  return str;
}
int count_words(char *str){
  if(word_start(str)==0)
    return 0;
  if(*word_end(word_start(str))==0)
    return 1;
   return count_words(word_end(word_start(str)))+1;    
}
char *copy_str(char *src, short len){
  char * new_src=(char *)malloc(sizeof(char)*len+1);
  int i;
  for(i=0;i<len;i++){
    *(new_src+i)=src[i];
  }
  new_src[i]='\0';
  return new_src;
}
char **tokenize(char *s){
  int string_num=count_words(s);
  char **tokens=(char **)malloc(sizeof(char*)*(string_num+1));
  tokens[string_num]=0;
  short dif;
  int i;
  char *start;
  i=0;
  for(i=0;i<string_num;i++){
    start=word_start(s);
    dif=word_end(word_start(start))-word_start(start);
    tokens[i]=copy_str(start,dif);
    s=s+dif+1;
  }
 
  return tokens;
}
void print_tokens(char **tokens){
  int i;
  i=0;
  while(tokens[i]!=0){
    printf("\ntokens[%d]:%s\n",i,tokens[i]);
  i=i+1;
  }
}
void free_tokens(char **tokens){
  int i;
  i=0;
  
  while(tokens[i]!=0){
    free(tokens[i]);
    i=i+1;
  }
  free(tokens[i]);
  free(tokens);
}
