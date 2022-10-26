#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int const TamanoPila = 5;

void InicializarPila(P_Pila p)
{
  int *aux;
  aux = (int *)malloc(TamanoPila * sizeof(int)); // aux[50]
  p->valores = aux; // pila->valores = aux[50];
  p->postope = 0; //pila->postope = 0;
}

void Liberar(P_Pila p){
  free(p);
}

void Apilar(P_Pila p, int dato)
{
  //valores[50] se referencian como si fuese que cada uno de estos indices es un stacked node, siendo asi que se utiliza "postope" para referenciar al indice de la pila y iterar sobre este para apilar en la misma
  int index = (*p).postope;
  (*p).valores[index] = dato; 
  (*p).postope++; // es el equivalente a puntero siguiente
}

int Desapilar(P_Pila p)
{
  int z = p->valores[p->postope - 1];
  p->postope--;
  return z;
}

int Tope(P_Pila p)
{
  return p->valores[p->postope - 1];
}

int PilaVacia(P_Pila p)
{
  return (p->postope == 0);
}

void Leer(P_Pila p)
{
  int aux = 0;
  if (p->postope < TamanoPila)
  {
    printf("Ingrese un valor entero: ");
    fflush(stdin);
    scanf("%d", &aux);
    Apilar(p, aux);
  }
  else
    printf("Error: la pila esta llena");
}

void Mostrar(P_Pila p)
{
  int i;
  printf("\nBase .............................................. Tope\n\n");
  for (i = 0; i < p->postope; i++)
    printf("| %d ", p->valores[i]);
  printf("\n\nBase .............................................. Tope\n\n");
}