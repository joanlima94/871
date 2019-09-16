;
; atividade4.asm
;
; Created: 16/09/2019 14:44:10
; Author : ea871
;


; Replace with your application code

.org 0x0000

jmp main

.org 0x0034

main:
;setar o bit 3 de ddrb, pino13
	ldi r16, 0x10
	out DDRB,r16
	
loop:
;manter o led sempre aceso, bit 5 de PORTB
	sbi PORTB,5
	rjmp loop



