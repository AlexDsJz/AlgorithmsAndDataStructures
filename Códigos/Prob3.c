/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 17 de mayo de 2021*/ 

#include<stdio.h>
#include <stdlib.h>

int main(){

    //Se declaran los apuntadores como nulos para que no tome posiciones de memoria
    ///arbitrarias.
    int **q = NULL, *p = NULL;
    int *a = NULL, *b = NULL, *x = NULL, *y = NULL;

    int N= 10, k = 0; //Establecemos una variable N y una variable k
                      //queusaremos como posición.

    a = (int *)malloc(N*sizeof(int));   //Liberamos memoria para a, en este caso de un tamaño de 10 enteros
    b = (int *)malloc(N*sizeof(int));   //Liberamos memoria para b, de igual forma para 10 enteros

    for(x = a, y = b, k = 0; k<N; k++,x++,y++){  //Con este ciclo asignaremos valores a ambos apuntadores
                                                 
        (*x) = 2*k; //En el caso de a, como x tomó su dirección, a incrementará de 2 en 2 valores
        (*y) = 3*k; //En el caso de b, "y" almacenó su dirección, y al acceder al contenido, lo incrementa de 3 en 3
    }

    for (k=0; k<N; k++){ 
        if(k%2==0)  //Si la posición del arreglo es para, q guardará la dirección de a
            q= &a;
        else        //Si es impar, q almacenará la dirección de b
            q= &b;

        p = *q;  //Le pasa la dirección según lo anterior
        p = p+k; //Este recorre a P
        (*p) *= -1; //El valor de P se hace negativo

        (**q) += *p; //A **q le sumamos el valor de *p
    }

    for(k = 0; k<N; k++)
        printf("%X :: a[%d] = %d\n", &(a[k]), k, a[k]);//Imprimimos a

    printf("\n");

    for(k = 0; k<N; k++)
        printf("%X :: b[%d] = %d\n", &(b[k]), k, b[k]);//Imprimimos b

    printf("\n");

    free(a);//Liberamos la memoria
    free(b);
    return 0;
}