#include "calculadora.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct calc {
    char f[21];
    Pilha *p;
};

typedef struct calc Calc;

Calc *calc_cria(char *formato) {
    Calc *c = (Calc *)malloc(sizeof(Calc));
    strcpy(c->f, formato);
    c->p = cria_pilha();
    return c;
}

void calc_operando(Calc *c, float v) {
    pilha_push(c->p, v);
    printf(c->f, v);
}

void calc_operador(Calc *c, char op) {
    float v1, v2, v;
    if (pilha_vazia(c->p))
        v2 = 0.0;
    else
        v2 = desempilha(c->p);
    if (pilha_vazia(c->p))
        v1 = 0.0;
    else
        v1 = desempilha(c->p);
    
    switch (op) {
        case '+': v = v1 + v2; break;
        case '-': v = v1 - v2; break;
        case '*': v = v1 * v2; break;
        case '/': v = v1 / v2; break;
    }
    
    pilha_push(c->p, v);
    printf(c->f, v);
}

void calc_libera(Calc *c) {
    pilha_libera(c->p);
    free(c);
}
