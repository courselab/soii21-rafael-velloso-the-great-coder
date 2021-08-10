	.file	"stage1.c"
	.code16gcc
	.text
	.globl	init
	.data
	.align 4
	.type	init, @object
	.size	init, 4
init:
	.long	32256
	.section	.rodata
.LC0:
	.string	"TyOS - A really tiny OS."
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	clear
	movl	$.LC0, %ecx
	call	print
	movl	$nl, %ecx
	call	print
	call	load_stage2_block
	movl	init, %eax
	call	*%eax
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
