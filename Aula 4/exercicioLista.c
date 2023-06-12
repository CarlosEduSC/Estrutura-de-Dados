#include <stdio.h>
#include <string.h>

#define MaxItens 10
#define TamItem 20

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

typedef char tipoLista[MaxItens][TamItem];

void inserirItem (tipoLista l, char i[TamItem]) {

    int j;

    for (j=0;j < MaxItens && strlen(l[j]) > 0;j++);

    if (j < MaxItens) {

        strcpy (l[j],i);


        printf ("\nItem inserido com sucesso!\n");
        printf ("\n==========//==========\n");
    
    } else
        printf ("\nLista cheia, item '%s' nao pode ser inserido!",i);
}

void retirarItem (tipoLista l, char i[TamItem]) {

    int j;

    for (j=0;j < MaxItens && strlen(l[j]) > 0 && (strcmp(l[j],i)) != 0;j++);

    if (strcmp(l[j],i) == 0) {

        if (j == (MaxItens-1))
            l[MaxItens-1][0] = '\0';

        else {
            for (;j < (MaxItens-1) && strlen(l[j]) > 0;j++)
                strcpy(l[j],l[j+1]);

            l[MaxItens-1][0] = '\0';
        }

        printf ("\nItem removido com sucesso!\n");
        printf ("\n==========//==========\n");
    
    } else
        printf ("\nItem '%s' nao encontrado!",i);
}

void criarLista (tipoLista l) {

    int j;

    for (j=0;j < MaxItens;j++)
        l[j][0] = '\0';
}

int contarElementos (tipoLista l) {

    int j;

    for (j=0;j < MaxItens && strlen(l[j]) > 0;j++);

    return j;
}

void exibirConteudo (tipoLista l) {

    int j;

    printf ("\n===ITEMS DA LISTA===\n");

    for (j=0;j < MaxItens && strlen(l[j]) > 0;j++) {

        printf ("\n%s\n",l[j]);
    }
}

int main () {

    int menu;
    char item[TamItem];
    tipoLista Lista;

    criarLista (Lista);

    do {

        printf ("\n1- Inserir item na lista.\n2- Remover item da lista.\n3- Contar itens da lista.\n4- Exibir conteudo da lista.\n5- Sair\n");

        printf ("\nEscolha uma das opcoes acima: ");
        scanf ("%d",&menu);
        flush_in();

        printf ("\n==========//==========\n");

        switch (menu) {

            case 1:
                printf ("\nDigite o item que deseja inserir na lista: ");
                fgets (item,20,stdin);

                inserirItem (Lista,item);
                break;

            case 2:
                printf ("\nDigite o item que deseja remover da lista: ");
                fgets (item,20,stdin);

                retirarItem (Lista,item);
                break;

            case 3:
                printf ("\nA lista tem %d itens!\n",contarElementos(Lista));
                printf ("\n==========//==========\n");
                break;

            case 4:
                exibirConteudo (Lista);
                printf ("\n==========//==========\n");
                break;

            case 5:
                break;

            default:
                printf ("\nOpcao invalida!\n");
                printf ("\n==========//==========\n");
        }
    
    } while (menu != 5);

    return 0;
}