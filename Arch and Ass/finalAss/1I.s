
    .data
N:  .long 0
current: .long 0
Total: .long 0
i:  .long 0
temp .long 0
    .text

StartProgram

    xor %eax, %eax
    mov $10, %eax
    mov %eax, N(%rip)
    xor %ecx, %ecx
    mov $0, %ecx
    mov %ecx, current(%rip)
top:
    mov N(%rip), %eax
    mov current(%rip), %ecx
    cmp %ecx, %eax
    jz bottom

    cmp %ecx, $0        #accounts for 2^0
    jg next
    mov $1, %eax
    jmp done
next:
    xor %edx, %edx
    mov %edx, i(%rip)
    xor %eax, %eax
    mov $1, %eax
    mov %eax, temp(%rip)
square:
    mov i(%rip), %edx
    mov current(%rip), %ecx
    cmp %edx, %ecx
    jz squareBottom

    mov temp(%rip), %eax
    mul $2              #eax = eax * 2 (eax stars holding 1. So, 1*2=2, then 2*2=4, then 4*2=8 for 2^3)
    mov %eax, temp(%rip)
    mov i(%rip), %edx
    inc %edx
    mov %edx, i(%rip)
    jmp square
squareBottom:

done:
    xor %edx, %edx
    xor %eax, %eax
    mov Total(%rip), %edx
    mov temp(%rip), %eax
    add %eax, %edx       #now, eax = eax (temp number) + edx (total)
    mov %eax, Total(%rip)

    mov current(%rip), %ecx
    inc %ecx
    mov %ecx, current(%rip)
bottom:

EndProgram