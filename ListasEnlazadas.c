#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int valores[100];
  int posTope;
} Pila;

Pila apilar(Pila pila, int numero)
{
  if(pila.posTope < 100)
  {
    pila.valores[pila.posTope] = numero;
    pila.posTope++;

  } else {
    printf("Esta llena la pila amiguito :).");
  }

  return pila;
}

void mostrar (Pila pila) {
  int i=0;
  while(i<pila.posTope){
    i++;
    
  }
}