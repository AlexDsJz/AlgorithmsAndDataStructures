/*  
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

void arbolDoble(int N, int nivel);
void arbolTriple(int N, int nivel);


int main(int argc, char *argv[])
{
    int N= 64, nivel=0;

    arbolDoble(N, nivel);
    arbolTriple(N, nivel);
    return 0;
}

//Esta función va "formando" por así decirlo, un árbol de varios niveles, estos niveles contienen valores se´gun se va dividiendo, en este caso, se van dividiendo de 2 en 2, y como
//N es un valor que es múltiplo de 2, llegaremos a un nivel en el que los valores sean 1.
void arbolDoble(int N, int nivel)
{
    int k=0;
    if (N<=0)
        return;

    printf("nivel= %d, N= %d\n", nivel, N);

    arbolDoble(N/2, nivel+1);
    arbolDoble(N/2, nivel+1);
}

//En este caso, se va dividiendo de 3 en 3, en este llegaremos a un nivel en el que los valores serán 2, ya que 2 no es divisible entre 3 y ya no se podría crear otro nivel.
void arbolTriple(int N, int nivel)
{
    int k=0;

    if (N<=0)
        return;

    printf("nivel= %d, N= %d\n", nivel, N);

    arbolTriple(N/3, nivel+1);
    arbolTriple(N/3, nivel+1);
    arbolTriple(N/3, nivel+1);
}