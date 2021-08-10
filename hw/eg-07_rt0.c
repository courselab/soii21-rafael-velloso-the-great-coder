
/* This symbol is defined in the linker script. */

extern void __END_STACK__;

/* Initialize stack. */

/* __asm__("movl $__END_STACK__ , %esp"); */


/* Call main and halt. 

   This is where main() returns to. Here we 

   This is how regular programs do e.g. in GNU/Linux operating system. */

void __attribute__((naked)) _start()
{
__asm__ volatile
  ("\
                mov  $__END_STACK__ , %%sp \n\t\
                call main                  \n\t\
     loop%=:                               \n\t\
                hlt                        \n\t\
                jmp loop%=                 \n\t\
   "
   :::
   );
}


/* Notes.

   Our rt0 file is not C with inline asm.

 */
