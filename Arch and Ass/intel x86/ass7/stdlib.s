.macro BeginProgram
        .text
        .global _main

    _main:

.endm

.macro EndProgram

    xor %eax, %eax
    ret
.endm

.macro ForLoop var start end
        .data
    \var: .quad 0
    End\var: .quad 0
        .text
        mov $\end, %rax
        mov %rax, End\var(%rip)
        mov $\start, %rax
        mov %rax, \var(%rip)
    Top\var:
        mov \var(%rip), %rax
        cmp %rax, End\var(%rip)
        je bottom\var
.endm

.macro Next var
        incq \var(%rip)
        jmp Top\var
    bottom\var:
.endm
