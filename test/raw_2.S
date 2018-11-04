//OSX, (!ATT)
.globl __test_osx_1
__test_osx_1:

mov  eax, 4 // sys_write
push dword [ebp + 16]
push dword [ebp + 12]
push dword [ebp + 8]
sub  esp, 4
int  0x80
jnc  .done
mov  eax, -1 //TODO
.done:
