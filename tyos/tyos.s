	.file	"tyos.c"
	.code16gcc
	.text
	.section	.rodata
	.align 4
.LC0:
	.string	"Welcome to DrawOS! Here are the commands:\r\n\nW A S D: move the cursor\r\nU H J K: move the cursor but erasing\r\nQ: toggle fill mode\r\nE: toggle eraser mode\r\nESC: reset game\n"
.LC1:
	.string	"Press any key to start!"
	.text
	.globl	welcome
	.type	welcome, @function
welcome:
.LFB0:
	.cfi_startproc
	movl	$.LC0, %ecx
	call	print
	movl	$nl, %ecx
	call	print
	movl	$.LC1, %ecx
	call	print
	movl	$nl, %ecx
	call	print
#APP
# 36 "tyos.c" 1
	mov $0x0, %ah;int $0x16;call clear;ret;
# 0 "" 2
#NO_APP
	nop
	ud2
	.cfi_endproc
.LFE0:
	.size	welcome, .-welcome
	.globl	game
	.type	game, @function
game:
.LFB1:
	.cfi_startproc
#APP
# 49 "tyos.c" 1
	mov $0x0, %bh;mov $0x0, %dh;mov $0x0, %dl;mov $0x0, %ch;mov $0x0, %cl;jmp read_input22;pencil22:;cmp $0x1, %ch;je fill22;cmp $0x0, %ch;je do_nothing22;fill22:;mov $0x0e, %ah;mov $0x0, %si;mov $0x2a, %al;int $0x10;do_nothing22:;ret;eraser22:;mov $0x0e, %ah;mov $0x0, %si;mov $0x0, %al;int $0x10;ret;change_fill_flag22:;cmp $0x0, %ch;je false122;cmp $0x1, %ch;je true122;false122:;mov $0x1, %ch;mov $0x0, %cl;jmp read_input22;true122:;mov $0x0, %ch;jmp read_input22;change_eraser_flag22:;cmp $0x0, %cl;je false222;cmp $0x1, %cl;je true222;false222:;mov $0x1, %cl;mov $0x0, %ch;jmp read_input22;true222:;mov $0x0, %cl;jmp read_input22;go_up22:;sub $0x1, %dh;int $0x10;cmp $0x77, %al;je end_input_draw22;jmp end_input_erase22;go_down22:;add $0x1, %dh;int $0x10;cmp $0x73, %al;je end_input_draw22;jmp end_input_erase22;go_left22:;sub $0x1, %dl;int $0x10;cmp $0x61, %al;je end_input_draw22;jmp end_input_erase22;go_right22:;add $0x1, %dl;int $0x10;cmp $0x64, %al;je end_input_draw22;jmp end_input_erase22;put_char22:;mov $0x0e, %ah;mov $0x0, %si;cmp $0x0, %cl;je put_o22;cmp $0x1, %cl;je put_null22;put_o22:;mov $0x2a, %al;int $0x10;mov $0x2, %ah;int $0x10;jmp read_input22;put_null22:;mov $0x0, %al;int $0x10;mov $0x2, %ah;int $0x10;jmp read_input22;read_input22:;mov $0x2, %ah;int $0x10;mov $0x0, %ah;int $0x16;mov $0x2, %ah;cmp $0x77, %al;je go_up22;cmp $0x73, %al;je go_down22;cmp $0x61, %al;je go_left22;cmp $0x64, %al;je go_right22;cmp $0x75, %al;je go_up22;cmp $0x6a, %al;je go_down22;cmp $0x68, %al;je go_left22;cmp $0x6b, %al;je go_right22;cmp $0x71, %al;je change_fill_flag22;cmp $0x65, %al;je change_eraser_flag22;cmp $0x20, %al;je put_char22;cmp $0x1b, %al;je end_of_game22;jmp read_input22;end_input_draw22:;call pencil22;jmp read_input22;end_input_erase22:;call eraser22;jmp read_input22;end_of_game22:;ret;
# 0 "" 2
#NO_APP
	nop
	ud2
	.cfi_endproc
.LFE1:
	.size	game, .-game
	.globl	halt
	.type	halt, @function
halt:
.LFB2:
	.cfi_startproc
.L4:
	call	clear
	call	welcome
	call	game
	jmp	.L4
	.cfi_endproc
.LFE2:
	.size	halt, .-halt
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
