#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *g_str;

void m() {
  int n;

  n = (int)time(NULL);
  printf("%s - %d\n", g_str, n);
}

int main(int argc, char **argv) {
  char *str0 = malloc(8);
  char *str1 = malloc(8);
  char *str2 = malloc(8);
  char *str3 = malloc(8);

  strcpy(str3, argv[1]);
  strcpy(str2, argv[2]);

  FILE *file = fopen("/home/user/level8/.pass", "r");
  fgets(g_str, 0x44, file);
  puts("~~");
  return (0);
}
