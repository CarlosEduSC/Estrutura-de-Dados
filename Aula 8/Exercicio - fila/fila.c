#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct elemento {
    int conteudo;
    struct elemento *prox;
};

typedef struct elemento *ApElemento;

typedef struct {
    ApElemento ini;
    ApElemento fim;
} Fila;

Fila criaFila() {
    Fila f;

    f.ini = NULL;
    f.fim = NULL;

    return f;
}

int filaVazia(Fila f) {
    if (f.ini== NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Fila insereElemento(Fila f, int e) {

    ApElemento novo;

    novo = malloc(sizeof(struct elemento));
    novo->conteudo = e;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f.ini = novo;
        f.fim = novo;
    
    } else {
        f.fim->prox = novo;
        f.fim = novo;
    }

    return f;
}

Fila retiraElemento(Fila f) {

    ApElemento pa;

    if (!filaVazia(f)) {
        pa = f.ini;
        f.ini = pa->prox;
        free(pa);

        if (filaVazia(f))
            f.fim = NULL;
    }

    return f;
}

void imprimeLista(Fila f) {

    ApElemento pa;
    pa = f.ini;

    if (!filaVazia(f)) {

        printf ("\n==========FILA==========\n");
        
        while (pa != NULL) {
            printf ("\n%d\n",pa->conteudo);
            pa = pa->prox;
        }
    } else
        printf ("\nFila Vazia!\n");
}

int main() {
    
    int menu,valor;
    Fila f1;

    f1 = criaFila();

    do {
        printf ("\n1- Inserir um elemento no final da fila.\n2- Retirar um elemento do início da fila.\n3- Imprimir o conteúdo da fila.\n4- Sair.\n");
        printf ("\nEscolha uma das opções a cima: ");
        scanf ("%d",&menu);

        printf ("\n==========//==========\n");

        switch (menu) {
            case 1:
                printf ("\nDigite o elemento que deseja inserir: ");
                scanf ("%d",&valor);

                f1 = insereElemento(f1,valor);
                
                printf ("\nElemento inserido a fila!\n");
                printf ("\n==========//==========\n");
                break;

            case 2:
                if (filaVazia(f1))
                    printf ("\nA fila esta vazia!\n");
                
                else {
                    f1 = retiraElemento(f1);
                    printf ("\nElemento retirado da fila!\n");
                }

                printf ("\n==========//==========\n");
                break;

            case 3:
                imprimeLista(f1);

                printf ("\n==========//==========\n");
                break;

            case 4:
                break;

            default:
                printf ("\nOpção invalida!\n");
                printf ("\n==========//==========\n");
        }

    } while (menu != 4);

    return 0;
}