section .data
    string: db "Hello, Holberton", 10, 0
    format: db "%s", 0

section .text
    global main
    extern printf
    default rel

main:
    push rbp
    mov rdi, format
    mov rsi, string
    mov rax, 0
    call printf wrt ..plt
    pop rbp
    mov rax, 0
    ret
