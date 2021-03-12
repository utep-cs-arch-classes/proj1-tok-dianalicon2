#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int get_int();
int power(int base, int pow);
void main(){
  char a;
  int i;
  List *history=init_history();
  Item *temp;
  while(1){
    char word[100];
    i=0;
    printf("input  string or enter 'q' to quit\n");
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
  printf("\nwould you like to 1)view full history or 2)search by index\n");
  char option=getchar();
  if(option=='1'){
    print_history(history);
  }
  else{
    getchar();
    int id=get_int();
    printf("\n%s\n",get_history(history,id));
  }
  //free_history(history);
}
int get_int(){
  char ch;
  char str[10];
  int len=0;
  printf("enter ! followed by the id number (ex: !3)\n");
  getchar();
  while((ch=getchar())!='\n'){
    str[len]=ch;
    len=len+1;
 }
  str[len]='\0';
  int count;
  int result=0;
  len=len-1;
  for(count=len;count>=0;count--){
    result=result+((str[len-count]-48) * power(10,count));
    }
  return result;
}
int power(int base, int pow){
  if(pow==0)
    return 1;
  return base * power(base,pow-1);
}
