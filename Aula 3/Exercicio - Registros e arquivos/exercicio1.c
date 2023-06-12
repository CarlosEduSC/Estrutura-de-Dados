#include <stdio.h>

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}


float media (float nota1,float nota2) {

    float soma,notafinal;

    soma = nota1+nota2;
    notafinal = soma/2;

    return notafinal;
}

int situacao (float media, int faltas) {

    char resultado;

    if (media >= 6 && faltas <= 20)
        resultado = 'A';

    else if (media < 6 && faltas > 20)
        resultado = 'R';

    return resultado;
}


int main () {

    struct aluno {
        int numMatricula;
        char nome[40];
        float prova1;
        float prova2;
        int faltas;
        float media;
        char situacao;
    };

    int numAlunos,i,cont=1,menu;
    char c;
    struct aluno turma[40];
    FILE *pont_arq;

    printf ("\nQual a quantidade de alunos da turma? ");
    scanf ("%d",&numAlunos);
    

    for (i=0;i < numAlunos;i++) {

        turma[i].numMatricula = i+1;

        printf ("\nNumero de matricula do aluno: %d\n",turma[i].numMatricula);
        flush_in();

        printf ("\nDigite o nome do aluno: ");
        fgets (turma[i].nome,40,stdin);

        printf ("\nDigite a nota do aluno na primeira prova: ");
        scanf ("%f",&turma[i].prova1);

        printf ("\nDigite a nota do aluno na segunda prova: ");
        scanf ("%f",&turma[i].prova2);

        turma[i].media = media (turma[i].prova1,turma[i].prova2);

        printf ("\nA media do aluno eh: %.1f\n",turma[i].media);

        printf ("\nDigite o numero de faltas do aluno: ");
        scanf ("%d",&turma[i].faltas);

        turma[i].situacao = situacao (turma[i].media,turma[i].faltas);

        if (turma[i].situacao == 'A')
            printf ("\nO aluno esta aprovado.\n");

        else if (turma[i].situacao == 'R')
            printf ("\nO aluno esta reprovado.\n");

        cont++;

        printf ("\n==========//==========\n");

    }

    do {
        printf ("\n1 - Inserir aluno.\n2 - Listar alunos.\n3 - Salvar dados.\n4 - Carregar dados.\n5 - Sair do programa.\n");

        printf ("\nEscolha uma das opcoes acima: ");
        scanf ("%d",&menu);
    

        printf ("\n==========//==========\n");

        switch (menu) {

            case 1:
                
                turma[cont].numMatricula = cont;

                printf ("\nNumero de matricula do aluno: %d\n",turma[cont].numMatricula);
                flush_in();

                printf ("\nDigite o nome do aluno: ");
                fgets (turma[cont].nome,40,stdin);

                printf ("\nDigite a nota do aluno na primeira prova: ");
                scanf ("%f",&turma[cont].prova1);

                printf ("\nDigite a nota do aluno na segunda prova: ");
                scanf ("%f",&turma[cont].prova2);

                turma[cont].media = media (turma[cont].prova1,turma[cont].prova2);

                printf ("\nA media do aluno eh: %.1f\n",turma[cont].media);

                printf ("\nDigite o numero de faltas do aluno: ");
                scanf ("%d",&turma[cont].faltas);

                turma[cont].situacao = situacao (turma[cont].media,turma[cont].faltas);

                if (turma[cont].situacao == 'A')
                    printf ("\nO aluno esta aprovado.\n");

                else if (turma[cont].situacao == 'R')
                    printf ("\nO aluno esta reprovado.\n");

                cont++;

                printf ("\n==========//==========\n");

                break;

            case 2:

                for (i=0;i < cont;i++) {

                    printf ("\n===%dº aluno===\n",i+1);

                    printf ("\nNumero de matricula: %d\n",turma[i].numMatricula);

                    printf ("\nNome: %s",turma[i].nome);

                    printf ("\nNota da primeira prova: %.1f\n",turma[i].prova1);

                    printf ("\nNota da segunda prova: %.1f\n",turma[i].prova2);

                    printf ("\nMedia: %.1f\n",turma[i].media);

                    printf ("\nNumero de faltas: %d\n",turma[i].faltas);

                    printf ("\nSituacao (A- Aprovado / R- Reprovado): %c\n",turma[i].situacao);

                    printf ("\n==========//==========\n");
                }

                break;

            case 3:

                pont_arq = fopen("registroTurma.txt","w");

                if (pont_arq == NULL)
                    printf ("\nERRO! O arquivo não foi aberto!\n");

                else
                    printf ("\nO arquivo foi aberto com sucesso!");

                for (i=0;i < cont;i++) {
                    fprintf (pont_arq,"\n===%dº aluno===\n",i+1);
                    fprintf (pont_arq,"\nNumero de matricula: %d\n",turma[i].numMatricula);
                    fprintf (pont_arq,"\nNome: %s",turma[i].nome);
                    fprintf (pont_arq,"\nNota da primeira prova: %.1f\n",turma[i].prova1);
                    fprintf (pont_arq,"\nNota da segunda prova: %.1f\n",turma[i].prova2);
                    fprintf (pont_arq,"\nMedia: %.1f\n",turma[i].media);
                    fprintf (pont_arq,"\nNumero de faltas: %d\n",turma[i].faltas);
                    fprintf (pont_arq,"\nSituacao (A- Aprovado / R- Reprovado): %c\n",turma[i].situacao);
                    fprintf (pont_arq,"\n==========//==========\n");
                }

                fclose(pont_arq);

                printf ("\nDados salvos com sucesso!\n");

                printf ("\n==========//==========\n");

                break;

            case 4:

                pont_arq = fopen ("registroTurma.txt","r");

                if (pont_arq == NULL)
                    printf ("\nERRO! O arquivo não foi aberto!\n");

                else
                    printf ("\nO arquivo foi aberto com sucesso!\n");

                do {
                    c = getc(pont_arq);

                    printf ("%c",c);
                
                } while (c !=  EOF);

                fclose(pont_arq);

                break;

            case 5:
                break;

            default:
                printf ("\nA opcao escolhida eh invalida!\n");
        }
        
    } while (menu != 5);

    return 0;
}