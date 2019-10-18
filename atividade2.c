/* Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>
#define MAX 5

char buffer[MAX]; //vetor com 5 elementos
int spos =0; //indice de inserir
int rpos =0; //indice de remover
int n_elem =0; //numero de elementos 

//função adicionar buffer
void adicionar_buffer(char c) {
		
	if (n_elem<5)
	{
		buffer[spos]=c;
		spos=(spos+1)%5; //faz com que spos seja maximo 4
		n_elem++;
	}
	if (rpos>spos)
	{
		buffer[n_elem]=c;
		n_elem++;
	}
	if ((rpos>0 && spos>0) && (rpos==spos))
	{
		rpos=0;
		spos=0;
	}
	
}

void remover_buffer() {
	if (n_elem>0)
	{
		buffer[rpos]=0;
		rpos=(rpos+1)%5;
		n_elem--;
	}
	if ((rpos>0 && spos>0) && (rpos==spos)) //zera os indices de somar e remover
	{
		rpos=0;
		spos=0;
	}
}

void imprimir_buffer() {
	int indice = rpos;

	for(int count = 0;count<n_elem;count++)
	{
		if (count == n_elem-1)
		{
		printf("%c",buffer[indice]);	
		} 
		else 
		{
		printf("%c ",buffer[indice]);
		}		
		indice = (indice +1)%5;

	}
		printf("\n");	
	//	printf("%d elementos\n",n_elem );
	//	printf("%d rpos\n",rpos );
	//	printf("%d spos\n",spos );

}

int main() {
	char c;
	do {
		scanf("%c",&c);
		if (c>=48 && c<=57)
		{
			adicionar_buffer(c);
		}
		else if ((c>=65 && c<=90) || (c>=97 && c<=122))
		{
			remover_buffer();
		}		
		
		if(c=='\n') break;	
		imprimir_buffer();	

      } while(1);
 
  return 0;
}
