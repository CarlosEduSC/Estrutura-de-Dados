#include <stdio.h>

float areRetangulo (float b,float a) {

    float resul;

    resul = b*a;

    printf ("\nA area do retangulo eh: %.1f\n",resul);
}

int main () {

    float base,altura;

    printf ("\nDigite o valor da base do retangulo: ");
    scanf ("%f",&base);

    printf ("\nDigite o valor da altura do aretangulo: ");
    scanf ("%f",&altura);

    areRetangulo (base,altura);

    return 0;
}