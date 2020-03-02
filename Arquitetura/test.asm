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

    push rbp

    mov rdi, printf_format
    mov rax, [var_x]
    mov rbx, [var_y]
    add rax, rbx
    mov rsi, rax
    mov rax, 0
    call printf

    pop rbp

    mov rax, 0
    ret

MeuProc:
    push ebp
    mov ebp, esp

    sub esp, 8

    mov DWORD PTR [ebp-4], 10
    mov DWORD PTR [ebp-8], 20

    mov esp, ebp
    pop ebp
    ret
