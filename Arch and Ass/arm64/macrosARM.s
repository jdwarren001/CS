.include "macrolib.s"

BeginProgram
    ForLoop i,0,10 

        mov     w0, #65
        bl      putchar
        mov     w0, #10
        bl      putchar

    Next i
EndProgram