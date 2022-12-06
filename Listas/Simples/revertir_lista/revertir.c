#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int numero;
	struct Nodo *siguiente;
}Nodo;

void añadir(Nodo **, int);
void imprimir(Nodo *cabeza);
void invertir(Nodo **cabeza);

int main(){
	Nodo *lista = NULL;

	añadir(&lista, 25);
	añadir(&lista, 20);
	añadir(&lista, 10);
	añadir(&lista, 5);

	imprimir(lista);
	printf("\n");

	invertir(&lista);
	
	imprimir(lista);
}

void imprimir(Nodo *cabeza){
	Nodo *recorrer = cabeza;
	while(recorrer != NULL){
		printf("%d ", recorrer->numero);
		recorrer=recorrer->siguiente;
	}
}

void añadir(Nodo **cabeza, int numero){
	Nodo *nuevo = malloc(sizeof(Nodo));
	nuevo->numero = numero;
	nuevo->siguiente = *cabeza;
	*cabeza = nuevo;
}

void invertir(Nodo **cabeza){
	Nodo *siguiente = NULL;
	Nodo *anterior = NULL;

	while(*cabeza != NULL){
		siguiente = (*cabeza)->siguiente; 
		(*cabeza)->siguiente = anterior; 
		anterior = *cabeza; 
		*cabeza = siguiente; 
	}
	*cabeza = anterior; 

}