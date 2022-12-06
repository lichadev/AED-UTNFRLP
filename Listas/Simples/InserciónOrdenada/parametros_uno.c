#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------------
// Cargar un struct de alumnos en una pila
// y armar una lista con las mejores notas ordenadas y juntos por alumno
// ----------------------------------------------------------------

typedef struct Nodo{
  int numero;
  struct Nodo *siguiente;
}Nodo;

void cargarNumeros(Nodo *pila_alumno);
void imprimir(Nodo **cabeza);
void insertarOrdenado(Nodo **cabeza, int numero);
void apilar(Nodo **tope, int numero);
int desapilar(Nodo **tope);


int main(){
  Nodo *pila_alumno = NULL;
  Nodo *lista_alumno = NULL;
  int repetir = 1;
  int numero;
  
  while(repetir){
    printf("Ingrese un numero para apilar: ");
    scanf("%d", &numero);

    apilar(&pila_alumno, numero);

    printf("Ingrese si quiere continuar:\n1-Si\nOtro-No\n");
    scanf("%d", &repetir);
  }

  printf("Lista ingresada por el usuario:\n");
  imprimir(&pila_alumno);


  while(pila_alumno != NULL){
    int numeroRetorno = desapilar(&pila_alumno);
    insertarOrdenado(&lista_alumno, numeroRetorno);
  }

  printf("\nLista Ordenada:");
  imprimir(&lista_alumno);



  return 0;
}
void imprimir(Nodo **cabeza){
  Nodo *recorrer = *cabeza;
  while(recorrer != NULL){
    printf("\nNumero: %d", recorrer->numero); 
    recorrer = recorrer->siguiente;
  }
}


void apilar(Nodo **tope, int numero){
  Nodo *nuevo = malloc(sizeof(Nodo));
  nuevo->numero = numero;
  nuevo->siguiente = *tope;
  *tope = nuevo;
}

int desapilar(Nodo **tope){
  Nodo *borrar = *tope;
  int alumnoRetornar = borrar->numero;
  *tope = borrar->siguiente;
  free(borrar);
  return alumnoRetornar;
}

void insertarOrdenado(Nodo **cabeza, int numero){
  Nodo *nuevo = malloc(sizeof(Nodo));
  nuevo->numero = numero;

  if(*cabeza == NULL){
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
  } else {
 
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;

    while(actual != NULL && actual->numero < nuevo->numero){
      anterior = actual;
      actual = actual->siguiente;
    }

    if(anterior == NULL){
      nuevo->siguiente = *cabeza;
      *cabeza = nuevo;
    } else {
      anterior->siguiente = nuevo;
      nuevo->siguiente = actual;
    }
  }
}