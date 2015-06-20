.syntax unified

.section ".vectors"

/* Stack top */
.word 0x20001000
/* Handlers */
.word reset
.word nmi
.word hard_fault
