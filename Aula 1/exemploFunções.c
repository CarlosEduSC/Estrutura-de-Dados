#include <stdio.h>

int a;

int duplica(int x) // Funcao que duplica o valor de x
{
     x=x*2;
	printf("Mensagem dentro da função: x = %d\n",x);	
	return(x);
}

int main()
{
	int a;
	int resultado;
	
	a = 50;
	resultado = duplica(a);
	// Imprime o valor de a e o valor retornado de duplica 
	printf("Resultado = %d, a = %d\n",resultado, a);
	a = 60;
	resultado = duplica(a);
	// Imprime o valor de a e o valor retornado de duplica 
	printf("\na = %d, resultado = %d \n",a, resultado);
	a=80;
	resultado = duplica(a);
	// Imprime o valor de a e o valor retornado de duplica 
	printf("\na = %d, resultado = %d \n",a, resultado);
	return(0);
}