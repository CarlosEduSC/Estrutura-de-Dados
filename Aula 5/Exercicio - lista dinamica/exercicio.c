#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int conteudo;
    struct elemento *prox;
};

typedef struct elemento nodo;

typedef nodo *lista;

lista criaLista () {
    return NULL;
}

void imprimeLista (lista l) {

    lista p;

    printf ("\n=====ITEMS DA LISTA=====\n");

    p = l;

    while (p != NULL) {

        printf ("\n%d\n",p->conteudo);
        p = p->prox;
    }
}

lista insereElemento (lista l, int e) {

    lista novo;

    novo = malloc(sizeof(struct elemento));
    novo -> conteudo = e;
    novo -> prox = l;

    return (novo);
}

int contaElementos (lista l) {

    lista p;
    int cont=0;

    p = l;

    while (p != NULL) {

        cont++;
        p = p->prox;
    }

    return cont;
}

lista buscaElemento (lista l, int e) {

    lista p;

    p = l;

    while (p != NULL && p->conteudo != e) {

        p = p->prox;
    }
    return (p);
}

lista retiraElemento (lista l, int e) {

    lista p,ant;

    p = l;
    ant = l;

    while (p != NULL && p->conteudo != e) {

        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (p == ant) {
            l = p->prox;
            free(p);
        
        } else {
            ant->prox = p->prox;
            free(p);
        }
    }

    return (l);
}

int main () {

    lista L1,ponteiro;
    int num,menu;

    L1 = criaLista();

    do {

        printf ("\n1- Inserir elemento na lista.\n2- Retirar elemento da lista.\n3- Buscar um elemento informado está na lista.\n4- Imprime o conteudo da lista.\n5- Conta o numero de elementos da lista.\n6- Sair.\n");

        printf ("\nDigite uma das opcoes acima: ");
        scanf ("%d",&menu);

        printf ("\n==========//==========\n");


        
        switch (menu) {

            case 1:
                
                printf ("\nDigite o elemento que deseja inserir na lista: ");
                scanf ("%d",&num);

                L1 = insereElemento (L1,num);

                printf ("\nO elemento '%d' inserido!\n",num);

                printf ("\n==========//==========\n");
                break;

            case 2:
                
                printf ("\nDigite o elemento que deseja remover da lista: ");
                scanf ("%d",&num);

                L1 = retiraElemento (L1,num);

                printf ("\nO elemento '%d' removido!\n",num);

                printf ("\n==========//==========\n");
                break;

            case 3:

                printf ("\nDigite o elemento que deseja buscar na lista: ");
                scanf ("%d",&num);

                ponteiro = buscaElemento (L1,num);

                if (ponteiro == NULL)
                    printf ("\nO Elemento '%d' nao foi encontrado!\n",num);

                else
                    printf ("\nO Elemento '%d' foi encontrado!\n",num);
                
                printf ("\n==========//==========\n");
                break;

            case 4:

                imprimeLista (L1);

                printf ("\n==========//==========\n");
                break;

            case 5:

                num = contaElementos(L1);

                printf ("\nA lista tem %d elementos!\n",num);
                
                printf ("\n==========//==========\n");
                break;

            case 6:
                break;

            default:

                printf ("\nOpcao invalida!\n");

                printf ("\n==========//==========\n");
        }
    
    } while (menu != 6);

    return 0;
}