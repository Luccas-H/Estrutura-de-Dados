#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double avalia (double* poli, int grau, double* out)
{
    double multiCoeficienteExp;
    for(int i = 0;i<=grau;i++)
    {
        double aux = poli[i];
        multiCoeficienteExp = aux*i;
        out[i] = multiCoeficienteExp;
    }
    return 0;
}

int main()
{   
    int grau;
    printf("Digite o maior grau do polinomio: \n");
    scanf("%d", &grau);

    double* vetorCoeficientes = (double*)malloc(grau * sizeof(double));
    double* out = (double*)malloc(grau*sizeof(double));

    for(int i = grau; i>=0; i--)
    {
        printf("Digite os coeficientes do polinomio em ordem do maior grau ao menor, se nao existir digite 0: \n");
        scanf("%lf",&vetorCoeficientes[i] );
    }


    avalia(vetorCoeficientes, grau, out);

    for(int i = grau; i>=0 ;i--)
    {
        printf("A derivada do polinomio fornecido tem coeficiente(s): ");
        (i - 1 >= 0) ?printf("%.2lfx^%d\n", out[i], i - 1) : printf("%.2lf\n", out[i]);
    }

    free(vetorCoeficientes);
    free(out);
}