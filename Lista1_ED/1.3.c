#include <stdio.h> 

int fibonacci (int n)
{
    int inicial_valor = 1,proximo_valor = 0, resultado;
        
    while(n!=0)
    {
        resultado = inicial_valor + proximo_valor;
        printf("%d ", inicial_valor);
        proximo_valor = inicial_valor;
        inicial_valor = resultado;
        n-=1; 
    }
    return 0;
}

int main()
{
    int n;
    printf("Digite até que termo quer ir: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}