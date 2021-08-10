/*  Linker script for MBR. */

OUTPUT_FORMAT(binary)		/* Output flat binary (no structure) */
SECTIONS
{
        . = 0x7C00;		/* Line counter is now 0x7c00. */
        .text :
	{
	  *(.text)              /* Copy input section .text to the oputput. */
	  *(.rodata)		/* Copy input section .rodata to the output. */
	}	
        . = 0x7c00 + 510;	/* Advance 510 bytes. */
        .signature : 		/* Add a signadure section with this content. */
	{
	    BYTE(0x55)
            BYTE(0xAA)
        }
	__END_STACK__ = 0x7e00 + 0x200;	/* The end of a 64k block. */
}
STARTUP(eg-07_rt0.o);




