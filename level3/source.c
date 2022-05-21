#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void v() {
  char str[0x200] = {0};
  char *coucou = "";

  fgets(str, 0x200, stdin);
  printf(str);
  if ((long int)coucou == 64)
    system("/bin/sh");
}

int main() {
  v();
}
