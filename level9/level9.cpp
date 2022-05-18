#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class N {
public:
  int nb;

  N(int nb) {
    // Assignation de la vtable
    this->nb = nb;
  };

  ~N(void) {};

  void setAnnotation(char *str) {
    memcpy(&this->nb, str, strlen(str));
  };

  void operator+(const N &rhs) {
    this->nb += rhs.nb;
  };

  void operator-(const N &rhs) {
    this->nb -= rhs.nb;
  };
};

int main(int argc, char **argv) {
  if (argc <= 1)
    exit(1);
  N first(int(108));
  N second(int(108));

  second.setAnnotation(argv[1]);
  first + second;
}
