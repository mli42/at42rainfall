
#include <stdlib.h>
#include <stdio.h>

void p() {
  char  str[60];
  char *coucou;
  gets(str);
  if (str & 0xb00000 == 0Xb00000)
    exit();
  else
    coucou = strdup(str)
}

int main() {

  p()

  return 0;

}
