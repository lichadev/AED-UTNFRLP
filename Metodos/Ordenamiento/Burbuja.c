#include <stdio.h>

void swap (int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main(){
  int arreglos[5] = {5, 4, 3, 2, 1};
  int n = 5;


  /*Maximo n-1 pasadas*/
  /*
    Se ordenaran pares adyacentes, obteniendo que a medida que se va 
    ordenando los numeros más grandes se van decantando hacia el final.

    El algoritmo optimazado del burbuja:
    Tiene una bandera que le permite saber si se realizo algún intercambio
    En caso que no se realizaron intercambios significa que ya esta ordenado.
    Por ende ya no se necesita seguir loopeando. Y asi se reduce el tiempo de complejidad en aquellos casos que tienen bajo nivel de desorden.
  */

  for(int i=0; i<n-1; ++i){
    int swapped = 0;

    for(int j=0; j<n-i-1; ++j){

      if(arreglos[j] > arreglos[j+1]){
        swap(&arreglos[j], &arreglos[j+1]);
        swapped = 1;
      }

    }

    if (swapped == 0){
      break;
    }
  }

  for(int i=0; i<5; i++){
    printf("%i", arreglos[i]);
  }

  return 0;
}
