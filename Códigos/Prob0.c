/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 06 de abril de 2021*/  
#include<stdio.h>

int main(int argc, char *argv[]){
    //Declaramos las variables y los apuntadores, los cuales tomaran una direccion de memoria aleatoria.
    //Los apuntadores dse declaran nulos al inicializarlos.
    int *u = NULL, *v = NULL, *w = NULL, *q = NULL;
    int a = 101, b = 201, c = 301;

    //Consultamos la direccion de cada una de las variables declaradas.
    u = &c;  
    v = &b;
    w = &a;

    //Realizamos las operaciones con apuntadores, en este caso todos incrementan de diferente forma.
    (*w)+= a + b + c;//a
    (*v)*= 4;//b
    (*u)++;//c

    //Almacenamos las direcciones de memoria en un apuntador diferente.
    //q ahora toma la direccion de w, que es la variable a.
    //w toma la direccion que tenia almacenada u, la cual es c
    //u toma la de v, que es la variable b
    //v toma la que tiene q, que es a
    q = w;  w = u; u = v;  v = q;

    //Se realiza decremento de las variables, pero al ser negativo el valor que obtenemos de 
    //la diferencia del modulo con las variables, se suma.
    (*u) -= (*q)%5 - a;
    (*v) -= (*q)%3 - b;
    (*w) -= (*q)%2 - c;

    //Imprimimos lo valores obtenidos en cada una de las variables.
    printf("a = %d    b = %d    c = %d\t", a, b, c);
    
    //Ningun apuntador queda nulo.
    return 0;
}