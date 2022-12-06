#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{
	int numero;
	struct Nodo *siguiente;
}Nodo;

void añadir(Nodo **, int);
void imprimir(Nodo *cabeza);
void add_any_pos(Nodo **cabeza, int numero, int posicion);

int main(){
	Nodo *lista = NULL;

	añadir(&lista, 10);
	añadir(&lista, 20);
	añadir(&lista, 30);
	añadir(&lista, 50);

	imprimir(lista);
	printf("\n");

	add_any_pos(&lista, 40, 4);

	printf("\n");
	imprimir(lista);
}

void add_any_pos(Nodo **cabeza, int numero, int posicion){
	Nodo *recorrer = *cabeza;
	Nodo *nuevo = malloc(sizeof(Nodo));
	nuevo->numero = numero;
	nuevo->siguiente = NULL;
	
	posicion--;
	while(posicion != 1){
		recorrer = recorrer->siguiente;
		posicion--;
	}

	nuevo->siguiente = recorrer->siguiente;
	recorrer->siguiente = nuevo;
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
