/* Header file for eg-05.c */

#ifndef EG_05_H
#define EG_05_H

/* A function-which prints pointed by str using BIOS' int 0x10 service. 

   Differently from eg-08.h's macro version, this function accepts 
   either a pointer to labeled string or an anonimous pointer for 
   a quoted literal string.

   This function clobbers eax, ebx, ecx and esi.

 */

void __attribute__((fastcall, naked))  write_str(const char* s);


/* An function which halts the system. 
 
   This function takes no arguments and does not clobber registers.

*/

void __attribute__((naked)) halt();


/* We we make function calls, we need to tell the cpu where to store the
   return address of the caller, so that the return instruction in the
   called function knows where to jump back to.

   In our case, this is informed in register %sp.

   More technically, this is the stack pointer but we shall go deeper 
   into this topic opportunely. 

   Let's take, for instance, 16 bytes right after the 512-byte MBR:

   LOAD_ADDRESS + 512 bytes + 16 bytes = 0x7e10

   Note: there is a much neater way of doing this, as we'll see soon.

   (This is not the key point here, but 16 bytes makes for 4 32-bit 
   entries, what allows for at most 4 return addresses. We are not
   ready for nested function calls, though. Anyway, if that's not 
   that clear by now, do not worry. We'll come back to it opportunely.)


*/

#define init_stack()  __asm__("mov $0x7e10, %sp") 


#endif

/* Notes.
   
   Function write_str() is implemented in eg-09_utils.c
*/
