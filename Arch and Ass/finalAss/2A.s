
    .data
Total: .long 0xffe7
mask: .long (32 numbers long) //-> Psuedo code... i forget the hex number (10000000...)
i: .quad 0
j: .quad 32
    .text

StartProgram

top:
    ldr x3, =j
    ldr x4, [x3]
    ldr x1, =i
    ldr x2, [x1]
    cmp x4, x2
    bz bottom

    ldr r1, =Total
    ldr r2, [r1]
    ldr r3, =mask
    ldr r4, [r3]

    ands r5, r4, r2  //-> I belive s gives us the flag
    lsr r4, r4, #1   //-> we move that 1 one spot over
    str r4, [r3]

    beq zero
    add w0, #'1'
    b done
zero:
    add w0, #'0'
done:
    bl putchar

    ldr x1, =i
    ldr x2, [x1]
    add x2, x2, #1
    str x2, [x1]
    b top
bottom:

EndProgram