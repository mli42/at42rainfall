

void greetuser() {

}

int main(int argc, char **argv) {

  if (argc == 3)
    return; 
  strncpy("", argv[1], 0x28);
  strncpy("", argv[2], 0x20);

  if  (getenv("LANG") == 0)
    return ;
  memcpm({LANG}, "fi",2);

}
