/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 13 de junio de 2021*/ 

#include<stdio.h>
#include<stdlib.h>

void QuickSort(int *a,  int n);
void imprime(int *a, int n);
int Particion(int *a, int n);

int main(int argc, char *argv[]){
	int a[10] = {8,4,1,6,0,3,2,5,7,9}, p, n = 10;
	fflush(stdin);
    printf("Arreglo desordenado: \n");
	imprime(a,  n);
    printf("\n");
	QuickSort(a, n);
    printf("Arreglo ordenado: \n");
	imprime(a,  n);

	return 0;
}

//Esta función es la recursiva, mientras no haya un elemento solo, no se dejará de dividir el arreglo, por eso invocamos a la función particion();
//Después acomoda los valores para que queden ordenados y al final los une.
void QuickSort(int *a, int n){
	int p;
	if (n>1){
        p=Particion(a,n);
		QuickSort(a, p);
		QuickSort(a+p+1, n-p-1);
	}
}

//Esta función se encarga de dividir el arreglo en subarreglos
int Particion(int *a, int n){
	int p=0, q=1, t, i;
	for(q=1;q<n;q++){
        if(a[q]<=a[p]){
            t=a[q];
            for(i=q;i>p;i--)
                a[i]=a[i-1];

            a[p]=t; p++;
        }
	}
	return p;
}

//Con esto imprimimos el arreglo ordenado, una vez concatenados todos los valores del arreglo.
void imprime(int *a, int n){
    int i;
    for (i=0; i<n;i++)
         printf("%d ", a[i]);
    printf("\n");
}

