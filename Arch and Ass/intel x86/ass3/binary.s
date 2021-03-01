    .data
N: .quad 0
i: .quad 0
u: .quad 0

    .text
    .global _main


_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	
    xor %rbx, %rbx
	movq $63745, N(%rip)
	mov N(%rip), %rbx

    movq $64, u(%rip)
	
jacksonLoop:
	xor %rax, %rax
	movq %rax, i(%rip)
top:
	cmp %rax, u(%rip)
	je bottom

                    #loop code

    shl $1, %rbx
    jc operation1

operation0:
    mov $'0', %edi
    push %rbx
    push %rbx
    call _putchar
    pop %rbx
    pop %rbx
    jmp endoperation

operation1:
    mov $'1', %edi
    push %rbx
    push %rbx
    call _putchar
    pop %rbx
    pop %rbx

endoperation:

                     #loop code

	incq i(%rip)
	movq i(%rip), %rax
	jmp top
bottom:


    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret