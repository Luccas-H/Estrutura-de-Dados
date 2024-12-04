#define MAX 100

typedef struct pilha
{
    int topo;
    char vet[MAX];
}Pilha;

Pilha* cria_pilha();
void liberaPilha(Pilha* p);
int empilha(Pilha* p, char v);
int palindromo(Pilha* p);
int topo(Pilha* p);
