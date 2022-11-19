#include <stdio.h>|
 
void swap (int *x, int *y);

int main(){
  int arreglo[5] = {5, 4, 3, 2, 1};
  int numeroPasadas = 5;

  /*Tomas una posicion fija y de ahi iteras comparando con esa posición fija*/
  /*Minimo n-1 pasadas*/

  for(int i = 0; i < numeroPasadas-1; i++){
    for(int j = i; j < numeroPasadas; j++){
      if(arreglo[i] > arreglo[j]){
        swap(&arreglo[i], &arreglo[j]);
      }
    }
  }

  for(int i=0; i<5; i++){
    printf("%i", arreglo[i]);
  }

  return 0;
}
 
void swap (int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}