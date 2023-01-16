[BITS 16]
[ORG 0x700]

JMP $

TIMES 510 - ($ -$$) db 0
DW 0xAA55
