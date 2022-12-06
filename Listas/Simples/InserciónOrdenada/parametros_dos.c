#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------------
// Cargar un struct de "Conjunto, que contiene basicamente un numero
// y su categoria." y lo apila
// Luego armo una lista con los numeros más grandes primero pero agrupados por grupo
// ----------------------------------------------------------------

typedef struct Conjunto{
  int numero;
  int categoria;
}Conjunto;

typedef struct Nodo{
  Conjunto conjunto;
  struct Nodo *siguiente;
}Nodo;

void cargarNumeros(Nodo *);
void imprimir(Nodo **);
void insertarOrdenado(Nodo **, Conjunto);
void apilar(Nodo **, int, int);
Conjunto desapilar(Nodo **);


int main(){
  Nodo *pila = NULL;
  Nodo *lista = NULL;
  int repetir = 1;
  int numero[2];
  
  while(repetir){
    printf("Ingrese un numero para apilar: ");
    scanf("%d", &numero[0]);

    printf("Ingrese la categoria del numero:");
    scanf("%d", &numero[1]);

    apilar(&pila, numero[0], numero[1]);

    printf("Ingrese si quiere continuar:\n1-Si|Otro-No\n");
    scanf("%d", &repetir);
  }

  printf("Lista ingresada por el usuario:\n");
  imprimir(&pila);


  while(pila != NULL){
    Conjunto conjuntoRetornado = desapilar(&pila);
    insertarOrdenado(&lista, conjuntoRetornado);
  }

  printf("\nLista Ordenada:");
  imprimir(&lista);



  return 0;
}
void imprimir(Nodo **cabeza){
  Nodo *recorrer = *cabeza;
  while(recorrer != NULL){
    printf("\nNumero: %d\nCategoria:%d\n", recorrer->conjunto.numero, recorrer->conjunto.categoria); 
    recorrer = recorrer->siguiente;
  }
}


void apilar(Nodo **tope, int numero, int categoria){
  Nodo *nuevo = malloc(sizeof(Nodo));
  nuevo->conjunto.numero = numero;
  nuevo->conjunto.categoria = categoria;
  nuevo->siguiente = *tope;
  *tope = nuevo;
}

Conjunto desapilar(Nodo **tope){
  Nodo *borrar = *tope;
  Conjunto conjuntoRetorno = borrar->conjunto;
  *tope = borrar->siguiente;
  free(borrar);
  return conjuntoRetorno;
}

int actualMenor(Conjunto conjuntoDestino, Conjunto conjuntoFuente){
  return (conjuntoDestino.numero >= conjuntoFuente.numero);
}

int actualMismaCategoria(Conjunto conjuntoDestino, Conjunto conjuntoFuente){
  return (conjuntoDestino.categoria == conjuntoFuente.categoria);
}

void insertarOrdenado(Nodo **cabeza, Conjunto conjuntoNum){
  Nodo *nuevo = malloc(sizeof(Nodo));
  nuevo->conjunto = conjuntoNum;
  nuevo->siguiente = NULL;

  if(*cabeza==NULL){
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
  } else {
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;
    
    // Si el actual existe, es menor que el nuevo numero y no son de la misma categoria
    while(actual != NULL && actualMenor(actual->conjunto, nuevo->conjunto) && !actualMismaCategoria(actual->conjunto, nuevo->conjunto)){
      //Recorre la lista
      anterior = actual;
      actual = actual->siguiente;
    }
    
    // Si el actual existe, es menor que el nuevo numero y son de la misma categoria
    while(actual != NULL && actualMenor(actual->conjunto, nuevo->conjunto) && actualMismaCategoria(actual->conjunto, nuevo->conjunto)){
      //Recorre la lista
      anterior = actual;
      actual = actual->siguiente;
    }

    // este de aca esta por si las dudas no se metio en ningun bucle
    if(anterior == NULL){
      nuevo->siguiente = *cabeza;
      *cabeza = nuevo;
    } else {
      // Meto el valor en el medio del anterior y del actual
      anterior->siguiente = nuevo;
      nuevo->siguiente = actual;
    }
  }
}