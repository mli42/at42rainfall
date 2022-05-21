#include <string.h>
#include <unistd.h>
#include <stdio.h>

void p(char *str, char *sepa) {

  char to_read[0x1008] = "";
  puts(sepa);
  read(STDIN_FILENO, to_read, 0x1000);
  *strchr(to_read, '\n') = 0;
  strncpy(str, to_read, 20);
}

int pp(char *str) {

  char *sepa = " - \n";
  char first[20] = "";
  char second[20] = "";

  p(first, sepa);
  p(second, sepa);

  strcpy(str, first);
  str[strlen(str)] = ' ';

  str = strcat(str, second);
}

int main(int argc, char **argv) {
  char str[0x40]= "";

  pp(str);
  puts(str);
  return 0;
}
