/* stage1.c - <one-line-description>

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


#include <tyos.h>

void(* init)(void) = ((void *) STAGE2_ADDR);

int main()
{
  clear();
  printnl ("TyOS - A really tiny OS.");

  load_stage2_block();

  init(); 			/* This is a call to stage2 adddress */
  
  return 0;
}
