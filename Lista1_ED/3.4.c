#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double avalia (double* poli, int grau, double x)
{
    double soma = 0;
    for(int i= 0; i<=grau; i++)
    {
        double aux = poli[i];
        double op = (aux*(pow(x,i)));
        soma = soma + op;
    }
    return soma;
}


int main()
{   
    int grau;
    printf("Digite o maior grau do polinomio: \n");
    scanf("%d", &grau);

    double* vetorCoeficientes = (double*)malloc(grau * sizeof(double));
    for(int i = grau; i>=0; i--)
    {
        printf("Digite os coeficientes do polinomio em ordem do maior grau ao menor, se nao existir digite 0: \n");
        scanf("%lf",&vetorCoeficientes[i] );
    }

    double numeroX;

    printf("Digite o numero para o qual deseja avaliar o polinomio: ");
    scanf("%lf", &numeroX);

    double resultado = avalia(vetorCoeficientes, grau, numeroX);

    printf("Para x = %.1lf temos que p(%.1lf) = %.3lf", numeroX,numeroX,resultado );

    free(vetorCoeficientes);
}