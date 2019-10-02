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
volatile int tempo=1000;
volatile int estado;
volatile int sentido=0; //sentido definido como horário

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

ISR(INT0_vect) //Função que configura o periodo dos Leds
{
		tempo/=2;
		if (tempo<125) tempo = 1000;
						
}


ISR(PCINT1_vect)  //Função que configura a transição de sentido
{
    //interrompe pro sentido anti-horário
	
	if ((*p_pinc & 1) == 0)
	{	
		if (sentido==1) sentido = 0;
		else sentido = 1;	
	}
   
}

void acende_led_horario(void)
{
	if (estado==0)
	{
		*p_portb&=0xF8; //Led apagado
	}
	
	if (estado==1)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x01; //acende o vermelho
	}
	
	if (estado==2)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x02; //acende o verde
	}
	
	if (estado==3)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x04; //acende o azul
	}
	
	if (estado==4)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x03; //acende o amarelo
	}

	if (estado==5)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x06; //acende o ciano
	}
	
	if (estado==6)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x05; //acende o magenta
	}
	
	if (estado==7)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x07; //acende o branco
	}
	
	_delay_ms(tempo);	
}
void acende_led_anti_horario(void)
{
	
	if (estado==7)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x07; //acende o branco
	}
	
	if (estado==6)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x05; //acende o magenta
	}
	
	
	if (estado==5)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x06; //acende o ciano
	}

		
	if (estado==4)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x03; //acende o amarelo
	}
		
	if (estado==3)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x04; //acende o azul
	}

	
	if (estado==2)
	{
		*p_portb &= 0xF8;
		*p_portb |= 0x02; //acende o verde
	}

	
	if (estado==1)
	{
		*p_portb &=0xF8;
		*p_portb |= 0x01; //acende o vermelho
	}
	
	if (estado==0)
	{
		*p_portb&=0xF8; //Led apagado
		estado=7;
	}
	
	_delay_ms(tempo);
}


int main(void)
{
	estado =0;
    
	setar();
	sei();

		while (1)
		{
			if (sentido==0)
			{
				acende_led_horario();
				estado = (estado+1)%8;
			}
			else
			{
				acende_led_anti_horario();
				estado = estado - 1;
				
			}	
					
		
		
	}
	

}

