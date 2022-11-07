/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 10 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int ******hipercubo = NULL; 
    int a=3, b=3, c=3, d=3, e=3, f=3; 
    int i =0, j = 0, k =0, l=0, m=0, n=0; 

    //Apartamos memoria para un hipercubo de 6 dimensiones
    hipercubo = (int ******)malloc(a*sizeof(int *****));

    //Con lo siguiente hacemos reservacion de memoria para cada una de las dimensiones
    for(i = 0; i < a; i++){
        
        hipercubo[i] = (int *****)malloc(b*sizeof(int****)); //Ahora se hacen arreglos de 5 dimensiones

        for(j = 0; j < b; j++){

            hipercubo[i][j] = (int****)malloc(c * sizeof(int ***)); //Ahora se hacen arreglos de 4 dimensiones
        
            for(k = 0; k < c; k++){

                hipercubo[i][j][k] = (int ***)malloc(d * sizeof(int **)); //Ahora se hacen arreglos de 3 dimensiones
            
                for(l = 0; l < d; l++){

                    hipercubo[i][j][k][l] = (int **)malloc(m*sizeof(int *)); //Ahora se hacen arreglos de 2 dimension

                    for(m = 0; m < e; m++){

                        hipercubo[i][j][k][l][m] = (int*)malloc(n*sizeof(int)); //Ahora se forma un arreglo lineal

                        for(n = 0; n < f; n++){

                            hipercubo[i][j][k][l][m][n] = (int)i*j*k*l*m*n; //Hacemos una operacion

                        }

                    }
                }
            }
        }
    }

    //Hacemos la impresion de las dimensiones del hipercubo
    for(i = 0; i < a; i++)
        for(j=0; j < b; j++)
            for(k = 0; k < c; k++)
                for(l = 0; l < d; l++)
                    for(m = 0; m < e; m++)
                        for(n = 0; n < f; n++)
                        printf("[%d][%d][%d][%d][%d][%d] = %d\n", i, j, k, l, m, n, hipercubo[i][j][k][l][m][n]);

    //Liberacion de memoria para cada una de las dimensiones
    for(j=0; j < b; j++){
        for(k = 0; k < c; k++){
            for(l = 0; l < d; l++){
                for(m = 0; m < e; m++){
                    for(n = 0; n < f; n++){
                        free(hipercubo[i][j][k][l][m]);
                    }
                    free(hipercubo[i][j][k][l]);
                }
                free(hipercubo[i][j][k]);
            }
            free(hipercubo[i][j]);
        }
        free(hipercubo[i]);
    }

    //Liberacion de memoria del apuntador de 6 dimensiones
    free(hipercubo);

    return 0;
}