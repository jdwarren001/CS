        .text
        .global main
main:
        stp     x29, x30, [sp, -16]!
        add     x29, sp, 0
/*code*/

        mov     w0, #65
        bl      putchar
        mov     w0, #10
        bl      putchar

/*code*/
        mov     w0, 0
        ldp     x29, x30, [sp], 16
        ret