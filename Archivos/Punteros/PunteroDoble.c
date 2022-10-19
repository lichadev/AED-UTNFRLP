#include "stdio.h"
#include "stdlib.h"
#include "../../modernTypes.h"

void FormatPuntero(uint16 *a)
{
  for(int i=0; i<10; i++){
    a[i]=i+1;
  }
}

uint16* CrearLista(uint16 *lista, uint16 TAM){
  lista = malloc(TAM*sizeof(uint16));
  for(uint16 i=0; i<TAM; i++)
    lista[i]=i+1;
  return lista;
}

void CrearListaDoblePuntero(uint16 **lista, uint16 TAM){
  // Creo una lista ya que hago que apunte a algo
  *lista = malloc(TAM*sizeof(uint16)); // reservo memoria
  for(uint16 i=0; i<10; i++)
    (*lista)[i]=i+1; //cargo usando lo que apunta lista = referencia pasada por parametro, es decir, a la lista original

}


int main(){

  // Creo y
  uint16 *arreglo = malloc(10*sizeof(uint16)); // arreglo de 10 elementos reservado
  FormatPuntero(arreglo);
  
  // Se pasa un puntero por ref
  uint16 *lista = CrearLista(lista, 10);


  // al pedir doble puntero por parametro se pasa referencia
  uint16 *listaDoble = 0;
  CrearListaDoblePuntero(&listaDoble, 10);


  for(int i=0; i<10; i++){
    printf("%i\n", listaDoble[i]);
  }





}

