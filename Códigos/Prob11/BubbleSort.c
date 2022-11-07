/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int N);
void imprimirBubbleSort(int *arr, int N);

int main(int argc, char *argv[]){
    int N = 10;
    int arr[10] = {8,4,1,6,0,3,2,5,7,9};

    printf("Arreglo sin ordenar\n");
    for(int i = 0; i < N; i++)
    printf("%d\t", arr[i]);

    printf("\n\n");

    bubbleSort(arr, N);
    imprimirBubbleSort(arr, N);
    return 0;
}

void bubbleSort(int *arr, int N){
    int i = 0, j = 0;
    int aux = 0;
    int inter = 1;
    int L = N-1;

    while(inter!=0){
        inter = 0;

        for(i = 0; i < L; i++){
            if(arr[i]>arr[i+1]){
                aux = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = aux;
                inter = 1;
            }
        }
    }
}

void imprimirBubbleSort(int *arr, int N){
    int i = 0;
    printf("Arreglo ordenado:\n");
    for(int i = 0; i < N; i++)
        printf("%d \t", arr[i]);
}