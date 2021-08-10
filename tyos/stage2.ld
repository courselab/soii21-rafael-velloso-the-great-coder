/*  Linker script. */

OUTPUT_FORMAT(binary)		/* Output flat binary (no structure) */
SECTIONS
{
        . = 0x7e00;		/* Line counter is now 0x7c00. */
        .text :
	{
	  *(.text)              /* Copy input section .text to the oputput. */
	  *(.data)		/* Copy input section .data to the output. */
	  *(.bss)		/* Copy input section .bss to the output. */
	  *(.rodata)		/* Copy input section .rodata to the output. */
	}
}
