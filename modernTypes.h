#ifndef modernTypes
#define modernTypes

// unsigned int
typedef unsigned short int uint16;
typedef unsigned long int uint32;

// signed int
typedef signed short int int16;
typedef signed long int int32;

// 64 bits double
typedef double int64;

   

// functions

void swapInteger(int *x, int *y){
  int *temp = x;
  x = y;
  y = temp;
}

#endif