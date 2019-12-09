/*
 * atividade8.c
 *
 * Created: 01/11/2019 21:05:57
 * Author : joan_
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
volatile int i = 0;
volatile int estado = 0;
volatile int cont1 = 0;
volatile int cont2 = 0;

void configura_uart()
{
	//Baud rate em 38400 bps
	UBRR0H = 0;
	UBRR0L = 25;
	
	//Velocidade de transimissão normal e Multiprocessador desabilitado
	UCSR0A = 0x00;
	
	/*
	- Transmissões USART desabilitadas
	- Somente o transmissor ativo
	- Numero de bits transmitidos em cada frame igual a 8
	*/
	UCSR0B = 0x08;
	
	/*Esse registrador indica as seguintes especificações:
	-USART assincrono
	-Bit de paridade ímpar
	-um único bit de parada
	-Número de bits transmitidos em cada frame (UCSZ01 e UCSZ00), no caso são 8
	-Transmissão assíncrona
	*/
	UCSR0C =0b00110110;
	
}

void configura_ledin()
{
	TCCR2A = 0x02; // Seleciona o modo de operação CTC
	TCCR2B = 0xC2; //configura o prescaler para ter um fator 8, ou seja a frequência passa a ser 2MHz
	OCR2A = 200; //Valor colocado no registrador que define a faixa de contagem 
	OCR2B = 200; //Valor para ser comparado no item B
	TIMSK2 = 0x06;
	
}

ISR(TIMER2_COMPA_vect)
{
	cont1++;  //Contador q deve contar até 5000 para bater 0.5s e acender o led
	if (cont1==5000)
	{
		PORTB = 0x20;
	} else if (cont1==10000)  // Essa condição é para manter o led 0.5 apagado
	{
		PORTB&=0b11011111;
		cont1=0;
	}

}

ISR(TIMER2_COMPB_vect)
{
		cont2++;  //Contador q deve contar até 5000 para bater 0s 0.78s e acender o led
		if (cont2==7800)
		{
			PORTB = 0x10;
		} else if (cont2==15600) // essa condição é para mantar o led 0.78s apagado
		{
			PORTB&=0b11101111;
			cont2=0;
		}
}

int main(void)
{
    DDRB=255; //Configurado como saida
	configura_uart();
	configura_ledin(); 
	
	sei();
	char msg[] = " Atividade 8 – Interrupcoes temporizadas tratam concorrencia entre tarefas! \n";

    while (1) 
    {
		i =0;
		while (msg[i]!='\0')
		{
			UDR0 = msg[i];
			while(!(UCSR0A & 0x20)) {};
			i++;
		}
		_delay_ms(5000);
    }
}

