#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int8_t language = 0;

void greetuser(char *argv) {
  char greeting[0x48] = { 0 };

  if (language == 1)
    strcpy(greeting, "Hyvää päivää ");
  else if (language == 2)
    strcpy(greeting, "Goedemiddag! ");
  else if (language == 0)
    strcpy(greeting, "Hello ");

  strcat(greeting, argv);
  puts(greeting);
}

int main(int argc, char **argv) {
  char dest[0x4c] = { 0 }; // 0x9c - 0x50
  char *lang_env = NULL;

  if (argc != 3)
    return 1;
  memset(dest, 0, 0x13);
  strncpy(dest, argv[1], 0x28);
  strncpy(&dest[0x28], argv[2], 0x20);

  lang_env = getenv("LANG");
  if (lang_env != NULL)
  {
    if (memcmp(lang_env, "fi", 2) == 0)
      language = 1;
    else if (memcmp(lang_env, "nl", 2) == 0)
      language = 2;
    else
      language = 0; // Implicit
  }
  char greet_arg[0x13];
  memcpy(greet_arg, dest, 0x13);
  greetuser(lang_env);

  return 0;
}
