    .data
N: .long 0
Total: .long 0

    .text
    .global _main

#val = 3*(n*(n+1))/2 is the goal for algorythm

_main: 
    pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
Begin:
    xor %rax, %rax
    xor %rdx, %rdx
    mov $4, %eax
    mov %eax, N(%rip)

    inc %eax
    mov N(%rip), %edx
    mul %edx
    mov $2, %ebx
    div %ebx

    mov $3, %edx
    mul %edx
    mov %eax, Total(%rip)
End:
    addq	$16, %rsp
	popq	%rbp
	retq

	xor %eax, %eax
	ret