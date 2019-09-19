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
	
	lds r20, 0x28 //setando o bit 5 do portc
	ori r20, 0x20 
	sts 0x28, r20
	
	lds r21, 0x26 //setando o bit 0 do pinc
	ori r21, 0x01
	sts 0x21,r21 

	pisca:
		call acende05
		call apaga05
	
	rjmp pisca
	

acende05:
		lds r17, 0x25
		ori r17, 0x20
		sts 0x25, r22  
		call atrasa05
		ret

apaga05:
		lds r17,0x25
		andi r17, 0xDF
		sts 0x25,r17
		call atrasa05
		ret

acende01:
		lds r17, 0x25
		ori r17, 0x20
		sts 0x25, r22  
		call atrasa01
		ret

apaga01:
		lds r17,0x25
		andi r17, 0xDF
		sts 0x25,r17
		call atrasa01
		ret


atrasa05:  //atraso de 0,5s
	
	ldi r20, 200 
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
	
	ldi r20, 40
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
