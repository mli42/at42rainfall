#include <stdio.h>
#include <stdlib.h>

void p(char *str) {
  printf(str);
}

void n() {
  char str[0x200];

  fgets(str, 0x200, stdin);
  p(str);

  if (*(int *)0x8049810 == 0x1025544) // 16930116
    system("/bin/cat /home/user/level5/.pass");
}

int main(void)
{
  n();
}
