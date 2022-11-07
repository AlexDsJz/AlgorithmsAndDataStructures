/*  
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

void arbolBinario(int nivel, int nodo, int limite, int *cont);
void arbolBaseB(int nivel, int nodo, int limite, int base, int*cont);

//Desde la funcion main, llamaremos a las funciones recursivas de arbolBinario y a la de arbolBaseB.
//Ademas de imprimir el conteo total de nodos que hay por cada nivel.
void main(int argc, char *argv[])
{
    int N=0, n=0, lim= 4, base=3;
    int conteo=0;

    arbolBinario(N, n, lim, &conteo);
    printf("Conteo arbol binario= %d\n", conteo);

    conteo= 0;

    arbolBaseB(N, n, lim, base, &conteo);
    printf("Conteo arbol base %d= %d\n", base, conteo);
}

//Irá generando niveles y nodos por cada nivel, en la variable cont, irá almacenando los nodos que hay por nivel en cada ciclo.
//Será invocandose N veces hasta que se llegue al límite de niveles. El límite lo establecimos en N.
void arbolBinario(int nivel, int nodo, int limite, int *cont)
{
    int k=0;

    if (nivel>=limite)
        return;

    for (k=0; k<nivel; k++)
    printf("\t");

    (*cont)++;

    printf("nivel= %d, nodo= %d\n", nivel, nodo);

    arbolBinario(nivel+1, 2*nodo+0, limite, cont);
    arbolBinario(nivel+1, 2*nodo+1, limite, cont);
}

//Hace lo mismo esta función que la interior, pero este se hace en base k.
void arbolBaseB(int nivel, int nodo, int limite, int base, int *cont)
{
    int k=0;

    if (nivel>=limite)
        return;

    (*cont)++;

    for (k=0; k<nivel; k++)
        printf("\t");

    printf("nivel= %d, nodo= %d\n", nivel, nodo);

    for (k=0; k<base; k++)
        arbolBaseB(nivel+1, base*nodo+k, limite, base, cont);
}