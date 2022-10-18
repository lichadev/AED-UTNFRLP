#include <iostream>

int const TAM = 4;

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

int findMin(int lista[TAM], int TAM, int i){
  int minValue; 
  for(i; i<TAM; i++){  
    if(lista[i] < lista[i+1]){
      minValue = lista[i];
    }
  }
  std::cout << "MinVal Nr. []:" << minValue <<  std::endl;
  return minValue;
}

int main (){
  int lista[TAM];
  int positionMin;

  for(int i=0; i<TAM; i++){
    std::cout << "Input Nr. [" << i << "]:" << std::endl;
    std::cin >> lista[i];
  }
      
  for(int i=0; i<TAM-1; i++){
    positionMin = findMin(lista, TAM, i);  
    swap(lista[i], lista[positionMin]);
  }

  for(int i=0; i<TAM; i++)
    std::cout << "Output Nr. [" << i << "]:" << lista[i] << std::endl;
}