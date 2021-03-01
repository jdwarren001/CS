    .data
i: .quad 0
    .text

StartProgram

    mov $’s’, %al
    mov $’t’, %ah

    add $'a', %dl
top:
    mov i(%rip), %rcx
    mov #26, %rdx
    cmp %rcx, %rdx
    jz bottom

    cmp %dl, %al        #im not too sure about these registers, but i wanted to keep with 8bits
    jz skip
    cmp %dl, %ah
    jz skip

    mov %dl, %dil
    push %dl
    push %dl
    call _putchar 
    pop %dl 
    pop %dl
skip:
    add %dl, $1
    mov i(%rip), %rcx
    inc %rcx
    mov %rcx, i(%rip)
    jmp top
bottom:

EndProgram