/* <file> - <One-line note about this file>
 
   Copyright (c) 2021, Rafael Meliani Velloso <raf.velloso427@usp.br>

   This piece of software is a derivative work of SYSeg, by Monaco F. J.
   SYSeg is distributed under the license GNU GPL v3, and is available
   at the official repository https://www.gitlab.com/monaco/syseg.

   This file is part of <PROJECT>.

   <PROJECT> is free software: you can redistribute it and/or modify
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

void __attribute__((fastcall, naked)) move_cursor();

/* QUIT */
#define quit() printnl("Sorry...")

/* Move cursor */
#define MOVC_CMD "movc"

#define QUIT_CMD "quit"

#define PROMPT ">"

#define NOT_FOUND "command not found"

#endif	/* MBR_H */
