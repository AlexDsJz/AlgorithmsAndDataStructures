/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 9 de junio de 2021*/ 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //Hacemos la declaracion del arreglo doble y el tamaño que utilizaremos.
    int **dinosaurio = NULL;
    int N = 9, k = 0, j = 0;

    dinosaurio = (int **)malloc(N * sizeof(int *));//Reservamos memoria para el arreglo doble
    
    for(j = 1; j < N; j+=2){ 
        dinosaurio[j] = (int *)malloc(j * sizeof(int)); //Con este ciclo, si los valores son impares, reservamos memoria para esa posicion.
        for(k=0; k < j; k++)
            dinosaurio[j][k] = j+k; //Ademas en esa posicion se crea un arreglo tomando como primer numero la posicion que ocupa, y se incrementa de uno en uno
    }

    for(j = 0; j < N; j+=2)
        dinosaurio[j] = &(dinosaurio[(j+1)%N][j]); //En caso de que sea par, guardamos la direccion de la última posición del arreglo creado en la posición impar siguiente.

    //Realizamos el desplegado
    for(j = 0; j < N; j++){
        if(j%2==0){
            printf("Posicion[%d] = %p -> %d\n", j, dinosaurio[j], *dinosaurio[j]);
        }else{
            for(k = 0; k<j; k++)
            printf("Posicion[%d][%d] = %d \t", j, k, dinosaurio[j][k]);
            printf("\n");
        }
    }

//Liberamos memoria, tanto para el aapuntador lineal como para el doble
    for(j = 1; j < N; j+=2){
        free(dinosaurio[j]);
    }

    free(dinosaurio);
    return 0;
}