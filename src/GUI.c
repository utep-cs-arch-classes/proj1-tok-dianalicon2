#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main(){
  char a;
  int i;
  List *history=init_history();
  Item *temp;
  while(1){
    char word[100];
    i=0;
    printf("input  string\n");
    while((a=getchar())!='\n'){
      word[i]=a;
      i=i+1;
      putchar(a);
    }
    word[i]='\0';
    if(word[0]=='q'&& word[1]=='\0'){
      break;
    }
    add_history(history,word);
    printf("\nyou entered %d words\n",count_words(word));
    char** tokens=tokenize(word);
    print_tokens(tokens);
  }
  print_history(history);
}
