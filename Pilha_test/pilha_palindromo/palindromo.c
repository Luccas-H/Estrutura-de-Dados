#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palindromo.h"

Pilha* cria_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL) p->topo=0;
    return p;
}

int topo(Pilha* p)
{
    if(p->topo > 0)
    {
    return p->vet[p->topo - 1];
    }
    return -1;
}

int empilha(Pilha* p, char v)
{
    if(p->topo == MAX){
        return 0;
    }
    p -> vet[p->topo++] = v;
    return 1;
}
int palindromo(Pilha* p) {
    int inicio = 0;
    int fim = p->topo - 1;

    while (inicio < fim) {
        
        while (inicio < fim && !isalpha(p->vet[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalpha(p->vet[fim])) {
            fim--;
        }

        if (tolower(p->vet[inicio]) != tolower(p->vet[fim])) {
            return 0;
        }

        inicio++;
        fim--;
    }

    return 1;
}

void liberaPilha(Pilha* p) {
    free(p);
}