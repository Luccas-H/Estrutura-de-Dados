#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


float delta(float a, float b, float c)    
{
    float delta = (pow(b,2)) - (4*a*c);
    if(delta < 0)
    {
        return delta;
    }
    else
    {
        return sqrt(delta);
    }
}

int raizes (float a, float b, float c, float* x1, float* x2, char* strConsquencia)
{
    int quantiaRaizes = 1;

    if(delta(a,b,c) < 0.0)
    {
        char str[50] = "Nao existem raizes reais";
        strcpy(strConsquencia, str);
        return quantiaRaizes - 1;
    }
    else
    {
         
        if(delta(a,b,c) == 0.0)
        {
            *x1 = (-b + delta(a,b,c)) / (2.0*a);
            *x2 = *x1;
            return quantiaRaizes;
        }
        else
        {
            *x1 = (-b + delta(a,b,c)) / (2.0*a);
            *x2 = (-b - delta(a,b,c)) / (2.0*a);
            return quantiaRaizes + 1;
        }
    }

    return 0;
}

int main()
{
    float raiz1;
    float raiz2;
    char consequencia[100];
    float a,b,c;

    printf("Digite os coeficientes em ordem a b c: \n");
    scanf("%f %f %f",&a,&b,&c);

    int numeroRaizes = raizes(a,b,c,&raiz1,&raiz2,consequencia);
    if(numeroRaizes == 0)
    {
        printf("%s\n", consequencia);
    }
    else
    {
        (numeroRaizes == 1) ? printf("O numero de raizes = %d \nx1=x2=%.3f\n", numeroRaizes,raiz1) : printf("O numero de raizes = %d \nx1 = %.3f\nx2 = %.3f\n",numeroRaizes,raiz1,raiz2);
    } 
}