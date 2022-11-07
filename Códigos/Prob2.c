/*  Autor: Dueñas Jiménez Cristian Alexis
    Grupo: 2BM1
    Fecha: 17 de mayo de 2021*/ 

#include <stdio.h>
#include <stdlib.h>

char *crearCadena(int N);
void invertirCadena(char *dest, char *letra);
void imprimirCadena(char *cadena);
void destruirCadena(char **cad);

int main(int argc, char *argv[]){
    char *str = NULL;
    char CadenaAIngresar[200];
    int N = 200;

    printf("Ingrese una cadena de caracteres para que esta sea invertida...\n");
    gets(CadenaAIngresar);

    str = crearCadena(N);

    invertirCadena(str, CadenaAIngresar);
    printf("La cadena original es: %s", CadenaAIngresar);
    printf("\nLa cadena invertida queda de la siguiente forma:\n");
    imprimirCadena(str);
    destruirCadena(str);

    return 0;
}

//Función para reservar memoria para la cadena de caracteres
char *crearCadena(int N){
    char *cadena = NULL;

    cadena = (char *)malloc(N*sizeof(char));

    cadena[0] = '\0';

    return(cadena);
}

//Función para invertir cadena
void invertirCadena(char *dest, char *letra){
    int k=0, c=0, N=0;

    for(k=0; letra[k]!='\0'; k++);

    N = k;

    for(k = N-1, c=0; k>=0; k--, c++)
        dest[c] = letra[k];

    dest[N] = '\0';
}

//Función para imprimir la cadena
void imprimirCadena(char *cadena)			
{
	int k=0;
	
	for (k=0; cadena[k]!='\0'; k++)
	   printf("%c", cadena[k]);
	
	printf("\n");	   
}

//Liberación de memoria
void destruirCadena(char **cad)
{
	char *p= NULL;
	
	p = *cad;
	
	free(p);
	*cad= NULL;

    printf("Memoria liberada");
}