#include <stdio.h>

void main(){
  char a;
  char b;
  char ch[100];
  int i;
  printf("input a string\n");
  a=0;
  i=0;
  while(a!='\n'){
    a=getchar();
    ch[i]=a;
    i=i+1;
  }
  a=0;
  i=0;
  while(a!='\n'){
    a=ch[i];
    printf("%c",a);
    i=i+1;
  }
}
