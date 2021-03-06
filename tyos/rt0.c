/* rt0.c - <one-line-description>

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

/* This is our program's entry point. */

void __attribute__((naked)) _start()
{
  __asm__ volatile
    (

     /* BIOS is not guaranteed to initialize all segemnt registers.
	We therefore do it manually. We assume all segments as zero.*/
     
     "        xorw %%ax, %%ax                ;" 
     "        movw %%ax, %%ds                ;" /* Zero data segment.    */
     "        movw %%ax, %%es                ;" /* Zero extra segment.   */
     "        movw %%ax, %%fs                ;" /* Zero extra segment 2. */
     "        movw %%ax, %%gs                ;" /* Zero extra segment 3. */
     "        movw %%ax, %%ss                ;" /* Zero stack segment.   */


     /* Configure the stack pointer. */
     
     "        mov $__END_STACK__, %%sp     ;" /* Setup stack */

     /* Call main. */

     "        call main                     ;" /* Call main */
     " loop%=:                              ;" 
     "        hlt                           ;" /* Halt. */
     "        jmp loop%=                    "
     
     :::
     );
}

/* Notes. */
