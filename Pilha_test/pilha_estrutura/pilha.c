#include "pilha.h"
#include <stdlib.h>

Pilha* cria_pilha()
{
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    return p ;
}

void liberaPilha(Pilha* p)
{
    free(p);
}

int topo(Pilha* p)
{
    if(p->topo > 0)
    {
    return p->vet[p->topo - 1];
    }
    return -1;
}

int empilha(Pilha* p, int v)
{
    if(p->topo == MAX){
        return 0;
    }
    p -> vet[p->topo++] = v;
    return 1;
}
int desempilha(Pilha* p, int *v)
{
    if(p->topo == 0)
    {
        return 0;
    }
    *v = p->vet[p->topo -1];
    p->topo--;
    return 1;
}

int estacheio(Pilha* p)
{
    if( p->topo - 1== MAX)
    {

        return 1;
    }
    return 0;
}
int estavazio(Pilha* p)
{
    if(p-> topo == 0)
    {
        return 1;

    }
    return 0;
}