/* eg-06.h - <one-line-description>

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

/* Header file for eg-06.c */

#ifndef EG_06_H
#define EG_06_H

/* A function-which prints pointed by str using BIOS' int 0x10 service. 
   This function clobbers eax, ebx, ecx and esi.
 */

void __attribute__((fastcall, naked))  write_str(const char* s);


/* A function which halts the system. 
   This function takes no arguments and does not clobber registers.*/

void __attribute__((naked)) halt();


/* Initialize stack. */


#define init_stack()  __asm__("mov $0x7e10, %sp") 


#endif

/* Notes.
   
   Function write_str() is implemented in eg-06_utils.c
*/
