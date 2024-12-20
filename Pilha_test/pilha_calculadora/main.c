#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculadora.h"

int main() {
    char c;
    float v;
    Calc *calc;
    Pilha* p;

    calc = calc_cria("%.2f\n");
    do {
        scanf(" %c", &c);
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            calc_operador(calc, c);
        } else {
            ungetc(c, stdin);
            if (scanf("%f", &v) == 1) {
                calc_operando(calc, v);
            }
        }
    } while (c != 'q');
    calc_libera(calc);;
    system("PAUSE");
    return 0;
}
