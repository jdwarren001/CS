
    .data
N:  .long 0
current: .long 0
Total: .long 0
i:  .long 0
temp .long 0
    .text

StartProgram

    ldr r1, =N
    mov r2, #10
    str r2, [r1]
top:
    ldr r1, =N
    mov r2, [r1]
    ldr r3, =current
    mov r4, [r3]
    cmp r4, r2
    beq bottom

    cmp r4, #0
    bg next         //branch to next if greater than 0, to account for 2^0
    mov r8, #1
    b done
next:
    ldr r5, =i
    mov r5, #0
    str r5, [r5]
    ldr r6, =temp
    mov r6, #1
    str r6, [r6]
square:
    ldr r5, =i
    ldr r5, [r5]
    ldr r3, =current
    ldr r4, [r3]
    cmp r4, r5
    beq squareBottom

    ldr r6, =temp
    ldr r8, [r6]
    mul r8, r8, #2      //now, same method as intel but r6 = r6 * 2 where r6 = prev number (ie. 2, 4, 8...)
    str r8, [r6]

    ldr r5, =i
    ldr r5, [r5]
    add r5, r5, #1
    str r5, [r5]
    b square
squareBottom:

done:
    ldr r9, =Total
    ldr r10, [r9]
    ldr r6, =temp
    ldr r8, [r6]
    add r10, r10, r8
    str r10, [r9]

    ldr r3, =current
    mov r4, [r3]
    add r4, r4, #1
    str r4, [r3] 
    b top
bottom:

EndProgram