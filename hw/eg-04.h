/* Header file for eg-08.c */

#ifndef EG_04_H
#define EG_04_H

/* A function-like macro which prints a string named str using BIOS' 
   int 0x10 service. 

   Note that we can't pass a quoted literal string like "Foo"
   as argument of this macro, since the argument will be  literally  
   replaced as is within the asm code. Argument str should be a label,
   existing in the scope of the asm code.

   This macro clobbers registers eax, ebx and ecx.

 */

#define write_str(str) __asm__\
("\
        mov   $0x0e,%ah            \n\t \
        mov   $0x0, %bx            \n\t \
loop:                              \n\t \
        mov   " # str "(%bx), %al  \n\t \
        cmp   $0x0, %al            \n\t \
        je    end                  \n\t \
        int   $0x10                \n\t \
        add   $0x1, %bx            \n\t \
        jmp   loop                 \n\t \
end:                               \n\t \
")

/* A function-like macro which halts the system. 
 
   This function takes no arguments and does not clobber registers.

*/

#define halt() __asm__\
("\
  halt:               \n\t\
        hlt           \n\t\
        jmp   halt    \n\t\
")


#endif

/* Notes.

   We must be carefull with labels not to reuse symbols. Inline asm
   is copied into the output; if there is another label (e.g.
   function name) which the same name, that'd be a problem.

   Note the combination \n\t to split lines in a multi-line assembly 
   source code. This is because assemblers read LF-terminated lines
   and normally indent the next line with a tab character.
*/
