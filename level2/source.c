#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void p() {
  char  str[60];
  char *coucou;

  gets(str);
  if (((long int)str & 0xb00000) == 0Xb00000)
    exit(1);
  else {
    puts(str);
    coucou = strdup(str);
  }
}

int main() {
  p();
  return 0;
}
