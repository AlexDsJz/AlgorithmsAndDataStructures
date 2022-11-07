/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int *arr, int N, int numero);
void imprimirBusquedaBinaria(int *arr, int N, int numero);

int main(int argc, char *argv[]){
    int arr[21] = {1,2,4,16,28,29,33,40,52,54,55,58,59,64,65,75,83,89,90,94,95};
    int numero = 59;
    int N =21;

    busquedaBinaria(arr, N, numero);
    imprimirBusquedaBinaria(arr, N, numero);
}

//Establecemos la función que realizará la búsqueda de forma iterativa, lo que hace es dividir el arreglo
//y si llega a encontrarse justamente en la mitad, arroja la posicion. En dado caso que no, sigue buscando
//ya sea en la parte superior o inferior, en la parte que no se encuentre, la descarta y sigue haciendo comparaciones
//en la parte donde se encontró, hasta encontrar la posición exacta donde está el número. 
int busquedaBinaria(int *arr, int N, int numero){
    int inf = 0, sup = N, mitad;

    while(inf<=sup){
        mitad = inf+(sup-inf)/2;

        if(arr[mitad] == numero)
            return(mitad);

        if(numero < arr[mitad])
            sup = mitad - 1;
        else
            inf = mitad + 1;
    }

    return(-1);
}

//Imprimimos la posición en la que se encuentra el valor que buscamos.
void imprimirBusquedaBinaria(int *arr, int N, int numero){
    printf("%d encontrado en la posicion %d\n", numero, busquedaBinaria(arr,21,numero));
}