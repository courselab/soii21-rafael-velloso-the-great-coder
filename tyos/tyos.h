/* mbr.h -  MbrCmd command
 
   Copyright (c) 2021, Monaco F. J. <monaco@usp.br>

   This file is part of SYSeg.

   SYSeg is free software: you can redistribute it and/or modify
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

#ifndef TOS_H
#define TOS_H

#define STAGE2_ADDR 0x7e00

#define VIDEO_MEMORY 0xb8000
#define VIDEO_ATTRIBUTE 0X02

/* Print string str on standard output. */

void __attribute((naked, fastcall)) print (const char *str);

/* Print string str on standard output, with a newline. */

extern char nl[];

#define printnl(str) do{print(str); print (nl);}while(0)

/* Clear the screen. */

void __attribute__((naked, fastcall)) clear (void);

/* Read standard input into buffer. */

void __attribute__((naked, fastcall)) read (char *buffer);

/* Prints a help message. */

void __attribute__((naked)) help (void);

/* Compare to strings up to BUFFER_MAX_LENGTH-1. */

#define BUFFER_MAX_LENGTH 5

int __attribute__((fastcall, naked)) compare (char *s1, char *s2);

/* Load stage 2 as a block. */

void load_stage2_block();

#define PROMPT ">"

/* Halt. */

void halt();


#endif
