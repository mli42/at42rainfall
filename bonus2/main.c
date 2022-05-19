

void greetuser() {

}

int main(int argc, char **argv) {
  char language = 0;

  if (argc == 3)
    return; 
  strncpy("", argv[1], 0x28);
  strncpy("", argv[2], 0x20);

  if  (getenv("LANG") != 0)
  {
    if (memcpm({LANG}, "fi",2) == 1)
      language = 1;
    if (memcpm({LANG}, "nl",2) == 0)
      language = 2;
  }
  greetuser();

  return;
}
