/*
 * atividade6.c
 *
 * Created: 02/10/2019 08:56:57
 * Author : joan_
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
//Registradores de Baud-Rate
unsigned char *ubrr0h;
unsigned char *ubrr0l;
//Registradores de controle e status
unsigned char *ucsr0a;
unsigned char *ucsr0b;
unsigned char *ucsr0c;
//Registrador de dados
unsigned char *udr0; 
volatile int i = 0;

void setar_registradores(void)
{
	ubrr0h = (unsigned char *) 0xC5;
	ubrr0l = (unsigned char *) 0xC4;
	ucsr0a = (unsigned char *) 0xC0;
	ucsr0b = (unsigned char *) 0xC1;
	ucsr0c = (unsigned char *) 0xC2;	
	udr0 = (unsigned char *) 0xC6;
	
	//esses dois registradores setam o Baud-Rate em 38400 bps.
	*ubrr0h = 0;
	*ubrr0l = 25;
	
	/*Esse registrador indica as seguintes especificações:
	-Velocidade de transmissão normal
	-Multiprocessador desabilitado
	*/
	*ucsr0a = 0b00000000;
	/*Esse registrador indica as seguintes especificações:
	-Todas as interrupções USART desabilitadas
	-Somente o transmissor ativado
	-Número de bits transmitidos em cada frame (UCSZ02), no caso são 8
	*/
	*ucsr0b =0b00001000;  
	/*Esse registrador indica as seguintes especificações:
	-USART assincrono
	-Bit de paridade ímpar
	-um único bit de parada
	-Número de bits transmitidos em cada frame (UCSZ01 e UCSZ00), no caso são 8
	-Transmissão assíncrona
	*/
	*ucsr0c =0b00110110;
}

int main(void)
{
	setar_registradores();
        char msg[]="Estamos no processo de fazer o bagulho funcionar\n";
    	char fim[]="A mensagem foi transmitida com sucesso!\n"; 

	while(1)
	{
		i = 0;
		while (msg[i]!='\0') //condição de execução do loop, só para quando chega no último caracter da string \0
    		{
			*udr0=msg[i];
			while(!(*ucsr0a & 0b00100000)){}; //Sai do looping toda vez a flag de envio ativar
    			i++;
			_delay_ms(100);
		}
		i=0;
		while(fim[i]!='\0')
		{
			*udr0=fim[i];
			while(!(*ucsr0a & 0b00100000)){};
			i++;
			_delay_ms(100);
		}
		_delay_ms(5000);	
	}
}

