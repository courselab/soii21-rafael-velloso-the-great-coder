/* Boot, say hello and halt. 
   Using macro-like functions, with linkder script.
*/

#include <eg-04.h>

extern const char msg[];

 
void __attribute__((naked)) _start()   /* This will be a label in asm code. */
{
  
  write_str(msg);	    /* This will be relaced with inline asm code. */

  halt();                   /* This will be relaced with inline asm code. */
}

/*  The string. */

const char msg[]  = "Hello world";



/* Notes

   We use a linker script to handle several issues:

   - merge .rodata into .text section  (don't need the hack on msg)
   - add the the boot signature        (don't need inline asm)
   - covert from elf to binary         (don't need ld command-line option)
   - set load address                  (don't need ld command-line option)
   - entry point                       (don't need ld command-line option)

   If this source looks less a hackery now, that's because of our might tools!
   
   Thanks GNU build toolchain.


 */
