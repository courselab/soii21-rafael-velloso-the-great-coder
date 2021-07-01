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

#ifndef MBR_H
#define MBR_H

/* 
 *  Core functions.
 */

/* Print the null-terminated buffer on standard output. */

void __attribute((naked, fastcall)) print (const char *buffer);

/* Print the null-terminated string buffer on standard output, and a newline.*/

extern char nl[];

#define printnl(str) do{print(str); print (nl);}while(0)

/* Clear the screen. */

void __attribute__((naked, fastcall)) clear (void);

/* Read standard input into fixed-length buffer (no check). */

void __attribute__((naked, fastcall)) read (char *buffer);

/* Compare to strings up to BUFFER_MAX_LENGTH-1. */

#define BUFFER_MAX_LENGTH 5

int __attribute__((fastcall, naked)) compare (char *s1, char *s2);

/* 
 * Commands.
 */

/* Prints a help message. */

#define HELP_CMD "help"

void __attribute__((naked)) help (void);

/* Quit. */

#define QUIT_CMD "quit"

#define quit() printnl("Sorry...")

#define PROMPT ">"

#define NOT_FOUND "command not found"

#endif	/* MBR_H */
