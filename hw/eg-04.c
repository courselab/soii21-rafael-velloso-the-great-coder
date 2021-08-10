/* eg-04.c - <one-line-description>

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

/* Boot, say hello and halt. 
   Using macro-like functions, with linkder script.
*/

#include <eg-04.h>

extern const char msg[];

 
void __attribute__((naked)) _start()   /* This will be a label in asm code. */
{
  
  write_str(msg);	    /* This will be relaced with inline asm code. */

  halt();                   /* This will be relaced with inline asm code. */
}

/*  The string. */

const char msg[]  = "Hello world";



/* Notes

   We use a linker script to handle several issues:

   - merge .rodata into .text section  (don't need the hack on msg)
   - add the the boot signature        (don't need inline asm)
   - covert from elf to binary         (don't need ld command-line option)
   - set load address                  (don't need ld command-line option)
   - entry point                       (don't need ld command-line option)

   If this source looks less a hackery now, that's because of our might tools!
   
   Thanks GNU build toolchain.


 */
