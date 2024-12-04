#include "calculadora.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct calc Calc;
Pilha* cria_pilha()
{
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    return p ;
}

Calc *calc_cria(char *formato) {
    Calc *c = (Calc *)malloc(sizeof(Calc));
    strcpy(c->f, formato);
    c->p = cria_pilha();
    return c;
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
int desempilha(Pilha* p)
{
    if(p->topo == 0)
    {
        return 0;
    }
    if(p->topo >= 0)
    {
        int valor = p->vet[p->topo -1];
        p->topo--;
        return valor;
    }
    return 1;
    
}
int estavazio(Pilha* p)
{
    if(p-> topo == 0)
    {
        return 1;

    }
    return 0;
}

void calc_operando(Calc *c, float v) {
    empilha(c->p, v);
    printf(c->f, v);
}

void calc_operador(Calc *c, char op) {
    float v1, v2, v;
    if (estavazio(c->p)) {
        v2 = 0.0;
    } 
    else {
        v2 = desempilha(c->p);
    }

    if (estavazio(c->p)) {
        v1 = 0.0;
    }
    else {
        v1 = desempilha(c->p);
    }
    switch (op) {
        case '+': v = v1 + v2; break;
        case '-': v = v1 - v2; break;
        case '*': v = v1 * v2; break;
        case '/': v = v1 / v2; break;
    }
    
    empilha(c->p, v);
    printf("Resultado: %.2f\n", v,c->f);
}
void liberaPilha(Pilha* p)
{
    free(p);
}

void calc_libera(Calc *c) {
    liberaPilha(c->p);
    free(c);
}
