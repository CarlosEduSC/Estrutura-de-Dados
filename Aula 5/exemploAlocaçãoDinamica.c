#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct elemento {
   int dado;				// Conteúdo (inteiro)
   struct elemento *prox;	// Ponteiro para o próximo registro
};

typedef struct elemento *Lista;


int leInt()
{
	int ret;
	char s[10];
	
	fgets(s,10,stdin);
	s[strlen(s)-1] = '\0';
	sscanf(s,"%d",&ret);
	return ret;
}

void leString(char *s, int tam)
{
	fgets(s,tam,stdin);
	s[strlen(s)-1] = '\0';
}


Lista criaLista()
{
	return NULL;
}


// Imprime todos os nodos da lista l
void imprimeLista(Lista l)
{
	Lista p;		// Ponteiro auxiliar, para percorrer a lista
	
	printf("\nItens da lista\n");
	p = l;		// Fazer p apontar para o início da lista
	while (p != NULL)	// Enquanto não chegar ao final da lista
	{
		printf("%d - ",p->dado);	// Imprime o elemento
		p = p->prox;	// Avança o ponteiro para o próximo nodo
	}
	printf("\n");	// Avança para a próxima linha
}


// Insere um elemento e no início da lista l
Lista insereLista(Lista l, int e)
{
	Lista novo;
	
	// Aloca o espaço e faz as atribuições de valores
	novo = malloc(sizeof(struct elemento));
	novo -> dado = e;
	novo -> prox = l;  // O próximo do novo é o início da lista
	return (novo);     // Retorna o endereço do novo elemento
}


// Procura o elemento e na lista l, retornando o endereço 
// do elemento se ele estiver na lista, ou NULL em caso contrário
Lista buscaLista(Lista l, int e)
{
	Lista p;	// Ponteiro para percorrer a lista
	
	p = l;	// Faz o ponteiro apontar para o início da lista
	// Percorre a lista enquanto não chegar ao final da lista
	// e não encontrar o elemento
	while ((p != NULL) && (p->dado != e)) 
	{
		p = p->prox;
	}
	return (p); // Retorna o endereço do nodo encontrado 
			  // ou NULL caso tenha chegado ao final sem 
			  // encontrar o elemento e na lista.
}

// Conta o número de nodos da lista l
int contaLista(Lista l)
{
	Lista p;
	int cont = 0;		// inicia o contador com 0
	
	p = l;			// aponta p para o início da lista
	while (p != NULL)	// enquando não acabou a lista
	{
		cont++;		// incrementa o contador
		p = p->prox;	// passa para o próximo elemento
	}
	return cont;		// retorna o contador
}


// Retira o elemento e da lista l, se ele existir.
// Retorna o endereço para o início da lista. 
Lista retiraLista (Lista l, int e)
{
	Lista p,    // Ponteiro p para o elemento atual
         ant;  // Ponteiro ant para o elemento anterior
	
	p=l;
	ant=l;
	// Procura o elemento e até o fim da lista ou encontrá-lo
	while ((p!=NULL) && (p->dado != e))
	{  // Procura o elemento e
		ant = p;
		p = p->prox;
	}
	if (p!=NULL)
	{  // Encontrou o elemento e. Remove
		if (p == ant) // Removendo primeiro elemento
		{
		    l = p->prox;
		    free (p);
		}
		else // Não é o primeiro elemento da lista
		{
		    ant->prox = p->prox;
		    free(p);
		}
	}
	return(l);
}


int main()
{
	Lista l;
	int op;
	int cont;
	Lista pos;
	int item;
	
	l = criaLista();
	op = 1;
	while (op != 0) {
		printf("\nLista de strings com alocação estática");
		printf("\n\n1 - Inserir item na lista");
		printf("\n2 - Imprimir lista");
		printf("\n3 - Retirar item");
		printf("\n4 - Tamanho da lista");
		printf("\n5 - Busca um elemento na lista");
		printf("\n0 - Encerrar\n");
		printf("\nOpção: ");
		op = leInt();
		switch(op) {
			case 1: printf("\nEntre com o item a inserir: ");
					item = leInt();
                    l = insereLista(l,item);
					break;
			case 2: imprimeLista(l);
					break;
			case 3: printf("\nEntre com o item a retirar: ");
					item = leInt();
                    l = retiraLista(l,item);
					break;
			case 4: cont = contaLista(l);
			        printf("\nA lista tem %d itens",cont);
					break;
            case 5: printf("\nEntre com o elemento a ser buscado: ");
					item = leInt(); 
					pos = buscaLista(l,item);
					if (pos == NULL) 
					    printf("\nItem não encontrado");
					else
						printf("\nItem encontrado");
					break;
			case 0: break;
			default: printf("\nOpcao invalida");
		}
	}
}