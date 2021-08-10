/* Boot, say hello and halt. 
   Using macro-like functions, with some hacks.
*/

#include <eg-04.h>

extern const char msg[];

 
void __attribute__((naked)) _start()   /* This will be a label in asm code. */
{
  
  write_str(msg);	    /* This will be relaced with inline asm code. */

  halt();                   /* This will be relaced with inline asm code. */
}

/*  The string, with a hack to allocate it in the same section (.text). */

const char __attribute__((section(".text#"))) msg[]  = "Hello world";

/* The boot signature. */

__asm__(". = _start + 510");                /* Pad with zeros */
__asm__(".byte 0x55, 0xaa");                /* Boot signature  */


/* Notes

   Macros write_str() and halt() are defined in eg-04.h.

   Asm statements inside __asm__() are ouput as are.

   The attribute 'naked' is used to prevent GCC from generating extra asm
   code that we don't need in our example, and can be safely discarded for
   easy of readability. This extra code is normally important for implementing
   consistent memory utilization across functions which exchange data using
   the memory stack (a memory region which programs use to pop and push
   data when they need). This is not the case of our simple program and we
   therefore may safely get along without it for now. We should get back 
   to this topic opportunely.


   The naked attribute is to prevent gcc from generating

   A caveat is in order here:

 - The compiler will allocate the executable code in the section .text
   of the assembly code. By default, it would allocate the string in
   the read-only data (.rodata) section.  The problem is, the assembler
   computes offsets relatively to the start of the current section.   

   The attribute in the declaration of msg forces the compiler to allocate
   the string in the designated section.

   And the hack does not ends there. If we write '.text' as the
   argument of the attribute specification, GCC will append a '.a'
   after it, such that the string will be in section '.text.a' Not what
   we need.  We therefore specify '.text#' as a way to fool GCC:
   it will output '.text#.a'.  But '#' happens to be a comment mark
   for the the assembler, which will read just '.text' as we'd like.
   
   If this source looks like hackery to you, that's because it is. 
   
   Welcome to system level programming.


 */
