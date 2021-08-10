/* Boot, say hello and halt. 
   Using macro-like functions, with linkder script.
*/

#include <eg-05.h>

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

   This code looks like eg-04.c, but with function-like macros replaced 
   with actual function calls.

 */
