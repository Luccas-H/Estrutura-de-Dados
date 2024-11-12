#include <stdio.h>

int primo (int n)
{
    int divisor = 2;

    while(n%divisor!=0 && divisor*divisor<=n) // se o numero não sobrar resto 0 e o divisor*divisor for menor ou igual ele incrementa até quebrar o loop, depois compara no ternário a mesma multiplicação. 
    {
        divisor+=1;
    }

    int resultado = (divisor*divisor<=n) ? 0: 1; // Retorna 1 se for primo e 0 para não primo

    return resultado;
}

int main()
{
    int n;
    printf("Digite um numéro inteiro positivo maior que 1: ");
    scanf("%d", &n);

    printf("%d", primo(n));
    return 0;
}