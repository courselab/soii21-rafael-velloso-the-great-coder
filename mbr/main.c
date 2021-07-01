/* main.c - Main program of MbrCmd
 
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


#include <mbr.h>

int main()
{
  char cmd[BUFFER_MAX_LENGTH];

  /* Clear screen. */
  
  clear();

  /* Main loop. */
  
  while (1)
    {
  
      print (PROMPT);		        /* Show prompt. */

      read (cmd);		        /* Read user command. */

      /* Process user command. */
      
      if (compare(cmd, HELP_CMD))       /* Command help. */
	help();
      else if (compare(cmd, QUIT_CMD))  /* Command quit. */
	quit();
      else
	{
	  print (cmd);		        /* Unkown command. */
	  printnl (NOT_FOUND);
	}
    }
  
  return 0;

}
