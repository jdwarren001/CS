.include "macrolib.s"

    .data
N:  .quad 0
i:  .quad 0
base:    .quad 10

BeginProgram
    ldr     x6, =i
    mov     x7, #0
    str     x7, [x6]
    ldr     x5, =N
    mov     x4, #500
    str     x4, [x5]
    ldr     x8, =base
    ldr     x9, [x8]

TopLoop:
    ldr     x5, =N
    ldr     x1, [x5]
    cmp     x1, #0
    beq     EndLoop
    mov     x3, #0
    udiv    x2, x1, x9
    msub    x3, x2, x9, x1
    str     x2, [x5]

    add     x3, x3, #'0'
    cmp     x3, #'9'
    ble     Number
    add     x3, x3, #7
Number:
    mov     x0, x3
    stp     x29, x0, [sp, -16]!
    ldr     x6, =i
    ldr     x7, [x6]
    add     x7, x7, #1
    str     x7, [x6]
    b       TopLoop
EndLoop:

TopLoop2:
    ldr     x6, =i
    ldr     x7, [x6]
    str     x7, [x6]

    cmp     x7, #0
    beq     EndLoop2
    ldp     x29, x0, [sp], 16
    bl      putchar
    ldr     x6, =i

    ldr     x7, [x6]
    sub     x7, x7, #1
    str     x7, [x6]
    b       TopLoop2
EndLoop2:

EndProgram