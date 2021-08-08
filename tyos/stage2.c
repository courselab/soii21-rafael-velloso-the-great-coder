
#include <tyos.h>

void __attribute__((naked)) init()
{
  printnl ("Second stage loaded sucessuflly.");

  /* Here we may call functions from tyos.c. */
  
  halt();			/* Halt the system. */
}

