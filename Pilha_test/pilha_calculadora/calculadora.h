#define MAX 100

typedef struct pilha
{
    int topo;
    int vet[MAX];

}Pilha;

struct calc {
    char f[21];
    Pilha *p;
};
typedef struct calc Calc;

Pilha* cria_pilha();
void liberaPilha(Pilha* p);
int empilha(Pilha* p, int v);
int desempilha(Pilha* p);
int estacheio(Pilha* p);
int estavazio(Pilha* p);
int topo(Pilha* p);