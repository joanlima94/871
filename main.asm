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
	           
	lds r16, 0x24 //configurado o pino 5 como saida (ddrb)
	ori r16, 0x20
	sts 0x24, r16


loop:
	
	lds r16, 0x24
	andi r16, 0x7F
	sts 0x24, r16
	jmp atrasa05
	lds r16,0x24
	ori r16, 0x80
	jmp atrasa05
	
	rjmp loop //volta pro inicio do loop

atrasa05:  //atraso de 0,5s
	ldi r18, 200
	ldi r19, 200
	ldi r20, 200 
	ldi r23, 0
   volta:
	  dec r18 //decrementa r18, começa em 200
	  cp r18, r23
	  brne volta //enquanto R18 >0 decrementa r18
	  dec r19 //decrementa r19, começa em 200
	  cp r19, r23
	  brne volta //enquanto r19>0 decrementa r19
	  dec r20  //decrementa r20, começa em 200
	  cp r20, r23
	  brne volta //enquanto r19>0 vai para volta
	  ret
	  
atrasa01: //atraso de 0,1s
	ldi r18, 200
	ldi r19, 200
	ldi r20, 40
	ldi r23, 0
	retorna:
	  dec r18 //decrementa r18, começa em 200
	  cp r18, r23
	  brne retorna //enquantor 18 > 0 decrementa r18
	  dec r19 //decrementa r18, começa em 200
	  cp r19, r23
	  brne retorna //enquanto r19 >0, decrementa r19
	  dec r20 //decrementa r20, começa em 40
	  cp r20, r23
	  brne retorna //enquanto r20>0 vai para volta
	  ret
		   

