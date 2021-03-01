    .data
i: .quad 0
    .text

StartProgram

    mov r1, #’z’
    mov r2, #’a’

    mov r3, #'a'
top:
    ldr x1, =i
    ldr x2, [x1]
    mov x3, #26
    cmp x3, x2
    beq bottom

    cmp r3, r1
    beq skip
    cmp r3, r2
    beq skip

    mov r0, r3      //-> used r0 for putchar
    bl putchar
    b next
skip:
    mov r0, #'-'
    bl putchar
next:
    add r3, r3, #1

    ldr x1, =i
    ldr x2, [x1]
    add x2, x2, #1
    str x2, [x1]
    b top
bottom:

EndProgram