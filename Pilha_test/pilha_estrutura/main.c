#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main()
{
    int v;
    Pilha* p = cria_pilha();
    empilha(p, 20);
    empilha(p, 30);

    if (estacheio(p)) {
        printf("A pilha está cheia!\n");
    } else {
        printf("A pilha NÃO está cheia.\n");
    }
    

    if (estavazio(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("A pilha NÃO está vazia.\n");
    }

    printf("Topo da pilha: %d\n", topo(p));
    if (desempilha(p, &v)) {
        printf("Desempilhado: %d\n", v);
    }
    printf("Topo da pilha após desempilhar: %d\n", topo(p));
    liberaPilha(p);
    system("PAUSE");
    return 0;
}