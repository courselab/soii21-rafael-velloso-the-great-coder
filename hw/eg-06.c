/* Boot, say hello and halt. 
   Using extended assembly.
*/

#include <eg-06.h>

extern const char msg[];

 
void __attribute__((naked)) _start()   /* This will be a label in asm code. */
{
  
  init_stack();		    /* Needed for function calls (see eg-05.h) */

  write_str(msg);	    /* This will be a functional call in asm code. */

  halt();                   /* This will be a function call in asm code. */
}

/*  The string. */

const char msg[]  = "Hello world";



/* Notes

   This code looks like eg-06.c, but functions are implemented with
   GCC's extended inline assembly.

 */
