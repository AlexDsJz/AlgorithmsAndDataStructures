/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

long int recursiveFactorial(int N);

int main(int argc, int *argv[]){
    int N = 1; 
    for(int i = 0; i < 14; i++) //Calcula el factorial desde i = 1, hasta i < 13
        printf("%d! = %d\n", i, recursiveFactorial(i));
}

//Esta es la funcion recursiva, la declaramos como long int por el tamaño que pueden ocupar los factoriales.
//Lo que hace es que si N es menor o igual a 1, retorna un 1, porque el factorial de 1 y de cero es igual a 1.
//Ahora, en caso de que sea mayor a estos, multiplica a N por N-1, invocando a la misma función, para que se siga multiplicando por N-1, hasta llegar a 2.
long int recursiveFactorial(int N){
    if(N <= 1)
        return(1);        
    else
        return(N * recursiveFactorial(N-1));
}