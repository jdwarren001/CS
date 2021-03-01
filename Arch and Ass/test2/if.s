    .data
x: .quad 0
ground: .quad 0
    .text
    .global _main

_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
Begin:

    movq $9, x(%rip)
    movq $10, ground(%rip)

    mov x(%rip), %rax
    cmp %rax, ground(%rip)
    jz if
then:
    mov $'Z', %rdi
    call _putchar
    jmp End

if:
    mov $'A', %rdi
    call _putchar

End:
    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret