#include <stdio.h>
#include <stdbool.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y )
{   
    bool condicaoX = (x <= x1 && x >= x0) ? true : false; //Ternario pra ver se o x está entre x0 ponta esquerda e x1 ponta direita
    bool condicaoY = (y <= y1 && y >= y0) ? true : false; //Ternario pra ver se o y está entre y0 ponta esquerda e y1 ponta direita
    int result = (condicaoX && condicaoY) ? 1: 0;//Ternario pra ver se a duas condições acima são verdadeiras

    return result;
}

int main()
{
    int x0, y0, x1, y1, x, y;
    printf("Digite a posição do retangulo seguindo a ordem e a forma de digitação: x0 y0 x1 y1 x y:\n");
    scanf("%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &x, &y);
    printf("%d", dentro_ret(x0,y0,x1,y1,x,y));
    
    return 0;
}