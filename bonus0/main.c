
int p(char *str, char *sepa) {

  char *to_read = "";
  puts(sepa);
  read(stdin, to_read, 0x1000);
  index = strchr('\n', to_read);
  to_read[index] = '\0';
  strncpy(str, to_read, 20);
}
int pp(char *str) {

  char *sepa = " - \n";
  char *new= "";
  char *blank= " ";
  char *first;
  char *second;

  p(first, sepa);
  p(second, sepa);

  strcpy(first, second);
  strlen(first);

  str = strcat(first, second)
}

int main(int argc, char argv**) {

  char *str= "";
  pp(str);

  puts(str);
  return 0;
}
