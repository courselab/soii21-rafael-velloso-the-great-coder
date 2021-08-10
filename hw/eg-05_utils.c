/* eg-05_utils.c - <one-line-description>

   Copyright (c) 2021, Rafael Meliani Velloso <raf.velloso427@usp.br>

   This file is part of soii21-rafael-velloso-the-great-coder

   soii21-rafael-velloso-the-great-coder is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/* A function-which prints pointed by str using BIOS' int 0x10 service. 

   We use fascall calling convention, which receives the argument in ecx.

   This function clobbers ax, bx, cx and si.
*/

void __attribute__((fastcall, naked))  write_str(const char* s)
{
__asm__
  ("\
        mov   %cx, %bx              \n\t \
	mov   $0x0e, %ah            \n\t \
	mov   $0x0, %si             \n\t \
 loop:			            \n\t \
	mov   (%bx, %si), %al       \n\t \
	cmp   $0x0, %al	            \n\t \
	je    end                   \n\t \
	int   $0x10	            \n\t \
	add   $0x1, %si	            \n\t \
	jmp   loop	            \n\t \
 end:                               \n\t \
      ret                           \n\t \
");
}

/* Halt. */

void __attribute__((naked)) halt()
{
__asm__					
("\
  halt:               \n\t\
	hlt           \n\t\
	jmp   halt    \n\t\
");
}

/* Notes.

   Function _start calls write_srt, and, by means of attribte fascall,
   we told it to pass its arguments via register cx (it's a convention.)

   Some caveats.

 - Again, we must be careful not to redefine labels.
 
 - In eg-04, the string location was identified by a label 'smsg', and 
   we could read it using 

     mov msg(%bx)

   Now the string position is given by a register. We can't use eg.

     %cx(%bx)

   One reason is because AT&T assembly uses the syntax

     (register_1, register_2)

   which means base and index, respoectively (the full statement
   allow more parameters, but this is suffices for now).

   Another reason, is that we can't use

    (%cx, %bx)

   simply because in 16-bit real mode we can't choose any registers
   for base and index respectively. We are limited to a few choices.

   (%bx, %si)

   is one of them. Indeed, that is why bx and si are referred to by 
   base  and index register, respectively.

   See ./README for more on this matter.

   If it feels to you that the hardware is kind of sadly inconsistent,
   that's because it is.  It's our duty as reckless system programs 
   to mask those idiosyncrasies out and simulate the idyllic illusion 
   of consistency and simplicity for innocents in userland.


 */
