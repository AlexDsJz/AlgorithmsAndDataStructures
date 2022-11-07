/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

void selectSort(int *arr, int N);
void imprimirSelectSort(int *arr, int N);

int main(int argc, char *argv[]){
    int N = 10;
    int arr[10] = {8,4,1,6,0,3,2,5,7,9};

    printf("Arreglo desordenado:\n");
    for(int i = 0; i < N; i++)
        printf("%d \t", arr[i]);

    printf("\n\n");
    selectSort(arr, N);
    imprimirSelectSort(arr, N);

}

void selectSort(int *arr, int N){
    int i = 0, j = 0; 
    int aux = 0;

    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            if(arr[i]>arr[j]){
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }
}

void imprimirSelectSort(int *arr, int N){
    int i = 0;
    printf("Arreglo ordenado:\n");
    for(int i = 0; i < N; i++)
        printf("%d \t", arr[i]);
}