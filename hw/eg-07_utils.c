/* eg-07_utils.c - <one-line-description>

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

   This function clobbers eax, ebx, ecx and esi.
*/


void __attribute__((fastcall, naked))  puts(const char* s)
{
__asm__ volatile
("\
        mov   %w[str], %%bx         \n\t\
	mov   $0x0e, %%ah           \n\t\
	mov   $0x0, %%si            \n\t\
loop%=:	          		    \n\t\
	mov   (%%bx, %%si), %%al    \n\t\
	cmp   $0x0, %%al	    \n\t\
	je    end%=                 \n\t\
	int   $0x10	            \n\t\
	add   $0x1, %%si	    \n\t\
	jmp   loop%=	            \n\t\
end%=:                              \n\t\
        ret                         \n\t\
"
:				      /* No ouptut parameters. */
: [str] "b" (s)	                      /* Var. s put in bx, referenced as str.*/
: "ax", "cx", "si"       	      /* Clobbred registers (bx is input).   */
 );
}



/* Notes.

   Function 'int puts(const char *s)' of standard C and POSIX specifications
   returns the number of printed characters. Our version returns void.
   We shall address the return value of a fauction opportunely.

   Standard C and POSIX puts() write trailing newline also.

 */
