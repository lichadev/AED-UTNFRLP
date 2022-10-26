#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

void CrearLlavero(Key *keyExample){
  printf("Ingrese el codigo de la llave:");
  scanf("%i", &keyExample->key);
  printf("Ingrese el nombre del llavero:");
  scanf(" %s", &keyExample->keyManName);
}

void IncializarLista(Lista *nodo_raiz){
  
  // incializo mi lista, con el nodo siguiente al raiz = NULL, por ser el primero
  nodo_raiz->nodo_siguiente = NULL;
  CrearLlavero(&(nodo_raiz->keyExample));

}

void AñadirNodo(Lista *nodo_actual){

  // Creo un nodo auxilar para recorrer la lista
  Lista *nodoActualCopy = nodo_actual;
  nodoActualCopy = malloc(sizeof(nodo_actual));

  // Buscando al ultimo nodo de la lista
  while(nodoActualCopy->nodo_siguiente != NULL){
    nodoActualCopy = nodoActualCopy->nodo_siguiente;
  }

  // Esta en el ultimo nodo de la lista
  nodo_actual=nodoActualCopy->nodo_siguiente;
  free(nodoActualCopy);
  CrearLlavero(&(nodo_actual->keyExample));
  nodo_actual->nodo_siguiente = NULL;

}

void RecorrerLista(Lista *nodo_actual){
  
  // Creo un nodo auxilar para recorrer la lista
  Lista *nodoActualCopy = nodo_actual;
  nodoActualCopy = malloc(sizeof(nodo_actual));

  while(nodoActualCopy->nodo_siguiente != NULL){
    printf("<Llavero: %i>\n<Nombre llavero: %s>\n", nodoActualCopy->keyExample.key, nodoActualCopy->keyExample.keyManName);
    nodoActualCopy = nodoActualCopy->nodo_siguiente;
  }
  printf("-----\nSe termino de recorrer el llavero\n------\n");
  free(nodoActualCopy);
}

void BuscarLlavero(Lista *nodo_actual);
void BorrarUltimo(Lista *nodo_actual);
