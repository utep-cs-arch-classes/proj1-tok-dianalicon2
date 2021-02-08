#include <stdio.h>

void main(){
  char a;
  char b;
  int ch[100];
  int i;
  printf("input a string\n");
  a=0;
  i=0;
  while(a!='\n'){
    a=getchar();
    ch[i]=a;
    i=i+1;
  }
  printf("%c%c%c ",ch[0],ch[1],ch[2]);
}
