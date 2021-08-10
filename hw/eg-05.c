/* eg-05.c - <one-line-description>

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

#include <eg-05.h>

extern const char msg[];

void __attribute__((naked)) _start()   /* This will be a label in asm code. */
{

  init_stack();		    /* Needed for function calls (see eg-05.h) */
  
  write_str(msg);	    /* This will be a functional call in asm code. */

  halt();                   /* This will be a function call in asm code. */
}

/*  The string. */

const char msg[]  = "Hello world";



/* Notes

   This code looks like eg-04.c, but with function-like macros replaced 
   with actual function calls.

 */
