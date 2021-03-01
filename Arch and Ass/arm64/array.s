    .data
ar:                 //array[10]
    .rept 10
    .quad 0
    .endr

    .text
    .global main
main:
    stp     x29, x30, [sp, -16]!
    add     x29, sp, #0

    ldr     x1, =ar
check:
    mov     x2, #2                  //place were looking at in array (2)
    add     x3, x1, x2, lsl #3      //moving to location of ar[2] (moving 2^3 bits [8 bytes] through array)
check2:
    mov     x0, #10                 //put a 10 into ar[2]
    str     x0, [x3]                //ar[2] = 10


.macro binTree
    .data
value\@:    .quad 0 // \@ makes it have a counter so we know how many times it's been visited {{{value2 @ binTree[2]}}}
left\@:     .quad 0
right\@:    .quad 0 //l and r pointer
pad\@:      .quad 0 //need a a pad so it's a power of 2 (2^5= 32 bytes)
    .text
.endm

treeNode:           //creates treeNode[10]
    .rept   10
    binTree
    .endr

    .text
    ldr     x1, =treeNode
    mov     x2, #2
    add     x3, x1, x2, lsl #5      //NOW SHIFTING BY 32*2 FOR binTree SIZE, gets location 64 bits later for binTree[2]
    mov     x0, #10
    str     x0, [x3]                //put that into the location (treeNode[2].value = 10)
    mov     x0, #0
    add     x4, x3, #8              //mov to treeNode[2].left __ALSO__ -> x3 holds intial treeNode[2] 
    str     x0, [x4]                //put 0 into treeNode[2].left = 0
    add     x4, x3, #16
    str     x0, [x4]                //go to treeNode[2].right = 0

    mov     w0, #0
    ldp     x29, x30, [sp], 16
    ret