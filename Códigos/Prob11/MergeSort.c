/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 12 de junio de 2021*/ 


#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int N);
void imprimirMergeSort(int *arr, int N);

int main(int argc, char *argv[]){
    int N = 10;
    int arr[10] = {8,4,1,6,0,3,2,5,7,9};

    printf("Arreglo sin ordenar\n");
    for(int i = 0; i < N; i++)
    printf("%d\t", arr[i]);

    printf("\n\n");

    mergeSort(arr, N);
    imprimirMergeSort(arr, N);
    return 0;
}

void mergeSort(int *arr, int N){
    int *nuevo= NULL;
	int k=0, h=0, q=0, c=0;
	int L= 2*N, corte=0, medio=0;
	int i=0, j=0;
	
	nuevo= (int *) malloc(N*sizeof(int));
	
	for (q=0; q<N; q++)
	   nuevo[q]= 0;

       for (k=2, h=1; k<L; k*=2, h*=2)		
	   {	   		
	   		for (q=0; q<N; q+=k)			
	   		   {		
	   		   		corte= q+k;
	   		   		if (corte>N)
	   		   		  corte= N;
	   		   		medio= q+h;
	   		   		if (medio>N)
	   		   		  medio= N;
	   		   		
	   		   		i= q;
	   		   		j= medio;

                    for (c=q; c<corte; c++)		
					   {
					   		if (arr[i]<arr[j] && i<medio || j>=corte)
					   		  {
					   		  	nuevo[c]= arr[i];
					   		  	i++;
							  }
							else
							{							
								if (arr[i]>=arr[j] && j<corte || i>=medio)
							  	  {
							  		nuevo[c]= arr[j];
					   		  		j++;
							  	  }
							}
					   }					
			   }
			   
			for (q=0; q<N; q++)
			   arr[q]= nuevo[q];
			   
	   }	
	free(nuevo);
}

void imprimirMergeSort(int *arr, int N){
    int i = 0;
    printf("Arreglo ordenado:\n");
    for(int i = 0; i < N; i++)
        printf("%d \t", arr[i]);
}