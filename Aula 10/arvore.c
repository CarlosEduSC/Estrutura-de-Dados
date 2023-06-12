#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct elemento {
    int conteudo;
    struct elemento *menor;
    struct elemento *maior;
};

typedef struct elemento *Arvore;

Arvore criaArvora() {
    Arvore a;
    a = NULL;
    return a;
}

int arvoreVazia(Arvore a) {
    if (a == NULL)
        return TRUE;

    else
        return FALSE;
}

void insereElemento (Arvore *a, int e) {
    if ((*a) == NULL) {
        
        (*a) = (Arvore)malloc(sizeof(struct elemento));
        (*a)->conteudo = e;
        (*a)->menor = NULL;
        (*a)->maior = NULL;

        printf("\nElemento inserido na arvore!\n");

    } else if (e < (*a)->conteudo) {
        insereElemento(&((*a)->menor),e);
    
    } else if (e > (*a)->conteudo) {
        insereElemento(&((*a)->maior),e);
    
    } else {
        printf("\nValor já pertence a arvore!\n");
    }
}

Arvore buscaElemento(Arvore a, int e) {
    if (a == NULL) {
        return NULL;
    
    } else if (e < a->conteudo) {
        return buscaElemento(a->menor,e);
    
    } else if (e > a->conteudo) {
        return buscaElemento(a->maior,e);
    
    } else {
        return a;
    }
}

void preOrdem(Arvore a) {
    if (a != NULL) {
        printf("\n%d", a->conteudo);
        preOrdem(a->menor);
        preOrdem(a->maior);
    }
}

void ordemAscendente (Arvore a) {
    if (a != NULL) {
        ordemAscendente(a->menor);
        printf("\n%d", a->conteudo);
        ordemAscendente(a->maior);
    }
}

void ordemDescendente (Arvore a) {
    if (a != NULL) {
        ordemDescendente(a->maior);
        printf("\n%d", a->conteudo);
        inOrdemDesc(a->menor);
    }
}

void posOrdem(Arvore a) {
    if (a != NULL) {
        posOrdem(a->menor);
        posOrdem(a->maior);
        printf("\n%d", a->conteudo);
    }
}

int main() {
    int valor,menu1,menu2;
    Arvore a1,aux;

    a1 = criaArvora(a1);

    do {
        printf("\n1- Insere um elemento na árvore.\n2- Busca um elemento da árvore.\n3- A remove um elemento da árvore.\n4- Imprime a arvore.\n5- Conferir se a arvore esta vazia.\n6- Sair.");

        printf("\nEscolha uma das opções acima: ");
        scanf("%d",&menu1);

        printf("\n==========//==========\n");


        switch (menu1) {
            case 1:
                printf("\nDgite o numero que deseja inserir na arvore: ");
                scanf("%d",&valor);

                insereElemento (&a1,valor);

                printf("\n==========//==========\n");
                break;

            case 2:
                printf("\nDgite o numero que deseja buscar na arvore: ");
                scanf("%d",&valor);

                aux = a1;

                aux = buscaElemento(a1,valor);

                if (arvoreVazia(a1) == TRUE) {
                    printf("\nArvore vazia!");
                
                } else if (aux == NULL) {
                    printf("\nElemento não encontrado!\n");
                
                } else {
                    printf("\nElemento encontrado!\n");
                }

                printf("\n==========//==========\n");
                break;

            case 3:
                break;

            case 4:
                printf("\n1- Percurso em pré-ordem.\n2- Percurso em in-ordem crescente.\n3- Percurso em in-ordem decrescente.\n4- Percurso em pós-ordem.\n");

                printf("\nEscolha com qual dos percursos acima deseja impremir a arvore: ");
                scanf("%d",&menu2);

                switch (menu2) {
                    case 1:
                        preOrdem(a1);
                        break;

                    case 2:
                        ordemAscendente(a1);
                        break;

                    case 3:
                        ordemDescendente(a1);
                        break;

                    case 4:
                        posOrdem(a1);
                        break;
                        
                    default:
                        printf("\nOpção de exibição invalida!\n");
                }

                printf("\n==========//==========\n");
                break;

            case 5:
                if (arvoreVazia(a1) == TRUE) {
                    printf("\nA arvore esta vazia!\n");

                } else {
                    printf("\nA arvore não esta vazia!\n");
                }
                
                printf("\n==========//==========\n");
                break;

            case 6:
                printf("\n==========//==========\n");
                break;

            default:
                printf("\nOpção invalida!\n");
                printf("\n==========//==========\n");
        }

    } while (menu1 != 6);
}