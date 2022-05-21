#include <stdio.h>
#include <stdlib.h>

char str[0x200] = { 0 };

void o(void) {
  system("/bin/sh");
  exit(1);
}

void n(void) {
  fgets(str, 0x200, stdin);
  printf(str);
  exit(1);
}

int main(void) {
  n();
}
