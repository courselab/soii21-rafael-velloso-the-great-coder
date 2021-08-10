#  eg-03.S - <one-line-description>

#  Copyright (c) 2021, Rafael Meliani Velloso <raf.velloso427@usp.br>

#  This file is part of soii21-rafael-velloso-the-great-coder

#  soii21-rafael-velloso-the-great-coder is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
   
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
   
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.

	## Boot, say hello, and halt
	## AT&T assembly, translated from NASM
	
	.code16                # Set 16-bit code
	
	.global _start	       # Linker's default entry point
	
_start:		               # Program beginning 
	
	movb  $0xe, %ah	       # BIOS tty mode
	
	movw  $0x0, %bx	       # Using linker's org flag
loop:			      
	movb  msg(%bx), %al    # Offset to the message
	cmp   $0x0, %al	       # Loop while char is not 0x0
	je    halt             # Jump to halt
	int   $0x10	       # Call bios
	add   $0x1, %bx	       # Point to the next character
	jmp   loop	       # Repeat until we find a 0x0
	
halt:
	hlt		       # Halt
	jmp   halt	       # Safeguard

msg:			       # C-like NULL terminated string

	.string    "Hello World"
	
	.fill 510 - (. - _start), 1, 0       # Pad with zeros
	.word 0xaa55			     # Boot signature


	# Notes
	#
	# By default, the linker will consider _start the entry point.
	
