#include <iostream>

// Implementacion del metodo trackeando si ya esta ordenado para poder optimizarlo y avisando cuando se trackeo esta optimizacion atraves de pantalla

int const TAM = 4;

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

int main (){
  int lista[TAM];

  for(int i=0; i<TAM; i++){
    std::cout << "Input Nr. [" << i << "]:" << std::endl;
    std::cin >> lista[i];
  }

  for(int i=1; i<TAM; i++){
    bool desordenado = false;
      for(int j=0; j<TAM-i; j++)
        if (lista[j] > lista[j+1]){
          desordenado = true;
          swap(lista[j], lista[j+1]);
        }
    if (!desordenado){
      std::cout << "Se pudo optimizar el algoritmo exitosamente!." << std::endl;
      break;
    }
  }
    
    
  for(int i=0; i<TAM; i++)
    std::cout << "Output Nr. [" << i << "]:" << lista[i] << std::endl;
}