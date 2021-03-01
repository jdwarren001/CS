    .data
x: .quad 0
y: .quad 0
m: .quad 0
b: .quad 0    
    .text
    .global _main

_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
Begin:

    movq $3, m(%rip)       #random numbers for testing the equation
    movq $4, x(%rip)
    movq $8, b(%rip)

    mov m(%rip), %rax
    mov x(%rip), %rdi
    mul %rdi

    add b(%rip), %rax
    mov %rax, %rsi
    mov %rsi, y(%rip)

End:
    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret