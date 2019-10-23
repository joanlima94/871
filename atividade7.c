/*
 * atividade7.c
 *
 * Created: 11/10/2019 15:36:26
 * Author : joan_
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#define MAX 10


unsigned char *p_portb;
unsigned char *P_ddrb;
unsigned char *p_ucsr0a;
unsigned char *p_ucsr0b;
unsigned char *p_ucsr0c;
unsigned char *p_ubbr0h;
unsigned char *p_ubbr0l;
unsigned char *p_udr0;
volatile int i = 0;


void setar_registrador(void)
{
	//setando as mascaras dos registradores
	p_portb = (unsigned char *) 0x25;
//	p_ddrb = (unsigned char *) 0x24;
	p_ucsr0a = (unsigned char *) 0xC0;
	p_ucsr0b = (unsigned char *) 0xC1;
	p_ucsr0c = (unsigned char *) 0xC2;
	p_ubbr0h = (unsigned char *) 0xC5;
	p_ubbr0l = (unsigned char *) 0xC4;
	p_udr0 = (unsigned char *) 0xC6;

	//configurações da USART
	//Velocidade de transmissão multi- processador desabilitada
	//número de bits de dados por frame igual a 8
	//modo assíncrono de funcionamento
	//Sem bits de paridade
	//Uso de dois bits de parada
	//Baud rate de 9600

	*p_ucsr0a = 0b00000000;
	*p_ucsr0b = 0b00001000;
	*p_ucsr0c = 0b00001110;

	//Configuração do Baud Rate para 9600 bps
	*p_ubbr0h = 0;
	*p_ubbr0l = 103;

	//*p_ddrb = 1; //setando a porta b como saida
	
	*p_portb &= 0xF8; // Iniciando zerado o PB2, PB1, PB0
}

ISR(INT0_vect)
{

}	
ISR(PCINT1_vect)
{

}

int main(void)
{
	setar_registrador();
	i=0;
       	char msg[]="vazio!\n";
	while(1)
	{
		i=0;
		while(msg[i]!='\0')
		{
			*p_udr0=msg[i];
			while(!(*p_ucsr0a & 0b00100000)){};
			i++;
			_delay_ms(200);
		}
	
	}

}
