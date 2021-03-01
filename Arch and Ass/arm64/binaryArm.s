.include "macrolib.s"
        .data
N:      .quad 123
mask:   .quad 0

BeginProgram

    ldr     x3, =mask
    mov     x4, #0x8000000000000000
    str     x4, [x3]

    ForLoop i,0,64 
        ldr     x3, =N
        ldr     x5, [x3]
        ldr     x3, =mask
        ldr     x4, [x3]

        ANDS    x5, x4, x5
        lsr     x4, x4, #1
        str     x4, [x3]

        beq     out0
        mov     w0, #'1'
        b       out
    out0:
        mov     w0, #'0'
    out:
        bl      putchar
    Next i
EndProgram