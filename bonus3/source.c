#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  FILE *file;
  char str[0x42 * 2];

  file = fopen("/home/user/end/.pass", "r");
  memset(str, 0, 0x21);

  if (file == NULL || argc != 2)
    return -1;
  fread(str, 1, 0x42, file);
  str[atoi(argv[1])] = 0;

  fread(str + 0x42, 1, 0x41, file);
  fclose(file);

  if (strcmp(str, argv[1]) != 0)
    puts(str + 0x42);
  else
    execl("/bin/sh", "sh", NULL);
  return 0;
}
