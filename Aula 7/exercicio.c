#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct elemento {
    int conteudo;
    struct elemento *prox;
};

typedef struct elemento *Pilha;

Pilha criaPilha () {

    return NULL;
}

int testaVazio (Pilha p) {

    if (p == NULL)
        return TRUE;

    else
        return FALSE;
}

Pilha empilhar (Pilha p, int e) {

    Pilha pa;

    pa = malloc(sizeof(struct elemento));

    pa->conteudo = e;

    pa->prox = p;

    return pa;
}

Pilha desempilhar (Pilha p, int *e) {

    Pilha pa;

    if (testaVazio(p) == FALSE) {

        *e = p->conteudo;

        pa = p;

        p = p->prox;

        free (pa);
    
    } else {

        *e = -1;

        printf ("\nPilha vazia!\n");
    }

    return p;
}

void imprimePilha (Pilha p) {

    Pilha pa;

    pa = p;

    printf ("\n=====ITENS DA LISTA=====\n");

    while (pa != NULL) {

        printf ("\n%d\n",pa->conteudo);

        pa = pa->prox;
    }
}

int main () {

    int menu,e1;
    Pilha p1;

    p1 = criaPilha();

    do {

        printf ("\n1- Empilhar um elemento.\n2- Desempilhar um elemento.\n3- Imprimir o conteudo da pilha.\n4- Sair.\n");

        printf ("\nEscolha uma das opcoes: ");
        scanf ("%d",&menu);

        printf ("\n==========//==========\n");

        switch (menu) {

            case 1:
                printf ("\nDigite o elemento que voce quer empilhar: ");
                scanf ("%d",&e1);

                p1 = empilhar (p1,e1);

                printf ("\nElemento empilhado!\n");
                printf ("\n==========//==========\n");
                break;

            case 2:
                printf ("\nDigite o elemento que voce quer desempilhar: ");
                scanf ("%d",&e1);

                p1 = desempilhar (p1,&e1);

                printf ("\nElemento retirado da pilha!\n");
                printf ("\n==========//==========\n");
                break;

            case 3:
                imprimePilha (p1);
                printf ("\n==========//==========\n");
                break;

            case 4:
                break;

            default:
                printf ("\nOpcao invalida!\n");
                printf ("\n==========//==========\n");
        }
    } while (menu != 4);

    return 0;
}