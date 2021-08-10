/* tyos.c - the TyOS function library

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

#define DEBUG 0

void  __attribute__((naked)) welcome()
{
    printnl("Welcome to DrawOS! Here are the commands:\r\n\n"
            "W A S D: move the cursor\r\n"
            "U H J K: move the cursor but erasing\r\n"
            "Q: toggle fill mode\r\n"
            "E: toggle eraser mode\r\n"
            "ESC: reset game\n");
    
    printnl("Press any key to start!");
    
    __asm__ volatile 
    (
        "mov $0x0, %%ah;"
        "int $0x16;"
        "call clear;"
        "ret;"
        :::"ax"
    );
}

void __attribute__((naked, fastcall)) game()
{   
#if !DEBUG
    __asm__ volatile
    (
        // sets cursor position to (0,0)
        "mov $0x0, %%bh;"
        "mov $0x0, %%dh;"
        "mov $0x0, %%dl;"

        "mov $0x0, %%ch;" // fill flag (starts with false)
        "mov $0x0, %%cl;" // eraser flag (starts with false)

        "jmp read_input%=;" // jumps to main loop
    
        // decides whether or not to draw when moving cursor (depending on fill flag)
        "pencil%=:;"
            "cmp $0x1, %%ch;"
            "je fill%=;"
            "cmp $0x0, %%ch;"
            "je do_nothing%=;"

            "fill%=:;"
                "mov $0x0e, %%ah;"
                "mov $0x0, %%si;"
                "mov $0x2a, %%al;"
                "int $0x10;"
            "do_nothing%=:;"
                "ret;"
        
        // prints a '\0' char at current position (erases)
        "eraser%=:;"
            "mov $0x0e, %%ah;"
            "mov $0x0, %%si;"
            "mov $0x0, %%al;"
            "int $0x10;"
            "ret;"
        
        // changes fill flag (from false to true or vice-versa)
        "change_fill_flag%=:;"
            "cmp $0x0, %%ch;" // checks if false
            "je false1%=;"
            "cmp $0x1, %%ch;" // checks if true
            "je true1%=;"
            
            "false1%=:;"
                "mov $0x1, %%ch;" // fill flag becomes true
                "mov $0x0, %%cl;" // eraser flag becomes false
                "jmp read_input%=;"
            "true1%=:;"
                "mov $0x0, %%ch;" // fill flag becomes false
                "jmp read_input%=;"
        
        // changes eraser flag (from false to true or vice-versa)
        "change_eraser_flag%=:;"
            "cmp $0x0, %%cl;" // checks if false
            "je false2%=;"
            "cmp $0x1, %%cl;" // checks if true
            "je true2%=;"
            
            "false2%=:;"
                "mov $0x1, %%cl;" // eraser flag becomes true
                "mov $0x0, %%ch;" // fill flag becomes false
                "jmp read_input%=;"
            "true2%=:;"
                "mov $0x0, %%cl;" // eraser flag becomes false
                "jmp read_input%=;"
        
        // moves cursor UP
        "go_up%=:;"
            "sub $0x1, %%dh;"
            "int $0x10;"
            "cmp $0x77, %%al;" // W
            "je end_input_draw%=;"
            "jmp end_input_erase%=;"
        
        // moves cursor DOWN
        "go_down%=:;"
            "add $0x1, %%dh;"
            "int $0x10;"
            "cmp $0x73, %%al;" // S
            "je end_input_draw%=;"
            "jmp end_input_erase%=;"
        
        // moves cursor LEFT
        "go_left%=:;"
            "sub $0x1, %%dl;"
            "int $0x10;"
            "cmp $0x61, %%al;" // A
            "je end_input_draw%=;"
            "jmp end_input_erase%=;"
        
        // moves cursor RIGHT
        "go_right%=:;"
            "add $0x1, %%dl;"
            "int $0x10;"
            "cmp $0x64, %%al;" // D
            "je end_input_draw%=;"
            "jmp end_input_erase%=;"
        
        // prints a '*' or a '\0' character (depending on eraser flag)    
        "put_char%=:;"
            "mov $0x0e, %%ah;"
            "mov $0x0, %%si;"

            // checks eraser flag
            "cmp $0x0, %%cl;"
            "je put_o%=;"
            "cmp $0x1, %%cl;"
            "je put_null%=;"
            
            // prints '*'
            "put_o%=:;"
                "mov $0x2a, %%al;"
                "int $0x10;"
                "mov $0x2, %%ah;" // moves cursor
                "int $0x10;"
                "jmp read_input%=;"

            // prints '\0'
            "put_null%=:;"
                "mov $0x0, %%al;"
                "int $0x10;"
                "mov $0x2, %%ah;" // moves cursor
                "int $0x10;"
                "jmp read_input%=;"
        
        // MAIN LOOP
        "read_input%=:;"
        
            "mov $0x2, %%ah;"
            "int $0x10;"
            
            // reads input from keyboard
            "mov $0x0, %%ah;"
            "int $0x16;"
            
            "mov $0x2, %%ah;"
            
            "cmp $0x77, %%al;" // W
            "je go_up%=;"
            "cmp $0x73, %%al;" // S
            "je go_down%=;"
            "cmp $0x61, %%al;" // A
            "je go_left%=;"
            "cmp $0x64, %%al;" // D
            "je go_right%=;"
            
            "cmp $0x75, %%al;" // U
            "je go_up%=;"
            "cmp $0x6a, %%al;" // J
            "je go_down%=;"
            "cmp $0x68, %%al;" // H
            "je go_left%=;"
            "cmp $0x6b, %%al;" // K
            "je go_right%=;"
            
            // changes flags
            "cmp $0x71, %%al;" // Q
            "je change_fill_flag%=;"
            "cmp $0x65, %%al;" // E
            "je change_eraser_flag%=;"
            
            // draws or erases a char (depending on eraser flag)
            "cmp $0x20, %%al;" // SPACE
            "je put_char%=;"
            
            // resets game
            "cmp $0x1b, %%al;" // ESC
            "je end_of_game%=;"
            
            "jmp read_input%=;"
            
            // draws or not after moving cursor (depending on fill flag)
            "end_input_draw%=:;"
                "call pencil%=;"
                "jmp read_input%=;"
            
            // erases after moving cursor
            "end_input_erase%=:;"
                "call eraser%=;"
                "jmp read_input%=;"
        
        "end_of_game%=:;"
            "ret;"
            
    :::"ax","bx","cx","dx"    
    );
#endif
}

void __attribute__((naked, fastcall)) halt()
{
    while(1)
    {
        clear();
        welcome();
        game();
    }
}

