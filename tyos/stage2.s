	.file	"stage2.c"
	.code16gcc
	.text
	.section	.rodata
	.align 4
.LC0:
	.string	"Second stage loaded sucessuflly."
	.text
	.globl	init
	.type	init, @function
init:
.LFB0:
	.cfi_startproc
	movl	$.LC0, %ecx
	call	print
	movl	$nl, %ecx
	call	print
	call	halt
	nop
	ud2
	.cfi_endproc
.LFE0:
	.size	init, .-init
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
