#include <stdio.h>

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int soma (int a, int b) {

    int resul;

    resul = a+b;

    return resul;
}

int mult (int a, int b) {

    int resul;

    resul = a*b;

    return resul;

}

int sub (int a, int b) {

    int resul;

    resul = a-b;

    return resul;

}

int div (int a, int b) {

    int resul;

    resul = a/b;

    return resul;

}

int calculo (int x, int y,char op) {

    int resul;

    if (op == '+') {

        resul = soma (x,y);

        printf ("\nO resultado da soma dos dois numeros eh: %d\n",resul);
    
    } else if (op == '*') {       
        
        resul = mult (x,y);

        printf ("\nO resultado da multiplicacao dos dois numeros eh: %d\n",resul);
    
    } else if (op == '-') {       
        
        resul = sub (x,y);

        printf ("\nO resultado da subtracao dos dois numeros eh: %d\n",resul);
    
    } else if (op == '/') {
        
        resul = div (x,y);

        printf ("\nO resultado da divisao dos dois numeros eh: %d\n",resul);
    }

    printf ("\n==========//==========\n");

}

int main () {

    int num1,num2,resul;
    char menu;

    do {

        printf ("\nSoma +\nMultiplicacao *\nSubtracao -\nDivisao /\nSair #\n");

        printf ("\nEscolha uma das opcoes a cima: ");
        scanf ("%c",&menu);

        printf ("\n==========//==========\n");

        if (menu != '+' && menu != '*' && menu != '-' && menu != '/' && menu != '#') {

            printf ("\nOpcao invalida!\n");

            printf ("\n==========//==========\n");
        }

        else if (menu == '#')
            break;
        
        else {

             printf ("\nDigite o primeiro numero: ");
            scanf ("%d",&num1);

            printf ("\nDigite o segundo numero numero: ");
            scanf ("%d",&num2);

            printf ("\n==========//==========\n");

            calculo(num1,num2,menu);

        }

        flush_in ();
        
        } while (menu != '#');

    return 0;
}