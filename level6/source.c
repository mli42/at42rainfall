#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n()
{
  system("/bin/cat /home/user/level7/.pass");
}

void m()
{
  puts("Nope");
}

int main(int argc, char **argv) {
  char *str;
  char *str1;

  str = malloc(0x40);
  str1 = malloc(0x4);
  *str1 = (long int)m;
  strcpy(str, argv[1]);

  ((void (*)())str1)();
}
