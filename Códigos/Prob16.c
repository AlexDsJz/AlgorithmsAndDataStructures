/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 13 de junio de 2021*/ 

#include <stdlib.h>
#include <stdio.h>   

void towerOfHanoi(int numdiscos, char de_torre, char a_torre, char torre_aux);

//En la función main establecemos el número de discos que se utilizarán. Posterior a terminar el "juego", preguntamos si se desea jugar otra vez, en caso afirmativo, se vuelve a preguntar
//el número de discos.
int main(int argc, char *argv[]) {
    printf("******Torres de Hanoi*******\n");
    int res;
    do{
        int numdiscos;
        printf("Ingresa el numero de discos\n");
        scanf("%d",&numdiscos);
        towerOfHanoi(numdiscos, 'A', 'C', 'B');
        printf("\n\nQuieres volver a jugar? Ingrese un 1 para si o un 0 para no\n");
        scanf("%d",&res);
        
    }while(res==1);
    return 0;
}

//Esta es la función recursiva, establecemos una condición, si el número de discos es 1, sólo habrá una operación.
//Lo que hace es realizar operaciones de acorde al número de discos, si tenemos que la cantidad de discos son 10, la operación es 
//2^10-1
void towerOfHanoi(int numdiscos, char de_torre, char a_torre, char torre_aux) {
    if (numdiscos == 1) {
        printf("Mover disco 1 de la torre %c a la torre %c\n", de_torre, a_torre);
        return;
    }

    towerOfHanoi(numdiscos - 1, de_torre, torre_aux, a_torre);
    printf("Mover disco %d de la torre %c a la torre %c\n", numdiscos, de_torre, a_torre);
    towerOfHanoi(numdiscos - 1, torre_aux, a_torre, de_torre);
}