    .data
N: .quad 0
low: .quad 0
high: .quad 0
guess: .quad 0
i: .quad 0
    .text
    .global _main


_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
#

    mov $169, %rdi

sqrt:
    mov %rdi, N(%rip)
    mov %rdi, high(%rip)
    xor %rax, %rax
    mov %rax, low(%rip)
topsqrt:
    mov low(%rip), %rax
    add high(%rip), %rax
    shr $1, %rax
    mov %rax, guess(%rip)
    mov low(%rip), %rcx
    inc %rcx
    cmp %rcx, high(%rip)
    je done
    mul %rax
    cmp N(%rip), %rax
    je done
    jg replaceHigh
replaceLow:
    mov guess(%rip), %rbx
    mov %rbx, low(%rip)
    jmp topsqrt
replaceHigh:
    mov guess(%rip), %rbx
    mov %rbx, high(%rip)
    jmp topsqrt
done:

top:
                    #loop code

    mov guess(%rip), %rax
    cmp $0, %rax
    jz bottom
    mov $0,  %rdx
    mov $10, %rbx
    div %rbx  
    mov %rax, guess(%rip)

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

#
    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret