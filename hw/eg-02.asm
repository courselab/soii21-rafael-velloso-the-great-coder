;  eg-02.asm - <one-line-description>

;  Copyright (c) 2021, Rafael Meliani Velloso <raf.velloso427@usp.br>

;  This file is part of soii21-rafael-velloso-the-great-coder

;  soii21-rafael-velloso-the-great-coder is free software: you can redistribute it and/or modify
;  it under the terms of the GNU General Public License as published by
;  the Free Software Foundation, either version 3 of the License, or
;  (at your option) any later version.
   
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU General Public License for more details.
   
;   You should have received a copy of the GNU General Public License
;   along with this program.  If not, see <http://www.gnu.org/licenses/>.

	;; Boot, say hello, and halt
	;; NASM assembly, neater version wit loop

	bits 16			; Set 16-bit mode
	
	org 0x7c00		; Our load address (alternative way)

	mov ah, 0xe		; BIOS tty mode

	mov bx, 0		; Offsets now handled via org directive
loop:				
	mov al, [msg + bx]	; Ofsset to the message
	cmp al, 0x0		; Loop while char is not 0x0 
	je halt			; Jump to halt
	int 0x10		; Call BIOS video interrupt
	add bx, 0x1		; Point to the next character
	jmp loop		; Repeat until we find a 0x0

halt:
	hlt			; Halt
	jmp halt		; Safeguard

msg:				; C-like NULL terminated string

	db 'Hello World', 0x0
	
	times 510 - ($-$$) db 0	; Pad with zeros
	dw 0xaa55		; Boot signature


	;; Notes
	;;
	;;  The org directive tells nasm where we intende to load the program.
	;;  The offset is now automatically applied wherever needed.
