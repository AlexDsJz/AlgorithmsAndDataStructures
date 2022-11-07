/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 13 de junio de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

int *crearVec(int t);
void llenarPositivo(int *v, int t);
void reinas(int i, int N, int *vec,int *puesto,int *diag2_1,int *diag1_2);
void imp(int *vec, int N);
int reina=0;

int main(int argc, char *argv[]){
    int *vec=NULL,*puesto=NULL,*diag2_1=NULL,*diag1_2=NULL;
    int N=0;
    printf("Introduce el numero de reinas: ");
    scanf("%d", &N);
    vec = crearVec(N);
    puesto = crearVec(N);
    diag2_1 = crearVec((2*N)-1);
    diag1_2 = crearVec((2*N)-1);
    llenarPositivo(puesto,N);
    llenarPositivo(diag2_1,(2*N)-1);
    llenarPositivo(diag1_2,(2*N)-1);
    reinas(0, N, vec,puesto,diag2_1,diag1_2);
    imp(vec, N);
    return 0;
}
//Creación del vector
int *crearVec(int t){
    int *v=NULL;
    if((v=malloc(sizeof(int)*t))==NULL){
        printf("Sin memoria suficiente\n");
        return NULL;
    }
    return v;
}
//Función para cambiar el valor
void llenarPositivo(int *v,int t){
    int i;
    for(i=0;i<t;i++){
        v[i] = 1;
    }
}
//Función recursiva para posicionar la reinas
void reinas(int i, int N, int *vec,int *puesto,int *diag2_1,int *diag1_2){
    int j;
    for(j=0;j<N;j++){
            if(puesto[j] && diag2_1[i+j] && diag1_2[i-j+(N-1)]){
                vec[i] = j;
                puesto[j] = 0;
                diag2_1[i+j] = 0;
                diag1_2[i-j+(N-1)] = 0;
                reina++;
                if(i<(N-1)){
                    reinas(i+1,N,vec,puesto,diag2_1,diag1_2);
                    if(reina<N){
                        puesto[j] = 1;
                        diag2_1[i+j] = 1;
                        diag1_2[i-j+(N-1)] = 1;
                        reina--;
                    }
                }
            }
    
    }

}

//Imprimir tablero
void imp(int *vec, int N){
    int i,j;
    printf("Tablero\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(j==vec[i]){
                printf(" x ");
            }else{
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    
    printf("Coordenadas de las reinas:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(j==vec[i]){
                printf("%d,%d\n",i,j);
            }
        }
    }
}