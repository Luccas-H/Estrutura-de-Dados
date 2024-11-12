#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Item;

typedef struct {
    int linhas;
    int colunas;
    int quantiElementos;  
    Item* elementos;
}matrizTriangular;

matrizTriangular* inicializa(int linhas, int colunas, int quantiElementos) {// Parte de alocar e inicializar a matriz
    matrizTriangular* matriz = (matrizTriangular*) malloc(sizeof(matrizTriangular));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->quantiElementos = 0;  
    matriz->elementos = (Item*) malloc(quantiElementos * sizeof(Item));
    return matriz;
}


int adicionaItem(matrizTriangular* matriz, int linha, int coluna, int valor) {// colocando os itens na matriz respeitando o numero de elementos
    if (matriz->quantiElementos < matriz->linhas * matriz->colunas) {
        matriz->elementos[matriz->quantiElementos++] = (Item) {linha, coluna, valor};
    } 
    return 0;
}


int pegaItem(matrizTriangular* matriz, int linha, int coluna) { //Pega cada item da matriz. É usado no método de imprimir
    for (int i = 0; i < matriz->quantiElementos; i++) {
        if (matriz->elementos[i].row == linha && matriz->elementos[i].col == coluna) {
            return matriz->elementos[i].value;
        }
    }
    return 0;
}

void imprimeMatriz(matrizTriangular* matriz) {// Imprime a matriz
    printf("Aqui esta a matriz triangular superior:\n");
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d ", pegaItem(matriz, i, j));
        }
        printf("\n");
    }
}

void triangularSuperior(matrizTriangular* matriz, int linhas, int colunas)// coloca a matriz no formato de uma matriz triangular inferior
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas ;j++)
        {
            if(i > j)
            {
                adicionaItem(matriz, i, j, 0);
            }
            else
            {
                adicionaItem(matriz, i, j, 1);
            }
        }
    }
}


void liberaMatriz(matrizTriangular* matriz) {// Libera a memoria após o uso *Importante*
    free(matriz->elementos);
    free(matriz);
}


int main() {

    int linhas;
    int colunas;
    int quantiElementos;

    printf("Digite o numero de linhas e colunas da matriz na ordem l c: \n(Lembrando que ela deve ser quadrada do tipo nxn)\n");
    scanf("%d %d", &linhas, &colunas);

    
    if(linhas == colunas)// Verifica se a matriz é quadrada
    {
        printf("Digite o numero de elementos (Lembre que a quantia de elementos e linhas x colunas): \n");
        scanf("%d", &quantiElementos);

        matrizTriangular* matriz = inicializa(linhas, colunas, quantiElementos);

        if(quantiElementos < linhas*colunas)//verifica se a quantia de elementos bate com a multiplicação das linhas pelas colunas
        {
            printf("Ocorreu um erro de numero de elementos \nTente novamente e se atente ao numero de elementos na matriz");

        }
        else
        {
            triangularSuperior(matriz, linhas, colunas);
            imprimeMatriz(matriz);
        }


        liberaMatriz(matriz);
    }
    else
    {
        printf("ERRO!! \nPara a matriz ser triangular ela deve ser quadrada! (linhas = colunas)");
    }

    return 0;
}