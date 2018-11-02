;nasm -f macho64 raw_osx.s -o raw_osx.o && ld -e _main -macosx_version_min 10.8 raw_osx.o -o raw_osx -lSystem && ./raw_osx
;objdump raw_osx.o -S > raw_osx.o.dump.txt
;objdump raw_osx -S > raw_osx.dump.txt
;bcomp raw_osx.dump.txt raw_osx.o.dump.txt

; %include "stud_io.inc"    

;;;;-------- bus error??
;;;global _main     
;;;
;;;section .text
;;;_main: 
;;;xor eax, eax
;;;again:
;;;; PRINT "Hello"
;;;; PUTCHAR 10
;;;inc eax     
;;;cmp eax, 5
;;;jl again


;-------- hello world
;;global _main
;;section .text
;;_main:
;;	mov     rax, 0x2000004 ; write
;;	mov     rdi, 1 ; stdout
;;	mov     rsi, msg
;;	mov     rdx, msg.len
;;	syscall
;;
;;	mov     rax, 0x2000001 ; exit
;;	mov     rdi, 0
;;	syscall
;;section .data
;;
;;msg:    db      "Hello, world! 世界你好！", 10
;;.len:   equ     $ - msg

;;;https://stackoverflow.com/questions/8451939/compiling-nasm-on-mac-osx
;;n 64 bit land, the first parameter is in RDI, not on the stack
;;The stack must be aligned on a 16-byte boundary before calling. When main is entered, the operating system has placed the (8 byte) return address of main on the stack, so pushing rbx before calling puts serves to get the stack realigned.
;;Also, nasm on macOS needs rel.
;-------- hola
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
