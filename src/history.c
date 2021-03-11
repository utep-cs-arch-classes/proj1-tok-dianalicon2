#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history(){
  return (List*)malloc(sizeof(List)*1);
 
}
Item* get_new_item(){
  return (Item*)malloc(sizeof(Item)*1);
}
char *copy_str_h(char *str){
  short count=0;
  while(str[count]!='\n'){
    count=count+1;
  }
  char * new_str=(char *)malloc(sizeof(char)*count+1);
  int i;
  for(i=0;i<count;i++){
    *(new_str+i)=str[i];
  }
  new_str[i]='\0';
  return new_str;
}
void add_history(List *list, char *str){
  Item *temp=list->root;
  int id=1;
  if(!temp){
    list->root=get_new_item();
    temp=list->root;
  }else{
    id=2;
    while(temp && temp->next){
      temp=temp->next;
      id=id+1;
    }
    temp->next=get_new_item();
    temp=temp->next;
  }
  temp->str=copy_str_h(str);
  temp->id=id;
}
void print_history(List *list){
  Item *temp=list->root;
  while(temp){
    printf("\nID:%d ",temp->id);
    printf("  STRING:%s\n",temp->str);
    temp=temp->next;
  }
}
