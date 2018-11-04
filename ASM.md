# ASM

| INTEL | AT&T |
| -- | -- |
| mov eax,8 | movl   $8,%eax |
| mov     ebx,0ffffh | movl   $0xffff,%ebx |
| int 80h | int      $0x80 |
| MOV EBP, ESP | movl %esp, %ebp |
| DEC WORD PTR [EBX] | decw (%eax) |
| MOV EAX, [0100]        | movl           0x0100, %eax | 
| MOV EAX, [ESI]         | movl           (%esi), %eax |
| MOV EAX, [EBP-8]       | movl         -8(%ebp), %eax |
| MOV EAX, [EBX*4+0100]  | movl  0x0100(,%ebx,4), %eax |
| MOV EAX, [EDX+EBX*4+8] | movl 0x8(%edx,%ebx,4), %eax | 
| MOV EAX,    8h | movl 0x8   , %eax |  
| MOV EAX,   10o | movl 010   , %eax | 
| MOV EAX, 1000b | movl 0b1000, %eax | 
| SUB EAX, 30 | subl $0x30, %eax |
| -- | -- |
| BYTE PTR、WORD PTR、DWORD PTR | -b -w -l |
| -h -o -b | 0x- 0- 0b- |
| segreg:[base+index*scale+disp] | %segreg:disp(base,index,scale) |

