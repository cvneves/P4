; compiled with nasm -felf64 -o test.o test.asm && gcc -no-pie -o test test.o -lc

extern printf

global main

section .text
main:
    push rbp

    mov rdi, printf_format
    mov rsi, msg
    mov rax, 0
    call printf

    pop rbp

    mov rax, 0
    ret

section .data
    printf_format: db '%s', 10, 0
    msg: db "Hello world", 0