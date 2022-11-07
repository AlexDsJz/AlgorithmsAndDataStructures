/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 13 de junio de 2021*/ 

#include<stdio.h>

int recursiveSearchBinary(int *arr, int start, int end, int element);

//Establecemos el arreglo con los valores ordenados y el número a buscar
int main(int argc, char *argv[]){
    int arr[21] = {1,2,4,16,28,29,33,40,52,54,55,58,59,64,65,75,83,89,90,94,95};
    int numero = 1; 
    
    printf("El numero %d fue encontrado en la posicion %d", numero, recursiveSearchBinary(arr, 0, 21, numero));
    
    return 0;
}

//Con la función recursiva dividimos en 2 partes el arreglo y tomamos el valor de en medio
//Si el valor no existe en el arreglo, devuelve un -1.
//En caso de que exista realiza la búsqueda, si está en el valor de en medio, termina la búsqueda
//Si no está en el valor de en medio, compara si es menor el valor que estamos buscando o mayor
//y si es menor toma la parte inferior, realiza lo mismo que lo anterior hasta llegar al punto donde 
//se encuentre el valor buscado.
int recursiveSearchBinary(int *arr, int start, int end, int element){
    if(start>end)
        return(-1);

    int mid = (start+end)/2;
    
    if(arr[mid] == element)
        return mid;
    else
        if(element < arr[mid])
        recursiveSearchBinary(arr, start, mid-1, element);
        else
            recursiveSearchBinary(arr, mid+1, end, element);

}