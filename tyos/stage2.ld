/* stage2.ld - <one-line-description>

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

/*  Linker script. */

OUTPUT_FORMAT(binary)		/* Output flat binary (no structure) */
SECTIONS
{
        . = 0x7e00;		/* Line counter is now 0x7c00. */
        .text :
	{
	  *(.text)              /* Copy input section .text to the oputput. */
	  *(.data)		/* Copy input section .data to the output. */
	  *(.bss)		/* Copy input section .bss to the output. */
	  *(.rodata)		/* Copy input section .rodata to the output. */
	}
}
