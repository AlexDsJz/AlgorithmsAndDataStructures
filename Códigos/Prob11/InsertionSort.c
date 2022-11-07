/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int N);
void imprimirSort(int arr[], int N);

int main(int argc, char *argv[]){
    int N = 10;
    int arr[10] = {8,4,1,6,0,3,2,5,7,9};

    printf("Arreglo sin ordenar\n");
    for(int i = 0; i < N; i++)
    printf("%d\t", arr[i]);

    printf("\n\n");

    insertionSort(arr, N);
    imprimirSort(arr, N);
    return 0;
}

void insertionSort(int arr[], int N){
    int i = 0, j = 0;
    int ref = 0;

    for(i = 0; i < N; i++){
        ref=arr[i];

        for(j = i-1; j >= 0 && ref<arr[j]; j--)
            arr[j+1] = arr[j];

        arr[j+1] = ref;
    }
}

void imprimirSort(int arr[], int N){
    int i = 0;
    printf("Arreglo ordenado\n");
    for(i = 0; i < N; i++)
        printf("%d \t", arr[i]);
}