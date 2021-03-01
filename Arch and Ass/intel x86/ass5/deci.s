    .data
N: .quad 0
i: .quad 0
    .text
    .global _main


_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

    xor %eax, %eax
    movq $0, i(%rip)

    xor %rbx, %rbx
	movq $23451241, N(%rip)
	
top:
                    #loop code

    mov N(%rip), %rax
    cmp $0, %rax
    jz bottom
    mov $0,  %rdx
    mov $10, %rbx
    div %rbx  
    mov %rax, N(%rip)

    add $'0', %rdx
    mov %rdx, %rdi
    push %rdi
    push %rdi
    incq i(%rip)
                     #loop code
	jmp top
bottom:

whileLoop:
    mov i(%rip), %rcx
    cmp $0, %rcx
    jz endofLoop
    pop %rdi
    pop %rdi

    call _putchar

    decq i(%rip)
    jmp whileLoop
endofLoop:

    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret