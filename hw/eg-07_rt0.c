/* eg-07_rt0.c - <one-line-description>

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

/* This symbol is defined in the linker script. */

extern void __END_STACK__;

/* Initialize stack. */

/* __asm__("movl $__END_STACK__ , %esp"); */


/* Call main and halt. 

   This is where main() returns to. Here we 

   This is how regular programs do e.g. in GNU/Linux operating system. */

void __attribute__((naked)) _start()
{
__asm__ volatile
  ("\
                mov  $__END_STACK__ , %%sp \n\t\
                call main                  \n\t\
     loop%=:                               \n\t\
                hlt                        \n\t\
                jmp loop%=                 \n\t\
   "
   :::
   );
}


/* Notes.

   Our rt0 file is not C with inline asm.

 */
