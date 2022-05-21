

int main(int argc, char **argv)
{
  char *str;
  char *bin_sh = "/bin/sh";
  int uid;
  int gid;



  if atoi(argv[1] != 423)
    write(1, "No !\n", 5);
  else
  {
    str = strdup(bin_sh);
    setresgid(getegid(), getegid(), getegid());
    system(bin_sh);
  }
  return 0;
}
