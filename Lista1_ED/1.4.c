#include <stdio.h>

int soma_impares_demorado (int n)
{
    int soma = 0, numero_incio = 1;
    while(n != 0)
    {
        if(numero_incio%2 != 0)
        {
            soma = soma + numero_incio;
            n -=1;
        }
        numero_incio +=1;
    }
    printf("%d\n", soma);

    return 0;
}

int soma_impares_rapido (int n)
{
    return n*n; // a soma de n numeros impares é igual a n^2
}

int main()
{
    int n;
    printf("Digite até que termo quer ir: ");
    scanf("%d", &n);

    soma_impares_demorado(n);
    printf("Jeito rapido: %d", soma_impares_rapido(n));

    return 0;
}