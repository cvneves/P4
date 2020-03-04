; compiled with nasm -felf64 -o test.o test.asm && gcc -no-pie -o test test.o -lc
;nasm -f elf32 test.asm && gcc -m32 -o test test.o


section .data
    printf_format db "%d", 10, 0
    saida_format db "Mover disco %d de %d para %d", 10, 0
    msg_1 db 'Furafic fark', 10, 0
    ; vector dd 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, -1
    ; vetor_cont dd 0

section .bss
    vector resb 2 * 63 * 4

section .text
    extern printf
    extern scanf
    global main


main:

    push ebp
    mov ebp, esp

    push 2
    push 3
    push 1
    push 2
    
    xor ecx, ecx
    
    call Hanoi

    add esp, 16

    mov dword [vector + ecx], -1

    call PrintVec

    pop ebp
    ret

FuncSum:
    push ebp
    mov ebp, esp

    mov eax, [esp+8]
    mov ebx, [esp+12]

    add eax, ebx

    mov esp, ebp
    pop ebp
    ret

PrintVec:
    push ebp
    mov ebp, esp

    mov eax, vector
    mov ecx, [eax]


    loopPrintvec:
    mov ecx, [eax]
    cmp ecx, -1
    je fimPrintVec
    push ecx
    push eax
    push ecx
    push printf_format
    call printf
    add esp, 8
    pop eax
    pop ecx
    add eax, 4
    jmp loopPrintvec

    fimPrintVec:
    mov esp, ebp
    pop ebp
    ret

Hanoi:
    push ebp
    mov ebp, esp

    cmp dword [ebp + 8], 1
    jne n_greater_than_1
   
    ; push dword [ebp + 16]
    ; push dword [ebp + 12]
    ; push dword [ebp + 8]
    ; push saida_format
    ; call printf
    ; add esp, 16

    mov eax, [ebp + 12]
    mov ebx, [ebp + 16]
    mov dword [vector + ecx], eax
    add ecx, 4
    mov dword [vector + ecx], ebx
    add ecx, 4

   
 
    mov esp, ebp
    pop ebp
    ret

    n_greater_than_1:
        push dword [ebp + 16]
        push dword [ebp + 20]
        push dword [ebp + 12]
        mov eax, [ebp+8]
        sub eax, 1
        push eax
       
        call Hanoi
        
        add esp, 16

        ; push dword [ebp + 16]
        ; push dword [ebp + 12]
        ; push dword [ebp + 8]
        ; push saida_format
        ; call printf
        ; add esp, 16

        mov eax, [ebp + 12]
        mov ebx, [ebp + 16]
        mov dword [vector + ecx], eax
        add ecx, 4
        mov dword [vector + ecx], ebx
        add ecx, 4

        push dword [ebp + 12]
        push dword [ebp + 16]
        push dword [ebp + 20]
        mov eax, [ebp+8]
        sub eax, 1
        push eax
       
        call Hanoi


        add esp, 16

      




      

    
    mov esp, ebp
    pop ebp
    ret

