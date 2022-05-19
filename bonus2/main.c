#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void greetuser(char *str) {
  int lang = 0; /* {language} */
  char *hello = NULL;
  char *str1 = NULL;

  if (lang == 1) {
    hello = "Hyvää päivää ";

  }
  else if (lang == 2) {
    hello = "Goedemiddag! ";

  }
  else if (lang != 0) {
    hello = "Hello ";

  }

  strcat(str1, hello);
  puts(str1);

}

int main(int argc, char **argv) {
  char language = 0;

  if (argc != 3)
    return 1;
  strncpy("", argv[1], 0x28);
  strncpy("", argv[2], 0x20);

  char *lang = getenv("LANG");
  if (lang != NULL)
  {
    if (memcmp(lang, "fi", 2) == 1)
      language = 1;
    if (memcmp(lang, "nl", 2) == 0)
      language = 2;
  }
  greetuser();

  return 0;
}
