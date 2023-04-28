section .data
    msg db 'Hello, Holberton',0xA,0

section .text
    global _start

_start:
    ; Prepare arguments for printf function
    mov rdi, msg ; First argument: pointer to the string
    xor eax, eax ; Clear eax register
    call printf ; Call printf function
    ; Exit program
    xor eax, eax ; Clear eax register
    mov al, 60 ; Set eax to exit syscall number
    xor edi, edi ; Clear edi register
    syscall ; Call exit syscall
