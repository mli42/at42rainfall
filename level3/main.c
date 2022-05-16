
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void v() {

  char str[200] = {""};
  char *coucou = "";
  fgets(str);
  printf(str);
  if ((int)coucou == 64)
    system("/bin/sh");
  else
    exit();

}


int main() {
  v();
}
