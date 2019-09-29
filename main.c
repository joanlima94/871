/*
 * atividade5.c
 *
 * Created: 21/09/2019 15:36:26
 * Author : joan_
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>


unsigned char *p_ddrc;
unsigned char *p_portc;
unsigned char *p_portb;
unsigned char *p_eicra;
unsigned char *p_eimsk;
unsigned char *p_ddrb;
unsigned char *p_pinc;
unsigned char *p_portd;
unsigned char *p_ddrd;
unsigned char *p_pind;

volatile int tempo = 1000;


void setar(void)
{
	//utilizando o mapeamento de memória para mascarar as portas 
	
	p_portb = (unsigned char *) 0x25;
	p_ddrb = (unsigned char *) 0x24;
	p_portc = (unsigned char *) 0x28;
	p_ddrc = (unsigned char *) 0x27;
	p_pinc = (unsigned char *) 0x26;
	p_portd = (unsigned char *) 0x2B;
	p_ddrd = (unsigned char *) 0x2A;
	p_pind = (unsigned char *) 0x29;
	p_eimsk = (unsigned char *) 0x3D;
	
	//selecionando a porta B2,B1,B0 como saida
	*p_ddrb |=7;
	
	//setando a porta C como saida
	*p_ddrc |=1;
	
	//setando a porta D como saida
	*p_ddrd |=2;
	
	//PB0 inicialmente apagado
	*p_portb &=0xFE;
	//PB1 inicialmente apagado
	*p_portb &=0xFD;
	//PB2 inicialmente apagado
	*p_portb &=0xFC;
	
	*p_eimsk |=2; //habilitando o INT0
	*p_eicra |=2; //Configurando o pino ISC00 em nivel alto
	
	*p_portc |=0x01;
	*p_portd |=0x02; 
}

ISR(INT0_vect)
{
	if ((*p_pind & 0x02) ==1)
	{
		while(tempo>=125 && tempo<=1000)
		{
			tempo/=2;
		
			*p_portb |= 0x01; //acende o vermelho
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x02; //acende o verde
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x04; //acende o azul
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x03; //acende o amarelo
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x06; //acende o ciano
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x05; //acende o magenta
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 0x07; //acende o branco
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			_delay_ms(tempo);
		
			if (tempo==125)
			{
				tempo=1000;
				break;
			}
		}
	}
	else 
	{
		*p_portb |= 0x01; //acende o vermelho
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x02; //acende o verde
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x04; //acende o azul
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x03; //acende o amarelo
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x06; //acende o ciano
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x05; //acende o magenta
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x07; //acende o branco
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		_delay_ms(tempo);
	}
}

ISR(PCINT1_vect)
{
	if ((*p_pinc & 0x01) == 1)
	{
		
		*p_portb &= 0xF8;
		*p_portb |= 0x07; //acende o branco
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x05; //acende o magenta
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x06; //acende o ciano
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x03; //acende o amarelo
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x04; //acende o azul
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x02; //acende o verde
		_delay_ms(tempo);
		*p_portb &= 0xF8;
		*p_portb |= 0x01; //acende o vermelho
		_delay_ms(tempo);
		
		
	}
	
}

int main(void)
{
    
	setar();
	
	while (1)
	{
		if ((*p_pinc & 0x01) == 0)
		{
			sei();
		}
				
			*p_portb |= 1; //acende o vermelho
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 2; //acende o verde
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 4; //acende o azul
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 3; //acende o amarelo
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 6; //acende o ciano
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 5; //acende o magenta
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			*p_portb |= 7; //acende o branco
			_delay_ms(tempo);
			*p_portb &= 0xF8;
			_delay_ms(tempo);	
	
	}
}

