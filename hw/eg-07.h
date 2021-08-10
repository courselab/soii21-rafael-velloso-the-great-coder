/* Header file for eg-07.c */

#ifndef EG_07_H
#define EG_07_H

/* Prints string pointed by s using BIOS' int 0x10 service. */

void __attribute__((fastcall, naked))  puts(const char* s);

#endif

/* Notes.
   
   Both puts and exit are now functions implemented in eg-10_utils.c.

   We should be careful not to clash names with libc.

*/
