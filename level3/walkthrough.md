# level3

Dans `v()`: si `0x804988c == 64` alors on a un shell

[Exploitation du format string](https://www.exploit-db.com/papers/23985)

On veut utiliser le `%n` pour écrire à l'adresse de la variable globale (ici `coucou`) et set sa valeur à `64`

Grâce à `%4$n`, on choisit le 4e paramètre de printf, comme il n'en a pas, il va chercher le 4e pointeur sur la stack, soit dans notre cas, notre input qui est aussi le format.

À cette adresse là il va écrire le nombre de chars de notre format avant `%n`, soit `60 + 4 = 64`:

```bash
(python -c "print '\x8c\x98\x04\x08' + 'a'*60 + '%4\$n'" ; cat) | ./level3
```
