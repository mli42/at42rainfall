# bonus3

On peut mettre un `\0` où on veut dans `str`.

Pour obtenir un shell, on veut que `str === argv[1]`

Or on sait que `atoi("")` rend `0`

Il suffit de donner une string vide en argument pour que le strcmp devienne `strcmp("", "")` et donc soit égal à 0

```bash
./bonus3 ""
```
