    .data
Total: .long 0x33
i: .quad 0
u: .quad 0
    .text
    .global _main

_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

Begin:
    xor %rax, %rax
    xor %rdi, %rdi
    mov Total(%rip), %eax       #32 bit location for Total
    movq $0, i(%rip)
    movq $32, u(%rip)
top:
    mov i(%rip), %rcx
    cmp %rcx, u(%rip)
    jz bottom

    shl $1, %eax
    jc carry1
carry0:
    mov $'0', %rdi
    push %rax
    push %rax
    call _putchar
    pop %rax
    pop %rax
    jmp binaryEnd
carry1:
    mov $'1', %rdi
    push %rax
    push %rax
    call _putchar
    pop %rax
    pop %rax
binaryEnd:

    incq i(%rip)
    jmp top
bottom:

End:
    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret