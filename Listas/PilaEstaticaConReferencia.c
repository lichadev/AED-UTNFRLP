#include <stdio.h>
#include <stdlib.h>

// Pila implementada con un array estatico
// TDA, Tipo de dato Abstracto. Pero sin uso de array dinamico

typedef struct {
  int valores[100];
  int posTope;
} Pila;

void apilar(Pila *pila, int numero)
{
  if(pila->posTope < 100)
  {
    pila->valores[pila->posTope] = numero;
    pila->posTope++;

  } else {
    printf("Esta llena la pila amiguito :).");
  }
}

void mostrar (Pila *pila) {
  int i=0;
  while(i<pila->posTope){
    printf("[%d]", pila->valores[i]);
    i++;
  }
}

int main (){
  Pila pila; // Creando la pila
  
  pila.posTope = 0; // Inicializando la pila, necesario ya que sino se carga desde un inicio en una posicion con basura
  apilar(&pila, 10); // Tiene que estar igualado ya que la funcion devuelve una pila
  apilar(&pila, 20);
  apilar(&pila, 30);
  apilar(&pila, 40);

  mostrar(&pila);


  return 0;
}