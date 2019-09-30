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
unsigned char *p_pcicr;
unsigned char *p_portb;
unsigned char *p_eicra;
unsigned char *p_eimsk;
unsigned char *p_ddrb;
unsigned char *p_pinc;
unsigned char *p_pcmsk;
unsigned char *p_ddrd;
unsigned char *p_pind;
int tempo=1000;


void setar(void)
{
	//utilizando o mapeamento de memória para mascarar as portas 

	p_portb = (unsigned char *) 0x25;
	p_ddrb = (unsigned char *) 0x24;
	p_ddrc = (unsigned char *) 0x27;
	p_pinc = (unsigned char *) 0x26;
	p_ddrd = (unsigned char *) 0x2A;
	p_pind = (unsigned char *) 0x29;
	p_eimsk = (unsigned char *) 0x3D;
	p_eicra = (unsigned char *) 0x69;
	p_pcicr = (unsigned char *) 0x68;
	p_pcmsk = (unsigned char *) 0x6C;
	
	
	//selecionando a porta B2,B1,B0 como saida
	*p_ddrb |=7;
	
	//setando a porta C como entrada
	*p_ddrc |=0;
	
	//setando o bit 3 da porta D como entrada
	*p_ddrd |=0;
	
	//PB0, PB1 e PB2 inicialmente apagados
	*p_portb &=0xF8;
	
	*p_eimsk |=1; //habilitando o INT0
	*p_eicra |=3; //Configurando o pino ISC00 e ISC01 na borda de subida
	
	*p_pcmsk |=1; //habilita as interrupções no PCINT8
	*p_pcicr |=2; //Habilita as interrupções em A0
	
}

ISR(INT0_vect)
{
	
		while(1)
			{
				
				if ((*p_pind & 0x04) ==0)
				{

						tempo/=2;
				}				
				
				*p_portb &=0xF8;
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


ISR(PCINT1_vect)
{
		while(1)
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
	sei();

	while (1)
		{
			*p_portb &=0xF8;
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

