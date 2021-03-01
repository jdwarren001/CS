	.data 
i: .quad 0
n: .quad 0
	.text
	.global _main

_main: 
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movq $10, n(%rip)
	
jacksonLoop:
	xor %rax, %rax
	movq %rax, i(%rip)
top:
	cmp %rax, n(%rip)
	je bottom
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
	incq i(%rip)
	movq i(%rip), %rax
	jmp top
bottom:

	addq	$16, %rsp
	popq	%rbp
	retq
	
	xor %eax, %eax
	ret



