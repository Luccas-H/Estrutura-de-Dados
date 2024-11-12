#include <stdio.h>
#include <stdlib.h>

int negativos(int n, float* vet)
{
    int contNumNegativos = 0;
    for(int i = 0; i <n; i++)
    {
        if(vet[i] < 0)
        {
            contNumNegativos +=1;
        }
    }
    return contNumNegativos;
}

int main()
{
    int indiceVetor;
    printf("Digite o numero de itens do vetor: \n");
    scanf("%d", &indiceVetor);

    
    float* vetor = (float*)malloc(indiceVetor*sizeof(float));

    for (int i =0; i<indiceVetor; i++)
    {
        printf("Digite o item %d do vetor: \n",i);
        scanf("%f", &vetor[i]);
    }

    int numerosNegativos = negativos(indiceVetor, vetor);

    printf("%d", numerosNegativos);

    free(vetor);
}