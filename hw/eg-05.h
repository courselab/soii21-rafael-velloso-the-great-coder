/* eg-05.h - <one-line-description>

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

/* Header file for eg-05.c */

#ifndef EG_05_H
#define EG_05_H

/* A function-which prints pointed by str using BIOS' int 0x10 service. 

   Differently from eg-08.h's macro version, this function accepts 
   either a pointer to labeled string or an anonimous pointer for 
   a quoted literal string.

   This function clobbers eax, ebx, ecx and esi.

 */

void __attribute__((fastcall, naked))  write_str(const char* s);


/* An function which halts the system. 
 
   This function takes no arguments and does not clobber registers.

*/

void __attribute__((naked)) halt();


/* We we make function calls, we need to tell the cpu where to store the
   return address of the caller, so that the return instruction in the
   called function knows where to jump back to.

   In our case, this is informed in register %sp.

   More technically, this is the stack pointer but we shall go deeper 
   into this topic opportunely. 

   Let's take, for instance, 16 bytes right after the 512-byte MBR:

   LOAD_ADDRESS + 512 bytes + 16 bytes = 0x7e10

   Note: there is a much neater way of doing this, as we'll see soon.

   (This is not the key point here, but 16 bytes makes for 4 32-bit 
   entries, what allows for at most 4 return addresses. We are not
   ready for nested function calls, though. Anyway, if that's not 
   that clear by now, do not worry. We'll come back to it opportunely.)


*/

#define init_stack()  __asm__("mov $0x7e10, %sp") 


#endif

/* Notes.
   
   Function write_str() is implemented in eg-09_utils.c
*/
