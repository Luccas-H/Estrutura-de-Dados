#include <stdio.h>
#include <math.h>

double pi (int n )
{
    double soma =0;
    double fracao;
    int i = 0;
    
   while(n >= 0)
   {
    fracao = pow(-1.0,i) / (2.0*i + 1.0);
    soma = soma + fracao;
    i +=1;
    n -=1;
   }
    return soma* 4;
}

int main()
{
    int n;
    printf("Digite o numero de termos: \n");
    scanf("%d", &n);
    printf("%lf", pi(n));
    return 0;
}