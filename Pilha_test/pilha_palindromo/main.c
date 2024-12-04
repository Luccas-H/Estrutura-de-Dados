#include "palindromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    
    Pilha* p = cria_pilha();
    char palavra[100];
    printf("Digite uma palavra ou frase: ");
    
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    for(int i =0; palavra[i] != '\0'; i++ )
    {
        empilha(p,palavra[i]);
    }
    

    if (palindromo(p)) {
        printf("e um palindromo\n");
    } else {
        printf("nao e um palindromo\n");
    } 
    system("PAUSE");
    liberaPilha(p);
    return 0;
}