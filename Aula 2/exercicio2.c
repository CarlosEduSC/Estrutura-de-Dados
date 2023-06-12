#include <stdio.h>

float areRetangulo (float b,float a) {

    float resul;

    resul = b*a;

    return resul;
}

int main () {

    float area,base,altura;

    printf ("\nDigite o valor da base do retangulo: ");
    scanf ("%f",&base);

    printf ("\nDigite o valor da altura do aretangulo: ");
    scanf ("%f",&altura);

    area = areRetangulo (base,altura);

    printf ("\nA area do retangulo eh: %.1f\n",area);

    return 0;
}