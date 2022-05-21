#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
  int32_t var_bp;
  char *size;
  FILE *nitems;
  FILE *stream;
  char *src;

  char *service;
  char *auth;

  while (1) {
    printf("%p, %p \n", auth, service);

    stream = stdin;
    fgets(src, 128, stream);

    if (src == NULL)
      break ;
    else if (strncmp("auth ", src, 5)) {
      int8_t dl = 0;
      int8_t al = 1;
      // When src > "auth", then alloc space

      auth = malloc(4);

      int8_t ecx = -1;
      al = 0;
      while (1 /* repne scasb al, byte es:[edi] */) {
        ecx -= 1;
      }
      if (!ecx - 1 < 0x1e) {
        strcpy(auth, src + 5);
      }
    }
    else if (strncmp("reset", src, 5)) {
      free(auth);
    }
    else if (strncmp("service", src, 6)) {
      service = strdup(src);
    }
    else if (strncmp("login", src, 5)) {
      if (auth[0x20] == 0) {
        stream = stdout;
        fwrite("Password:\n", 1, 0xa, stream);
      }
      else {
        system("/bin/sh");
      }
    }
  }
  return 0;
}

// c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
