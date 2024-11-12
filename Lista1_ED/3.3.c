#include <stdio.h>
#include <stdlib.h>

void inverte(int n, int* vet, int* vetinvert)
{
    
    for(int i = 0; i<n; i++)
    {
        int aux;
        aux = vet[i];
        vetinvert[n-i-1] = aux;

    }

}

int main()
{
    int indiceVetor;
    printf("Digite o numero de itens do vetor: \n");
    scanf("%d", &indiceVetor);
    
    int* vetor = (int*)malloc(indiceVetor*sizeof(int));
    int* vetorInvertido = (int*)malloc(indiceVetor*sizeof(int));

    for (int i =0; i<indiceVetor; i++)
    {
        printf("Digite o item %d do vetor: \n",i);
        scanf("%d", &vetor[i]);
    }

    inverte(indiceVetor, vetor,vetorInvertido);

    printf("Vetor principal: ");
    printf("[");
    for (int i = 0; i<indiceVetor;i++)
    {
        (i == indiceVetor -1)?printf("%d",vetor[i]):printf("%d,",vetor[i]);
    }
    printf("]");

    printf("\n");

    printf("Vetor invertido: ");
    printf("[");
    for (int i =0; i<indiceVetor; i++)
    {
        (i == indiceVetor -1)?printf("%d",vetorInvertido[i]):printf("%d,",vetorInvertido[i]);
    }
    printf("]");
    
    free(vetorInvertido);
    free(vetor);
}