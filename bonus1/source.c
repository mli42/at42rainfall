#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  char str[] = "";

  if (n > 9)
    return 1;

  memcpy(str, argv[2], n * 4);

  if (n == 0x574f4c46) {
    execl("/bin/sh", "sh", NULL);
  }

  return 0;
}
