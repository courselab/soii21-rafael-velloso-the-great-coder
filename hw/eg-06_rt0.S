
#   This register tells the CPU where the call instruction should
#   leave the return address. More technically, this is the
#   stack pointer but we'll go deeper into it opportunely. 
#
#   LOAD_ADDRESS + 512 bytes + 16 bytes = 0x7e10 



movl $0x7e10, %esp
