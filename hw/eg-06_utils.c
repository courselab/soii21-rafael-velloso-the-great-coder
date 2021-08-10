
/* A function-which prints pointed by str using BIOS' int 0x10 service. 

   This function clobbers eax, ebx, ecx and esi.
*/

void __attribute__((fastcall, naked))  write_str(const char* s)
{
__asm__ volatile
("\
	mov   $0x0e, %%ah           \n\t\
	mov   $0x0, %%si            \n\t\
loop%=:	          		    \n\t\
	mov   (%%bx, %%si), %%al    \n\t\
	cmp   $0x0, %%al	    \n\t\
	je    end%=                 \n\t\
	int   $0x10	            \n\t\
	add   $0x1, %%si	    \n\t\
	jmp   loop%=	            \n\t\
end%=:                              \n\t\
        ret                         \n\t\
"
:				      /* No ouptut parameters. */
: [str] "b" (s)	                      /* Var. s put in bx, referenced as str.*/
: "ax", "cx", "si"       	      /* Clobbred registers (bx is input).   */
 );
}

/* Halt. */

void __attribute__((naked)) halt()
{
__asm__					
("\
  halt%=:             \n\t\
	hlt           \n\t\
	jmp   halt    \n\t\
"
 :::
 );
}


/* Notes.

   This code uses GCC extende assembly.
  
   Register %reg is denoted %%reg
      
   The input parameter specifies that the C variable s should be copied into
   register b, and referenced in the code by str --- we therefore don't need 
   to mind that s is being received in ecx via function call.

   The line

        movw  %w[str], %%bx
   
    references str and the constraint %w tells the assembler that we want to
    operate on 16-bit register (therefor it should use bx).

    Token %= outputs a symbol which is unique in the entire compilation.
    This frees us from the risk of using the same label in another asm code
    in the same compilation unit.

    The last line informs GCC that the registers ax, cx, dx and si are 
    clobbered by this asm code. That bx is also clobbered GCC already 
    knows because bx is mentioned in the input/output parameter list.

    In extended asm GCC can modify the code. We used volatile qualifier
    to prevent optimization.

 */
