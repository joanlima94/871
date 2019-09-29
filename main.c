/*
 * ativ3.c
 *
 * Created: 05/09/2019 05:00:09
 * Author : joan_
 */ 
#define F_CPU 16000000UL //16 MHz de clock

#include <util/delay.h>


volatile unsigned char *p_ddrc;
volatile unsigned char *p_ddrd;
volatile unsigned char *p_portd;
volatile unsigned char *p_pinc;
unsigned char *p_ucsr0b;

void setup_registradores(void)  //seta os registradores
{
	p_ucsr0b = (unsigned char *) 0xC1;
	p_ddrd = (unsigned char *) 0x2A;
	p_portd = (unsigned char *) 0x2B;
	
	p_ddrc = (unsigned char *) 0x27;
	p_pinc = (unsigned char *) 0x26;
	
	*p_ucsr0b = 0;
	
	*p_ddrd |= 0xFE;
	*p_ddrc &= 0x00;
		
}


int main(void)
{
	unsigned char bottom = 1; //botão em repouso = 1, pressionado = 0
	unsigned char estado = 0; //estado inicial é zero, a MEF possui 10 estados
	unsigned char led=0; //contador para exibir o número do led
	
	setup_registradores();
	
     while (1)
	 {
		 if ((*p_pinc & 0x01) == 0)
		 {
			 bottom = 0;
		 }
		 else
		 {
			 bottom = 1;
		 }
		 
		 switch(estado)
		 {
			 case 0:   //led em repouso começa em 0
					if (bottom==1)
					{
						led = 0;
						estado = 0;
					}
					if (bottom==0)
					{
						led++;
						estado = 1;
					}
					break;
				
			 case 1: //led muda pra 1 se botão for apertado
					 if (bottom==1)
					 {
						led = led;
						estado = 1;
					 }
					 if (bottom==0)
					 {
						led++;
						estado = 2;
					 }
					 break;
				
			 case 2: //led muda pra 2 se botão for apertado
					if (bottom==1)
					{
						led = led;
					    estado = 2;
				    }
					if (bottom==0)
					{
						led++;
						estado = 3;
					}
					break;
			 
			 case 3: //led muda pra 3 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 3;
					}
					if (bottom==0)
					{
						led++;
						estado = 4;
					 }
					 break;
			 
			 case 4: //led muda pra 5 se botão for apertado
					 if (bottom==1)
					 {
						led = led;
						estado = 4;
					 }
					 if (bottom==0)
					 {
						 led++;
						 estado = 5;
					 }
					 break;	
			case 5: //led muda pra 6 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 5;
					}
					if (bottom==0)
					{
						led++;
						estado = 6;
					}
					break;	 
			case 6: //led muda pra 7 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 6;
					}
					if (bottom==0)
					{
						led++;
						estado = 7;
					}
					break;
			case 7: //led muda pra 8 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 7;
					}
					if (bottom==0)
					{
						led++;
						estado = 8;
					}
					break;
			case 8: //led muda pra 9 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 8;
					}
					if (bottom==0)
					{
						led++;
						estado = 9;
					}
					break;
			case 9: //led volta pra 0 se botão for apertado
					if (bottom==1)
					{
						led = led;
						estado = 9;
					}
					if (bottom==0)
					{
						led=0;
						estado = 0;
					}
					break;
		 }
		 if (led==0)
		 {
			 *p_portd |= 0x7E; //led  em 0
			 _delay_ms(50);
			 *p_portd &= 0x01; //Zera o registrador
			 _delay_ms(50);
		}
		if (led==1)
		{
			 *p_portd &= 0x01; //Zera o registrador
			 _delay_ms(50);
			 *p_portd |= 0x12; //led  em 1 
			 _delay_ms(50);
		}
		if (led==2)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0x12; //led  em 2
			_delay_ms(50);
		}
		if (led==3)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xB6; //led  em 3
			_delay_ms(50);
		}
		if (led==4)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xD2; //led  em 4
			_delay_ms(50);
		}
		if (led==5)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xE6; //led  em 5
			_delay_ms(50);
		}
		if (led==6)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xEE; //led  em 6
			_delay_ms(50);
		}
		if (led==7)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0x32; //led  em 7
			_delay_ms(50);
		}
		if (led==8)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xFE; //led  em 8
			_delay_ms(50);
		}
		if (led==9)
		{
			*p_portd &= 0x01; //Zera o registrador
			_delay_ms(50);
			*p_portd |= 0xF6; //led  em 9
			_delay_ms(50);
		}
		 	 
	 }
	 
	 
	 
}

