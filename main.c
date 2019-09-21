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
volatile unsigned char *p_portc;
volatile unsigned char *p_mcucr;
unsigned char *p_ucsr0b;

void setup_registradores(void)  //seta os registradores
{
	p_ucsr0b = (unsigned char *) 0xC1;
	p_ddrd = (unsigned char *) 0x2A;
	p_portd = (unsigned char *) 0x2B;
	p_portc =(unsigned char *) 0x28;
	p_ddrc = (unsigned char *) 0x27;
	p_pinc = (unsigned char *) 0x26;
	p_mcucr = (unsigned char *) 0x55;
	*p_ucsr0b = 0;
	*p_portc |=0x01;
	*p_ddrd |= 0xFE;
	*p_ddrc &= 0x00;
	*p_mcucr &=0b11101111;
		
}


int main(void)
{
	setup_registradores();
	
	unsigned char led=0; //contador para exibir o número do led

	while(1)
	 {
		 if ((*p_pinc & 0x01) == 0)
		 {
			 _delay_ms(50);
			if ((*p_pinc &0x01) != 0)
			{
				led++;
			}
		 }
		 	 		 
		 if (led==0)
		 {
			 *p_portd&=0x01;
			 *p_portd |= 0x7E; //led  em 0
		
		 }
		 if (led==1)
		 {
			 *p_portd &= 0x01; //Zera o registrador
			 *p_portd |= 0x0C; //led  em 1 
		 }
		 if (led==2)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xB6; //led  em 2
		 }
		 if (led==3)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0x9E; //led  em 3
		 }
		 if (led==4)
	 	 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xCC; //led  em 4
		 }
		 if (led==5)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xDA; //led  em 5
		 }
		 if (led==6)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xFA; //led  em 6
		 }
		 if (led==7)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0x0E; //led  em 7
		 }
		 if (led==8)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xFE; //led  em 8
		 }
		 if (led==9)
		 {
			*p_portd &= 0x01; //Zera o registrador
			*p_portd |= 0xCE; //led  em 9
		 }
		 
		 if (led>9)
		 {
			 led=0;
		 }
	
	 }
	 
}


