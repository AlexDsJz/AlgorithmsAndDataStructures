/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 09 de abril de 2021*/ 
#include<stdio.h>
#include<stdlib.h>

int *apartarMemoria(int N);
char **crearArregloDoble(int N);
void cambioBase(int N, int *arr, char **arr2);
void imprimirArreglo(int N, int *arre, char **arre2);
void liberarMemoria(int *arre);
void liberarMemoriaDoble(int **arre2, int N);

int main(int argc, char *argv[]){
    int *arr = NULL;
    int **p2 = NULL;
    int N = 6; 
    
    arr = apartarMemoria(N); 
    p2 = crearArregloDoble(N);
    
    cambioBase(N, arr, p2);
    imprimirArreglo(N, arr, p2);
    liberarMemoria(arr); 
    liberarMemoriaDoble(p2, N);
    
    return 0;
}

//Declaramos una funcion con la cual apartaremos memoria para un arreglo de N enteros.
int *apartarMemoria(int N){
    int *arre = NULL; //Declaramos el apuntador inicializandolo como Nulo.

    arre = (int *)malloc(N * sizeof(NULL));//Con malloc apartamos memoria segun el tipo de dato y el numero de enteros declarados al inicio.

    return(arre);
}

char **crearArregloDoble(int N){
    char **arre2 = NULL;

    arre2 = (char **)malloc(N*sizeof(char*));

    return(arre2);
}

//Declaramos la funcion que cambiara la base de cada uno de los valores que iran almacenados dentro del arreglo, 
//esta base se tomara de acuerdo a la posicion en la que se encuentren y el numero que se convertira es el de la direccion que tomamos
//en hexadecimal pero de forma entera.
void cambioBase(int N, int *arr, char **arr2){
    int div = 0, mod = 0, value = 0, c = 0, dir = 0;
    char cadena[30];
    for(int i = 0; i < N; i++){
        dir = &arr[i];
        c=0;
        div=dir;

        if(i == 0){
            cadena[0] = 0;
            c++;
        }
        else{
            if(i == 1){
                cadena[0]=49;
                c++;
            } else{
                while(div!=0){
                    mod = div%i;
                    value = mod;
                    if(mod<10){
                        value = value + 48;
                    } else
                        value = value + 55;

                    cadena[c] = value;
                    c++;
                    div = ((div)-mod)/i;
                }
            }
        }

        arr2[i]=(char *)malloc(c*sizeof(char));

        for(int j = 0, k = c-1; k >= 0; j++, k--){
            arr2[i][j] = cadena[k];
        }

        arr2[i][c] = '\0';
    }
}

//Imprimimos el arreglo en forma de tabla
void imprimirArreglo(int N, int *arre, char **arre2){
    printf("Posicion \t    Direccion \t       Direccion en base k\n");
    for(int i = 0; i < N; i++){
        printf("   [%d] \t            %d \t       %s \n", i, &arre[i], arre2[i]);
    }
}

//Liberamos memoria para el arreglo lineal
void liberarMemoria(int *arre){
    int *r = NULL; 
    r = *arre; 
    
    free(r); 
    *arre = NULL; 
}

//Liberamos memoria para el apuntador doble que se creo
void liberarMemoriaDoble(int **arre2, int N){
    for(int i = 0; i < N; i++){
        if(arre2[i]!=NULL)
            free(arre2[i]);
    }
    free(arre2);
}