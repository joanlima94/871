/*
 * atividade9.c
 *
 * Created: 22/11/2019 19:09:39
 * Author : joan_
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile int cont=0;
volatile int acende=1;


void configura()
{
	//Essas configurações são para o Fast PWM utilizando o registrador OCR2A para ser incrementado até 255
	//Configurando um Prescaler com fator 8, deixando assim a frequência em 2 MHz
	//E setando o PB1 como saida, fazendo DDRB=2
	//E utilizando o Timer2 com overflow
	TCCR2A = 0x83; 
	TCCR2B = 0x02;
	TIMSK2 = 0x01;
	OCR2A=0;
	DDRB = 8; //Testei várias entradas de PWM e apenas essa foi a que funcionou corretamente, não sei por que
}

ISR(TIMER2_OVF_vect)
{
	cont++;
	if (cont==30) //Fazendo as contas, temos que o contador deve ser igual a 30 . Pois, 1 = 256*256*(1/2000000)*30
	{
		cont=0;
		if (acende==1)
		{
			OCR2A++;
			if (OCR2A==255) acende=0;
		}else if (acende==0)
		{
			OCR2A--;
			if (OCR2A==0) acende=1;
		}
	}
}

int main(void)
{
    sei();
	configura();
    while (1);
}

