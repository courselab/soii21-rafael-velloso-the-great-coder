include(docm4.m4)
 MbrCmd - Mater Book Record Command interpreter
 ==============================================
DOCM4_DIR_NOTICE

 Overview
 ------------------------------

 MbrCmd is a very simple command line interpreter that fits entirely within
 the 512-byte master boot record of a USB stick. It is meant to be loaded
 through legacy BIOS boot method and execute in real mode on any x86 platform.

 The program interprets a few built in commands.

 Challenge
 ------------------------------

 1) Build and execute MbrCmd under a x86 emulator (e.g. qemu).

 2) Copy the program to a USB stick and boot it with BIOS legacy mode.

 3) Implement a new command exploring other BIOS services.

    E.g. use BIOS interrupt service 0x12 to report the computer's memory size,
    of 0x1a to read the system time, or any other cool feature you can
    think of.

    Consult reference (1) by the end of this file and related online sources.

    Tip: you may get rid of built in commands implemented in the example
    code if you run out of space for your own commands. Rememer, your binary
    must fit in 512 bytes (not kbytes!) --- actually, 510 bytes if we count
    out the boot signature (so, hands on bit twiddling.) 

DOCM4_PACK_DIRECTIONS

DOCM4_CLOSING_WORDS


 APPENDIX A
 ------------------------------
 
DOCM4_MAKE_BINTOOLS_DOC



 NOTES
 ------------------------------

 (1) BIOS interrupt calls, https://en.wikipedia.org/wiki/BIOS_interrupt_call
 
