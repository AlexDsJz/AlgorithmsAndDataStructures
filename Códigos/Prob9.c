/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int k = 0, x = 0, i = 0, j = 0, N = 5;

    for(k = 0, x = 0; k < N; k++) //Empieza en 0 y va aumentando de 1 en 1, estos valores obtenidos de cada ciclo se van sumando y asi obtenemos a x
        x += k;

    printf("x = %d\n", x);

    for(k = 1, x = 0; k<N; k*=6) //En este caso empezamos en 1, y en cada ciclo se multiplica por 6, en el segundo ciclo, k toma el valor 6 y ya no es menor que N, por lo que deja de 
        x += k;                  //hacer ciclos

    printf("x = %d\n", x);

    for(i = 0, x = 0; i < N; i+=2) //i incrementa de 2 en 2, empezando por cero
        for(j = 0; j < N; j+=3) //j incrementa de 3 en 3
            x += i*j; //Se van sumando los productos que obtenemos en cada ciclo entre i y j, en el segundo for, termina en el primer ciclo, pero se usa el numero obtenido anteriormente
                        //para seguir haciendo operaciones

    printf("x = %d\n", x);

    for(i = N, x = 0; i > 0; i/=2) //Empezamos con que i es igual a N, y se va dividiendo, aqui al ser declarados puros enteros, los decimales los excluye y toma solo el entero
        for(j = N; j > 0; j--) //Los enteros anteriores van multiplicando estos valores, j va disminuyendo de 1 en 1
            x += i*j;//Incrementa segun el producto de i y j en cada ciclo

    printf("x = %d\n", x);

    return 0;
}