/*
 Resumen
  Se recorre cada elemento del vector.

  Sea i>=1  
  Se comprueba si cada elemento esta ordenado, para saber si esta ordenado debe cumplir con que: sea un elemento i tal que i+1>=i. En el algoritmo por insercción se verifica al revez, es decir, sea un elemento i tal que i-1=<i.

  En el caso que no se de el orden correcto del arreglo: i-1>i. Se debe intercambiar y repetir hasta que llegue a la primera posición. Esta verificación se terminara si el elemento a su izquierda es menor (esta ordenado).

  Si el elemento actual esta en i=1 y anterior esta ordenado, la verificación termina y no se decrementa i. El porque es sencillo ya que a la izquierda de 0, es decir, 0-1 se encuentra -1 y esa posición no existe haciendo que el problema tenga un error.

*/

#include <stdio.h>

int main(){
	int datos[5]  = {4,5,3,8,1};
	int n = 5;
	for(int k=1 ; k<n ; k++){

		int posicionActual = k;
		int copiaActual = datos[k];
		int ordenado = 0;

		while (posicionActual>0 && ordenado==0){
			if(datos[posicionActual-1] > copiaActual){
				datos[posicionActual] = datos[posicionActual-1];
				posicionActual--;
			}
			else ordenado = 1;
		}

		datos[posicionActual] = copiaActual;
	}
	return 0;
}