
/* A function-which prints pointed by str using BIOS' int 0x10 service. 

   We use fascall calling convention, which receives the argument in ecx.

   This function clobbers ax, bx, cx and si.
*/


void __attribute__((fastcall, naked))  write_str(const char* s)
{
__asm__
  ("\
        mov   %cx, %bx              \n\t \
	mov   $0x0e, %ah            \n\t \
	mov   $0x0, %si             \n\t \
 loop:			            \n\t \
	mov   (%bx, %si), %al       \n\t \
	cmp   $0x0, %al	            \n\t \
	je    end                   \n\t \
	int   $0x10	            \n\t \
	add   $0x1, %si	            \n\t \
	jmp   loop	            \n\t \
 end:                               \n\t \
      ret                           \n\t \
");
}

/* Halt. */

void __attribute__((naked)) halt()
{
__asm__					
("\
  halt:               \n\t\
	hlt           \n\t\
	jmp   halt    \n\t\
");
}

/* Notes.

   Function _start calls write_srt, and, by means of attribte fascall,
   we told it to pass its arguments via register cx (it's a convention.)

   Some caveats.

 - Again, we must be careful not to redefine labels.
 
 - In eg-04, the string location was identified by a label 'smsg', and 
   we could read it using 

     mov msg(%bx)

   Now the string position is given by a register. We can't use eg.

     %cx(%bx)

   One reason is because AT&T assembly uses the syntax

     (register_1, register_2)

   which means base and index, respoectively (the full statement
   allow more parameters, but this is suffices for now).

   Another reason, is that we can't use

    (%cx, %bx)

   simply because in 16-bit real mode we can't choose any registers
   for base and index respectively. We are limited to a few choices.

   (%bx, %si)

   is one of them. Indeed, that is why bx and si are referred to by 
   base  and index register, respectively.

   See ./README for more on this matter.

   If it feels to you that the hardware is kind of sadly inconsistent,
   that's because it is.  It's our duty as reckless system programs 
   to mask those idiosyncrasies out and simulate the idyllic illusion 
   of consistency and simplicity for innocents in userland.


 */
