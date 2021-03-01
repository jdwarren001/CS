.import "macrolib.s"

BeginProgram
    mov     x0, #123
    mov     x1, #10
    sdiv    x2, x0, x1
    msub    x3, x2, x1, x0
check:
    mov     x0, #0b11010101
    mov     x1, #0b01000000
    tst     x0, x1
check2:
    mov     x0, #0b11010101
    mov     x1, #0b00100000
    tst     x0, x1
check3:
EndProgram