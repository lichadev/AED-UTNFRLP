#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


void AñadirNodoInicio(Lista *lista, int key, char* keyMan){
  // Creo un nodo
  Nodo *nodoNuevo;
  nodoNuevo = malloc(sizeof(Nodo));
  nodoNuevo->keyExample.key = key;
  strcpy(nodoNuevo->keyExample.keyManName, keyMan);


  // Apunto a la cabeza de la lista
  nodoNuevo->nodo_siguiente = lista->cabeza;

  // Actualizo la cabeza de la lista
  lista->cabeza = nodoNuevo;
}

void AñadirNodoFinal(Lista *lista, int key, char* keyMan){
  Nodo *nodoNuevo;
  nodoNuevo = malloc(sizeof(Nodo));

  // si literalmente no hay nadie
  if(lista->cabeza == NULL)
  {
    lista->cabeza = nodoNuevo;
  } else {

    // si hay algo
    Nodo *aux = lista->cabeza;
    while (aux->nodo_siguiente)
    {
      aux = aux->nodo_siguiente;
    }

    aux->nodo_siguiente = nodoNuevo;
  }
}

void RecorrerLista(Nodo *nodo_actual){

  // Creo un nodo auxilar para recorrer la lista
  Nodo *nodoActualCopy;
  nodoActualCopy = nodo_actual;

  while(nodoActualCopy != NULL){
    printf("<Llavero: %i>\n<Nombre llavero: %s>\n", nodoActualCopy->keyExample.key, nodoActualCopy->keyExample.keyManName);
    nodoActualCopy = nodoActualCopy->nodo_siguiente;
  }
  printf("-----\nSe termino de recorrer el llavero\n------\n");
  free(nodoActualCopy);
}

void EliminarPrimero(Lista *lista){
  if(lista->cabeza){
    // guardo quien borro
    Nodo *eliminar = lista->cabeza;
    // enlazo el primero con el siguiente
    lista->cabeza = lista->cabeza->nodo_siguiente;
    // boleo el nodo
    free(lista);
  }
}

void EliminarUltimo(Lista *lista){
  if(lista->cabeza){
    /*
      Nos tenemos que tener en el penultimo para eliminar al ultimo elemento.
      Si eliminas derecho el ultimo nodo, te genera un error de Segmentacion
      porque el nodo anterior estaba apuntado a ese y ahora ya no esta lo que apunta
      por lo tanto tenes que ir al penultimo y borrar a su siguiente.
    */

    Nodo *aux = lista->cabeza;
    while(aux->nodo_siguiente->nodo_siguiente)
      aux = aux->nodo_siguiente;

    Nodo *eliminar = aux->nodo_siguiente;
    aux->nodo_siguiente = NULL;
    free(eliminar);
  }
}


int cantidad = 3;

int valor(){
  printf("%i", cantidad);
  return cantidad;
}

void Cantidad(){
  cantidad = cantidad - 1;
}

void vaciarValor(){
  if(valor() != 0){
    Cantidad();
    vaciarValor();
  }
}

int main (){

  vaciarValor();



  return 0;
}