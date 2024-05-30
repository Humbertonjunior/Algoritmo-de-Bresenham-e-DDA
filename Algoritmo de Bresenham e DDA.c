// Jose Augusto Figureiroa Neto
// Humberto Nascimento Santos Junior

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void valores(int *codX1, int *codY1, int *codX2, int *codY2);
void calculoDDA(double codX1, double codY1, double codX2, double codY2);
void Algoritmobresenham(int x1, int y1, int x2, int y2);
void imprimirpixel(int X, int Y);
void irParaXY(int x, int y);
void planoCartesiano(void);
int setX(int x);
int setY(int y);
void valores2(int *xc, int *yc, int *r);
void circulobresenham(int xc, int yc, int r);


int main() {
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
    int operacao;
    int x1, y1, x2, y2,xc,yc,r;
    printf("(0) - Sair\n");
    printf("(1) - Imprime uma reta (Algoritmo DDA)\n");
    printf("(2) - Imprime uma reta (Algoritmo de Bresenham)\n");
    printf("(3) - Imprime o traçado de um circulo (Algoritmo de Bresenham)\n");
    printf("Qual opcao voce quer escolher? ");
    scanf("%d", &operacao);

    switch (operacao) {
        case 0:

             break;

        case 1:
            system("cls");
            valores(&x1, &y1, &x2, &y2);
            calculoDDA(x1, y1, x2, y2);
            planoCartesiano();
            break;
        case 2:
            system("cls");
            valores(&x1, &y1, &x2, &y2);
            Algoritmobresenham(x1, y1, x2, y2);
            planoCartesiano();
            break;
        case 3:
            system("cls");
            valores2(&xc, &yc, &r);
            circulobresenham(xc,yc,r);
            planoCartesiano();
            break;
        default:
            printf("Operação inválida!\n");
            main();
            break;
    }





    return 0;
}


void valores(int *codX1, int *codY1, int *codX2, int *codY2) {
    printf("Digite o X inicial: ");
    scanf("%d", codX1);
    printf("Digite o Y inicial: ");
    scanf("%d", codY1);
    printf("Digite o X final: ");
    scanf("%d", codX2);
    printf("Digite o Y final: ");
    scanf("%d", codY2);
}
void valores2(int *xc, int *yc, int *r) {
    printf("Digite a cordenada de X: ");
    scanf("%d", xc);
    printf("Digite a cordenada de Y: ");
    scanf("%d", yc);
    printf("Digite o raio: ");
    scanf("%d", r);
}
void calculoDDA(double codX1, double codY1, double codX2, double codY2){
    double deltax, deltay, step, x, y, xi, yi;

    deltax = codX2 - codX1;
    deltay = codY2 - codY1;

    if(fabs(deltax) > fabs(deltay)) {
        step = fabs(deltax);
    } else {
        step = fabs(deltay);
    }

    xi = deltax / step;
    yi = deltay / step;

    x = codX1;
    y = codY1;

    for(int i = 0; i < step; i++) {
        imprimirpixel(x, y);
        x += xi;
        y += yi;

    }
}

void Algoritmobresenham(int x1, int y1, int x2, int y2){
    int deltax,deltay,p,p2,xy2,x,y,xf;

    deltax = x2-x1;
    deltay = y2-y1;

    p = 2 * deltay - deltax;
    p2 = 2 * deltay;
    xy2 = 2 * (deltay-deltax);

    if (x1>x2)
    {
        x = x2; y = y2; xf = x1;
    }
    else
    {
        x = x1; y = y1; xf = x2;
    }

    while (x<xf)
    {
        x++;
        if (p<0)
            p += p2;
        else
        {
            y++;
            p += xy2;
        }
        imprimirpixel(x, y);
    }
}
void circulobresenham(int xc, int yc, int r){
  int x = 0, y = r, d, i = 0;
  imprimirpixel(x, y);
  d = 1 - r;

  while (y >= x)
    {
        x++;
    if (d > 0)
        {
            y--;
            d = d + 2 * (x - y) + 5;
        }
        else{
            d = d + (2 * x) + 3;}

        imprimirpixel(x,  y);
        imprimirpixel(x, -y);
        imprimirpixel(-x, y);
        imprimirpixel(-x,-y);

    }
}
void imprimirpixel(int X, int Y){
    irParaXY(setX(round(X)), setY(round(Y)));
    printf("%c", 178);
}


void irParaXY(int x, int y) {
    COORD coord;
    coord.X = (short) x;
    coord.Y = (short) y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void planoCartesiano(void){
    int vertical, horizontal;
    for (vertical = 14; vertical < 55 ; vertical++) {
        irParaXY(118, vertical);
        printf("|");
    }

    for (horizontal = 18; horizontal < 219; horizontal++) {
        irParaXY(horizontal, 34);
        printf("-");
    }

    irParaXY(118, 34);
    printf("X");
}

int setX(int x) {
    return (x + 118);
}

int setY(int y) {
    return (34 - y);
}

