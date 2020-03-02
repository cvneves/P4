; compiled with nasm -felf64 -o test.o test.asm && gcc -no-pie -o test test.o -lc

extern printf

global main

section .data
    printf_format db '%d', 10, 0
    msg db "Hello world", 0
    var_x dd 20
    var_y dd -15

section .text
main:
    mov rbx, 100
    call Func

   push rbp
   mov rdi, printf_format
   mov rsi, rax
   mov rax, 0
   call printf
   pop rbp
   mov rax, 0

   ret


    
Func:
    cmp rbx, 1
    jg Calc
    mov rax, 1
    ret

Calc:
    dec rbx
    call Func
    inc rbx
    add rax, rbx
    ret