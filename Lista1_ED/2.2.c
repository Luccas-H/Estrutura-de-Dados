#include <stdio.h>
#include <math.h>


void calc_esfera(float r, float* area, float* volume)
{
    *area = 4*pow(r,2);
    *volume = (4*pow(r,3))/3.0;

}
int main()
{
    float raio, area, volume;
    printf("Digite o raio em cm: \n");
    scanf("%f", &raio);

    calc_esfera(raio,&area,&volume);

    printf("Area da superficie da esfera de raio %.2f = %.3f \nVolume da esfera de raio %.2f = %.3f", raio, area, raio, volume);

    return 0;
}   