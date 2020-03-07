;nasm -f elf32 bin_hanoi.asm && gcc -m32 -o bin_hanoi bin_hanoi.o

section .data
    printf_format db "%d", 10, 0
    msg db "Insira o numero de discos: ", 0
    saida_format db "Mover da Torre %d para Torre %d", 10, 0
    scanf_format db "%d", 0
    nDiscos: times 4 db 0
    indice_torres db 1,2,3

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

    


    mov eax, 1
    shl eax, 2 + (2 + 1)
    sub eax, 8

    sub esp, eax

    add eax, 8
    shr eax, (2 + 1)

    push esp
    push eax
    call BinaryHanoi
    add esp, 8
    

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

    ;add esp, 36

    fim_do_main:
    pop ebp
    ret

BinaryHanoi:
    push ebp
    mov ebp, esp
    push 0

    mov ebx, 1
    xor ecx, ecx

    BinHanoiLoop:
    cmp ebx, [ebp + 8]
    je EndBinHanoiLoop
    push ebx
    push ecx
    and ebx, ecx
    ;
    ; dec ebx
    ;
    xor edx, edx
    mov eax, ebx
    mov ecx, 3
    div ecx


    mov ecx, [ebp + 12]
    mov eax, [ebp - 4]
    mov dword [ecx + eax], edx
    add eax, 4
    mov dword [ebp - 4], eax

    pop ecx
    pop ebx

    push ebx
    push ecx

    or ebx, ecx
    inc ebx
    xor edx, edx

    ;dec ebx
    
    mov eax, ebx
    mov ecx, 3
    div ecx


    mov ecx, [ebp + 12]
    mov eax, [ebp - 4]
    mov dword [ecx + eax], edx
    add eax, 4
    mov dword [ebp - 4], eax

    pop ecx
    pop ebx
    
    inc ebx
    inc ecx
    jmp BinHanoiLoop  

    EndBinHanoiLoop:

    add esp, 4
    mov esp, ebp
    pop ebp
    ret

Hanoi:
    push ebp
    mov ebp, esp

    cmp dword [ebp + 8], 1
    jne n_greater_than_1

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