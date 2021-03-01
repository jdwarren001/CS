.include "stdlib.s"


BeginProgram
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
    ForLoop i,0,10 
        mov $'J', %edi
        callq _putchar
        mov $'A', %edi
        callq _putchar
        mov $'C', %edi
        callq _putchar
        mov $'K', %edi
        callq _putchar
        mov $'S', %edi
        callq _putchar
        mov $'O', %edi
        callq _putchar
        mov $'N', %edi
        callq _putchar
        mov $'\n', %edi
        callq _putchar
    Next i
    addq	$16, %rsp
	popq	%rbp
EndProgram