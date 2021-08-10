/* Header file for eg-06.c */

#ifndef EG_06_H
#define EG_06_H

/* A function-which prints pointed by str using BIOS' int 0x10 service. 
   This function clobbers eax, ebx, ecx and esi.
 */

void __attribute__((fastcall, naked))  write_str(const char* s);


/* A function which halts the system. 
   This function takes no arguments and does not clobber registers.*/

void __attribute__((naked)) halt();


/* Initialize stack. */


#define init_stack()  __asm__("mov $0x7e10, %sp") 


#endif

/* Notes.
   
   Function write_str() is implemented in eg-06_utils.c
*/
