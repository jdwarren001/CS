.macro BeginProgram
        .text
        .global main

    main:
        stp     x29, x30, [sp, -16]!
        add     x29, sp, 0
.endm

.macro EndProgram
        mov     w0, 0
        ldp     x29, x30, [sp], 16
        ret
.endm

.macro ForLoop var start end
    .data
\var:       .quad 0
end\var:    .quad 0
    .text
        ldr     x2, =end\var
        mov     x4, #\end
        str     x4, [x2] 

        ldr     x3, =\var
        mov     x1, #\start
        str     x1, [x3]
    top\var:
        ldr    x2, =end\var
        ldr     x4, [x2] 
        cmp     x1, x4
        beq     bottom\var
.endm

.macro Next var
        ldr     x3, =\var
        ldr     x1, [x3]
        add     x1, x1, #1
        str     x1, [x3]
        b       top\var
    bottom\var:
.endm