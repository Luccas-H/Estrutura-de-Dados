#include <stdio.h>
#include <stdlib.h>

int matrizAlocadaBloco() // aloca um bloco de memoria pra matriz
{
    int linhas, colunas;
    printf("Digite o numero de linhas e colulas da matriz nessa ordem l c: \n");
    scanf("%d %d", &linhas, &colunas);
    printf("\n");

    int *matriz = (int *)malloc(linhas * colunas * sizeof(int)); // Alocando o bloco 

    if(matriz == NULL)// Prevenção pra não dar ruim
    {
        printf("Erro de alocacao");
        return 1;
    }

    if(linhas == colunas)
    {
        printf("A matriz e simetrica quadrada e tem esse formato:\n");

        int contador = 1;
        for (int i = 0; i<linhas; i ++)// Acessa a matriz 
        {
            for(int j = 0;j<colunas;j++)
            {
                
                matriz[i*colunas + j] = contador++; // Inicializando a matriz adicionando 1 e incrementando contador
            }
        }

        for(int i = 0; i < linhas; i++)
        {
            for(int j = 0; j< colunas; j++)
            {
                printf("%d ", matriz[i*colunas + j]);
            }
            printf("\n");
        }
        
    }
    else
    {
        printf("A matriz indicada nao e simetrica quadrada.\n");
    }
    free(matriz);// Libera aquele espaço alocado. Como é um bloco de memoria então não preciso liberar cada linha
    return 0;
}

int matrizAlocadaArray()//aloca um array de ponteiros para as linhas  
{
    int linhas, colunas;

    printf("Digite o numero de linhas e colulas da matriz nessa ordem l c: \n");
    scanf("%d %d", &linhas, &colunas);
    printf("\n");

    int** matriz = (int **)malloc(linhas* sizeof(int*));// array de ponteiros pra linhas

    if(matriz == NULL)
    {
        printf("Erro de alocacao de memoria");
        return 1;
    }
    if(linhas == colunas)
    {
        for(int i = 0; i< linhas; i++)
        {
        // Alocação de memoria pra cada linha. Como se eu falasse quanto de memoria cada linha vai precisar. Meio confuso ainda!
        //eu como se eu falasse quantas colunas vão ter em uma linha. Ex: 4 cols -> linha = [1º coluna,2º coluna,3º coluna,4º coluna]
            matriz[i] = (int*)malloc(colunas*sizeof(int));   
            if(matriz[i] == NULL)
            {
                printf("Erro de alocacao de memoria");
                return 1;
            }
        }
        printf("A matriz e simetrica quadrada e tem esse formato:\n");
        int contador =1;
        for(int i = 0; i<linhas;i++)
        {
            for(int j=0;j<colunas;j++)
            {
                matriz[i][j]= contador++;// adiciona 1 e acrescenta +1 para a variavel contador
                printf("%d ", matriz[i][j]);

            }
        printf("\n");
        }

        for(int i = 0;i<linhas;i++)
        {
            free(matriz[i]); 
            //libera a memoria de cada linha da matriz
            //como eu aloco memoria pra cada linha preciso também liberar pra cada uma delas
        }
    }
    else
    {
        printf("A matriz indicada nao e simetrica quadrada.\n");
    }

    return 0;
}  

int main()
{
    matrizAlocadaBloco();
    matrizAlocadaArray();
}