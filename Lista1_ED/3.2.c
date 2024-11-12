#include <stdio.h>
#include <stdlib.h>

int pares(int n, float* vet)
{
    int contNumPares = 0;
    for(int i = 0; i <n; i++)
    {
        int checkpar = vet[i];
        if(checkpar%2 == 0)
        {
            contNumPares += 1;
        }
    }
    return contNumPares;
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

    int numerosPares = pares(indiceVetor, vetor);

    printf("%d", numerosPares);

    free(vetor);
}