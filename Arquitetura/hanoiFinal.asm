;nasm -f elf32 hanoi.asm && gcc -m32 -o hanoi hanoi.o

section .data
    printf_format db "%d, ", 0
    msg db "Insira o numero de discos: ", 0
    saida_format db "Mover da Torre %d para Torre %d", 10, 0
    scanf_format db "%d", 0
    nDiscos: times 4 db 0

section .bss
    vector resb 2 * 63 * 4

section .text
    extern printf
    extern scanf
    global main


main:

    push ebp
    mov ebp, esp

    push -1

    
 entrada:
    mov ecx, msg
    push ecx
    call printf
    pop ecx

    push nDiscos 
    push scanf_format
    call scanf
    add esp, 8 

    mov eax, [nDiscos]
    cmp eax, 6
    jg entrada
    cmp eax, 1
    jl entrada
        
    mov cl, al
    mov ebx, 1
    shl ebx, cl
    dec ebx
    shl ebx, 3
    sub esp, ebx
    mov ecx, esp
    ; sub ecx, 4
    
    push 2
    push 3
    push 1
    push eax
    
    call Hanoi
    add esp, 16

    
    loop_print_stack:
        pop eax
        cmp eax, -1
        je fim_do_main
        push eax
        push saida_format
        call printf
        pop eax
        add esp, 8
        jmp loop_print_stack
    

    fim_do_main:

        pop ebp
        ret

Hanoi:
    push ebp
    mov ebp, esp

    cmp dword [ebp + 8], 1
    jne n_greater_than_1

    mov eax, [ebp + 12]
    mov ebx, [ebp + 16]
    mov dword [ecx], eax
    add ecx, 4
    mov dword [ecx], ebx
    add ecx, 4
 
    mov esp, ebp
    pop ebp
    ret

    n_greater_than_1:
        push dword [ebp + 16]
        push dword [ebp + 20]
        push dword [ebp + 12]
        mov eax, [ebp+8]
        dec eax
        push eax
       
        call Hanoi
        
        add esp, 16

        mov eax, [ebp + 12]
        mov ebx, [ebp + 16]
        mov dword [ecx], eax
        add ecx, 4
        mov dword [ecx], ebx
        add ecx, 4

        push dword [ebp + 12]
        push dword [ebp + 16]
        push dword [ebp + 20]
        mov eax, [ebp+8]
        dec eax
        push eax
       
        call Hanoi

        add esp, 16
    
    mov esp, ebp
    pop ebp
    ret