;
; atividade4.asm
;
; Created: 17/09/2019 23:44:48
; Author : joan_

.org 0x0000
jmp main
.org 0x0034

main:
	           
	lds r16, 0x24 //configurado o pino 5 como saida (ddrb)
	ori r16, 0x20
	sts 0x24, r16
	
	lds r18, 0x55 //desabilitando o MCUCR, resistor pull up , bit 4 do registrador
	andi r18, 0xEF
	sts 0x55, r18

	lds r19, 0x27 //setando o bit 0 do ddrc
	ori r19, 0x01
	sts 0x27, r19
	
	lds r30, 0x28 //setando o bit 0 do portc
	ori r30, 0x01 
	sts 0x28, r30

	ldi r29, 0

	pisca05:         //laço que pisca no periodo de 1s
		
		call acende05
		call apaga05

		lds r21,0x26
		andi r21, 0x01
		cp r29,r21
		breq pisca01

	rjmp pisca05

	pisca01:            //laço que pisca no periodo de 0,2s

		call acende01
		call apaga01
		
		lds r21,0x26
		andi r21, 0x01
		cp r29,r21
		brne pisca05
		
	rjmp pisca01
	

acende05:                    
		lds r30, 0x25
		ori r30, 0x20
		sts 0x25, r30  
		call atrasa05
		ret

apaga05:
		lds r30,0x25
		andi r30, 0xDF
		sts 0x25,r30
		call atrasa05
		ret

acende01:
		lds r30, 0x25
		ori r30, 0x20
		sts 0x25, r30  
		call atrasa01
		ret

apaga01:
		lds r30,0x25
		andi r30, 0xDF
		sts 0x25,r30
		call atrasa01
		ret

atrasa05:  //atraso de 0,5s
	
	ldi r20, 50 
	ldi r23, 0
   volta2:
   ldi r19, 200
   volta1:
   ldi r18, 200
   volta:
	  dec r18 //decrementa r18, começa em 200
	  cp r18, r23
	  brne volta //enquanto R18 >0 decrementa r18
	  dec r19 //decrementa r19, começa em 200
	  cp r19, r23
	  brne volta1 //enquanto r19>0 decrementa r19
	  dec r20  //decrementa r20, começa em 200
	  cp r20, r23
	  brne volta2 //enquanto r19>0 vai para volta
	  ret
	  
atrasa01: //atraso de 0,1s
	
	ldi r20, 10
	ldi r23, 0
	retorna2:
	ldi r19, 200
	retorna1:
	ldi r18, 200
	retorna:
	  dec r18 //decrementa r18, começa em 200
	  cp r18, r23
	  brne retorna //enquantor 18 > 0 decrementa r18
	  dec r19 //decrementa r18, começa em 200
	  cp r19, r23
	  brne retorna1 //enquanto r19 >0, decrementa r19
	  dec r20 //decrementa r20, começa em 40
	  cp r20, r23
	  brne retorna2 //enquanto r20>0 vai para volta
	  ret
