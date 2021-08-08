/* tyos.c - The tyOS function library.
 
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

#include <tyos.h>

#define DEBUG 0

void halt()
{
    clear();
    game();
	
}

void __attribute__((naked, fastcall)) game()
{

#if DEBUG    
    printnl("Welcome to DrawOS! Here are the commands:\r\n\n"
            "W A S D: move the cursor\r\n"
            "U H J K: move the cursor but erasing\r\n"
            "Q: toggle fill mode\r\n"
            "E: toggle eraser mode\r\n"
            "ESC: refresh\n");
    
    printnl("Press any key to start!");
#endif

#if !DEBUG
    __asm__ volatile
    (	
        "mov $0x0, %%bh;"
        "mov $0x0, %%dh;"
        "mov $0x0, %%dl;"
        "mov $0x2, %%ah;"
        "int $0x10;"
		"mov $0x1, %%ch;"
        "mov $0x0, %%cl;" // eraser mode
	 	"jmp draw_loop%=;"

	 	"pencil%=:;"
			"mov $0x0e, %%ah;"
            "mov $0x0, %%si;"
			"cmp $0x0, %%ch;"
			"je draw%=;"
		   	"cmp $0x1, %%ch;"
			"je do_nothing%=;"

			"draw%=:;"
				"mov $0x2a, %%al;"
				"int $0x10;"
			"do_nothing%=:;"
                "ret;"
                
        "eraser%=:;"
			"mov $0x0e, %%ah;"
            "mov $0x0, %%si;"
            "mov $0x0, %%al;"
			"int $0x10;"
            "ret;"

		"change_fill_flag%=:;"
			"cmp $0x0, %%ch;"
			"je false1%=;"
			"cmp $0x1, %%ch;"
			"je true1%=;"
				"false1%=:;"
					"mov $0x1, %%ch;"
                    "mov $0x0, %%cl;"
					"jmp read_input%=;"
				"true1%=:;"
					"mov $0x0, %%ch;"
					"jmp read_input%=;"
                    
        "change_eraser_flag%=:;"
			"cmp $0x0, %%cl;"
			"je false2%=;"
			"cmp $0x1, %%cl;"
			"je true2%=;"
				"false2%=:;"
					"mov $0x1, %%cl;"
                    "mov $0x1, %%ch;"
					"jmp read_input%=;"
				"true2%=:;"
					"mov $0x0, %%cl;"
					"jmp read_input%=;"
        

		"read_input%=:;"
			"mov $0x0, %%ah;"
			"int $0x16;"
			"mov $0x2, %%ah;"
            
			"cmp $0x77, %%al;"
            "je go_up%=;"
        	"cmp $0x73, %%al;"
        	"je go_down%=;"
        	"cmp $0x61, %%al;"
        	"je go_left%=;"
        	"cmp $0x64, %%al;"
        	"je go_right%=;"
            
            "cmp $0x75, %%al;"
            "je go_up%=;"
            "cmp $0x6a, %%al;"
            "je go_down%=;"
            "cmp $0x68, %%al;"
            "je go_left%=;"
            "cmp $0x6b, %%al;"
            "je go_right%=;"
            
			"cmp $0x71, %%al;"
			"je change_fill_flag%=;"
			"cmp $0x65, %%al;"
			"je change_eraser_flag%=;"
            
            "cmp $0x20, %%al;"
            "je put_char%=;"
            
            "cmp $0x1b, %%al;"
            "je clear_screen%=;"
            
			"jmp read_input%=;"
            
            "end_input_draw%=:;"
                "call pencil%=;"
                "jmp draw_loop%=;"
            
            "end_input_erase%=:;"
                "call eraser%=;"
                "jmp draw_loop%=;"
                
            "clear_screen%=:;"
                "call clear;"
                "mov $0x0, %%bh;"
                "mov $0x10, %%dh;"
                "mov $0x10, %%dl;"
                "mov $0x2, %%ah;"
                "int $0x10;"
                "mov $0x1, %%ch;"
                "mov $0x0, %%cl;" // eraser mode
                "jmp draw_loop%=;"

		"go_down%=:;"
    	    "add $0x1, %%dh;"
    	    "int $0x10;"
            "cmp $0x73, %%al;"
    	    "je end_input_draw%=;"
            "jmp end_input_erase%=;"

	    "go_up%=:;"
	        "sub $0x1, %%dh;"
	        "int $0x10;"
            "cmp $0x77, %%al;"
 	  		"je end_input_draw%=;"
            "jmp end_input_erase%=;"

	    "go_right%=:;"
	        "add $0x1, %%dl;"
	        "int $0x10;"
            "cmp $0x64, %%al;"
    	    "je end_input_draw%=;"
            "jmp end_input_erase%=;"

	    "go_left%=:;"
	        "sub $0x1, %%dl;"
	        "int $0x10;"
	        "cmp $0x61, %%al;"
    	    "je end_input_draw%=;"
            "jmp end_input_erase%=;"
            
        "put_char%=:;"
            "mov $0x0e, %%ah;"
            "mov $0x0, %%si;"
            "cmp $0x0, %%cl;"
            "je put_o%=;"
            "cmp $0x1, %%cl;"
            "je put_null%=;"
            
            "put_o%=:;"
                "mov $0x2a, %%al;"
                "int $0x10;"
                "mov $0x2, %%ah;"
                "int $0x10;"
                "jmp read_input%=;"
            
            "put_null%=:;"
                "mov $0x0, %%al;"
                "int $0x10;"
                "mov $0x2, %%ah;"
                "int $0x10;"
                "jmp read_input%=;"
            
		"draw_loop%=:;"
			"mov $0x2, %%ah;"
			"int $0x10;"
			"jmp read_input%=;"
			"jmp draw_loop%=;"
		
    :::"ax","bx","cx","dx"    
    );
	
#endif
}
