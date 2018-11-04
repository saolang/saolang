;nasm -f macho64 test_X86_64.nasm -o test_X86_64.o && ld -e _main -macosx_version_min 10.13 test_X86_64.o -o test_X86_64 -lSystem && objdump -D ./test_X86_64.o && ./test_X86_64
          global    _main
          extern    _puts

          section   .text
_main:    push      rbx                     ; Call stack must be aligned
          lea       rdi, [rel message]      ; First argument is address of message
          call      _puts                   ; puts(message)
          pop       rbx                     ; Fix up stack before returning
          ret

          section   .data
message:  db        "Hola, mundo", 0        ; C strings need a zero byte at the end

;;global _main
;;section .text
;;_main:
;;mov  eax, 4
;;push dword [ebp + 16]
;;push dword [ebp + 12]
;;push dword [ebp + 8]
;;sub  esp, 4
;;int  0x80
;;jnc  .done
;;mov  eax, -1
;;.done:
;;
;;;//nasm -f macho64 test_X86_64.nasm -o test_X86_64.o
;;
